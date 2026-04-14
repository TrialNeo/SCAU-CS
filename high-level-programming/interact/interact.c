// Created by Github@TrialNeo(shenpanpro@gmail.com)
// Created Time 2026/3/21 12:08.


#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../admin/users.h"
#include "../database/belong.h"
#include "../database/category.h"
#include "../system/system.h"
#include "menu.h"
#include "string.h"
unsigned table_name_max_width = 10;
unsigned table_desc_max_width = 10;

// 二次确认，防止误操作
bool interact_comfirm() {
    char op;
    do {
        printf("请确认[Y/N]:");
        scanf(" %c", &op);
    } while (op != 'y' && op != 'Y' && op != 'n' && op != 'N');
    return op == 'y' || op == 'Y';
}


// 录入新信息
void interact_enter() {
    system_cls();
    belong data;
    system_fun_start();
    printf("+ 您当前正在录入物品\t\t\t\t+\n");
    system_split();
    system_tip("请输入要录入的物品名称:");
    scanf(" %s", data.name);
    system_tip("请输入要录入的物品备注或描述:");
    scanf(" %s", data.desc);
    system_tip("请为其选择分类");
    scanf(" %d", &data.category);
    data.create_stamp = time(NULL);
    unsigned width = strlen(data.name); // 配置一下表格的宽度
    table_name_max_width = width > table_name_max_width ? width : table_name_max_width;
    width = strlen(data.desc); // 配置一下表格的宽度
    table_desc_max_width = width > table_desc_max_width ? width : table_desc_max_width;
    if (interact_comfirm()) {
        system_cls();
        if (belong_add(data)) {
            printf("+ 物品:[%s] 录入成功\n", data.name);
        } else {
            system_tip("录入失败");
        }

    } else {
        printf("- 录入操作已取消\n");
    }
    system_pause();
}

void interact_modify() {
    system_cls();
    system_fun_start();
    system_tip("输入\"0\"可返回上一步");
    system_split();
    system_ask("请输入需要修改的物品ID");

    unsigned id = 0;
    scanf(" %u", &id);
    if (id == 0) {
        return;
    }

    system_cls();
    char name[255] = {0}, desc[255] = {0};
    system_ask("请输入新的名称，若不修改可空");
    scanf("%s", name);
    system_split();
    system_ask("请输入新的备注，若不修改可空");
    scanf("%s", desc);

    if (belong_modify(id, strlen(name) ? name : NULL, strlen(desc) ? desc : NULL)) {
        system_tip("修改成功");
    } else {
        system_tip("修改失败，请检查ID是否正确");
    }
    system_pause();
}

// 删除对应id的物品信息
void interact_del() {
    system_cls();
    system_fun_start();
    system_tip("1.通过ID删除\t2.通过完整名称删除");
    system_split();
    system_ask("请选择您的操作序号");
    unsigned id = 0;
    char str[255] = {0};
    switch (system_get_op_id(0, 2)) {
        case 1:
            system_ask("请输入要删除的物品ID");
            scanf(" %d", &id);
            break;
        case 2:
            system_ask("请输入要删除的物品名称");
            scanf(" %s", str);
            break;
        default:
            break;
    }
    if (interact_comfirm()) {
        system_cls();
        belong b = {0};
        if (belong_del(id, str, &b)) {
            char s[255] = {0};
            sprintf(s, "物品[%s]已被删除", b.name);
            system_tip(s);
        } else {
            system_tip("删除失败!请检查输入信息是否正确~");
        }
    } else {
        system_tip("删除操作已取消");
    }
    system_pause();
}


void __interact_query(const belong data) {
    // 时间戳转为时间
    time_t timestamp = data.create_stamp;
    struct tm *tm_info;
    tm_info = localtime(&timestamp);
    tm_info->tm_year += 1900; // 这个不知道为什么要这么设计，大概是和千年虫差不多
    tm_info->tm_mon++;

    printf("%u\t%-*s\t%-*s\t%4d-%02d-%02d %02d:%02d:%02d\t%u\n", data.id, table_name_max_width * 2, data.name,
           table_desc_max_width * 2, data.desc, tm_info->tm_year, tm_info->tm_mon, tm_info->tm_mday, tm_info->tm_hour,
           tm_info->tm_min, tm_info->tm_sec,
           data.category); // 最后加上分类 ID
}

void interact_query() {
    system_cls();
    system_fun_start();
    printf("+ id\t%-*s\t\t%-*s\t\t%s\t\t%s\n", table_name_max_width, "物品名称", table_desc_max_width, "描述",
           "添加时间", "分类");
    belong_print(__interact_query);
    system_pause();
}

void interact_fuzzy_search() {
    system_cls();
    system_fun_start();
    system_tip("请输入您要查找的方式");
    system_split();
    system_tip("1.通过物品ID查找\t2.通过物品名称查找");
    system_split();
    system_tip("3.通过物品分类查找\t");
    system_split();
    system_tip("0.返回上一步");
    system_split();
    system_ask("请输入功能编号");
    unsigned op = 0;
    op = system_get_op_id(0, 3);
    switch (op) {
        case 0:
            system_cls();
            return;
        case 1:
            system_cls();
            system_fun_start();
            system_ask("请输入你要查找的物品id");
            char id = 0;
            scanf(" %d", &id);
            system_cls();
            system_fun_start();
            if (!belong_id_search(id, __interact_query)) {
                system_tip("抱歉没有查询到任何物品信息，请检查id是否正确");
                return;
            }

            break;
        case 2:
            system_cls();
            system_fun_start();
            system_ask("请输入你要查找的物品大致名称");
            char str[255] = {0};
            scanf(" %s", str);
            system_cls();
            system_fun_start();
            if (!belong_fuzzy_search(str, __interact_query)) {
                system_tip("抱歉没有查询到任何物品，请检查物品信息是否正确");
            }
            break;
        case 3:
            system_cls();
            system_fun_start();
            system_ask("请输入你要查找的物品的分类ID");
            scanf(" %d", &id);
            system_cls();
            system_fun_start();
            if (!belong_category_search(id, __interact_query)) {
                system_tip("抱歉没有查询到任何物品，请检查物品信息是否正确");
            }
    }
    system_pause();
}

// 管理员注册普通用户
void interact_reg() {
    // 这里做一个鉴权，如果不是管理员直接返回就行了
    if (global_user->role != ROLE_ADMIN) {
        return;
    }
    system_cls();
    system_fun_start();
    user new_user = malloc(sizeof(user));
    system_ask("请输入要注册的账号");
    scanf(" %s", new_user->username);
    system_split();
    system_ask("请输入要注册的密码");
    scanf(" %s", new_user->password);
    char error[255] = {0};
    if (user_regist(global_user, new_user, error)) {
        system_cls();
        system_fun_start();
        system_tip("注册成功!");
    }


    system_pause();
}

void __interact_query_category(const category data) { printf("%-8d\t\t\t%-s\n", data.id, data.name); }
//
void interact_query_categories() {
    system_cls();
    system_fun_start();
    if (!categories_print(__interact_query_category)) {
        system_tip("暂时还没有分类哦~去添加一个吧");
    }
    system_pause();
}

// 添加分类
void interact_add_category() {
    system_cls();
    system_fun_start();
    system_ask("请输入要添加的分类名称");
    category data = {0};
    scanf(" %s", data.name);
    if (interact_comfirm()) {
        if (category_add(data)) {
            system_tip("分类添加成功");
        } else {
            system_tip("添加失败");
        }
    }
    system_pause();
}

void interact_del_category() {
    system_cls();
    system_fun_start();
    system_split();
    system_ask("请输入要删除的分类ID");
    unsigned id = 0;
    scanf("%u", &id);
    if (interact_comfirm()) {
        if (category_del(id)) {
            system_tip("删除成功");
        } else {
            system_tip("删除失败，请检查id");
        }
    }

    system_pause();
}


// 查找将要逾期或者已经逾期的物品
void interact_search_date_belong() {
    system_cls();
    system_fun_start();
    system_tip("请输入截止时间，格式如2026-03-30 20:48:00");
    struct tm t = {0};
    scanf("%d-%d-%d %d:%d:%d", &t.tm_year, &t.tm_mon, &t.tm_mday, &t.tm_hour, &t.tm_min, &t.tm_sec);
    t.tm_year -= 1900;
    t.tm_mon--;
    t.tm_isdst = -1; // 夏令时问题
    time_t time = mktime(&t);
    if (time == -1) {
        system_cls();
        system_tip("请检查日期格式是否正确");
        system_pause();
        return;
    }


    printf("+ id\t%-*s\t\t%-*s\t\t%s\n", table_name_max_width, "物品名称", table_desc_max_width, "描述", "添加时间");
    belong_print_date(time, __interact_query);
    system_pause();
}
// 实现用户交互
void interact() {
    int op = 0;
    while (true) {
        system_cls();
        menu_welcome();
        printf("请输入您的功能编号:");
        op = system_get_op_id(0, 10);
        switch (op) {
            case 1:
                interact_query();
                break;
            case 2:
                interact_fuzzy_search();
                break;
            case 3:
                interact_enter();
                break;
            case 4:
                interact_modify();
                break;
            case 5:
                interact_del();
                break;
            case 6:
                interact_query_categories();
                break;
            case 7:
                interact_add_category();
                break;
            case 8:
                interact_del();
                break;
            case 9:
                interact_search_date_belong();
                break;
            case 10:
                interact_reg();
                break;
            case 0:
                belong_save();
                categories_save();
                return;
            default:
                break;
        }
    }
}
