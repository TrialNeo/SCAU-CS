// Created by Github@TrialNeo(shenpanpro@gmail.com)
// Created Time 2026/3/21 12:08.


#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../database/belong.h"
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
    printf("+===============================================+\n");
    printf("+ 您当前正在录入物品\t\t\t\t+\n");
    printf("+-----------------------------------------------+\n");
    printf("- 请输入要录入的物品名称:");
    scanf(" %s", data.name);
    printf("- 请输入要录入的物品备注或描述:");
    scanf(" %s", data.desc);
    data.create_stamp = time(NULL);
    unsigned width = strlen(data.name); // 配置一下表格的宽度
    table_name_max_width = width > table_name_max_width ? width : table_name_max_width;
    width = strlen(data.desc); // 配置一下表格的宽度
    table_desc_max_width = width > table_desc_max_width ? width : table_desc_max_width;

    if (interact_comfirm()) {
        belong_add(data);
        system_cls();
        printf("+ 物品:[%s] 录入成功\n", data.name);
    } else {
        printf("- 录入操作已取消\n");
    }
    system_pause();
}

void interact_modify() {}


// 删除对应id的物品信息
void interact_del() {
    system_cls();
    printf("+ 请输入要删除的物品ID:");
    unsigned id = 0;
    scanf(" %d", &id);


    if (interact_comfirm()) {
        system_cls();
        printf("* 删除成功\n");
    } else {
        printf("- 删除操作已取消\n");
    }

    system_pause();
}


void __interact_query(const belong data) {
    printf("%u\t%-*s\t%-*s\t%ld\n", data.id, table_name_max_width, data.name, table_desc_max_width, data.desc,
           data.create_stamp);
}

void interact_query() {
    system_cls();
    printf("+ id\t\t%-*s \t%-*s\t%s\n", table_name_max_width, "物品名称", table_desc_max_width, "描述", "添加时间");
    belong_print(__interact_query);
    system_pause();
}


void interact_fuzzy_search() {
    system_cls();
    system_tip("请输入您要查找的方式");
    system_tip("1.通过物品ID查找\t2.通过物品名称查找");
    system_tip("0.返回上一步");
    system_ask("请输入功能编号");
    unsigned op = 0;
    do {
        scanf("%u", &op);

    } while (op != 0 && op != 1 && op != 2);
    switch (op) {
        case 0:
            system_cls();
            return;
        case 1:
            break;
        case 2:
            system_cls();
            system_ask("请输入你要查找的物品大致名称");
            char str[255] = {0};
            scanf(" %s", str);
            belong_fuzzy_search(str, __interact_query);
            break;
    }
    system_pause();
}

// 实现用户交互
void interact() {
    int op = 0;
    while (true) {
        system_cls();
        menu_welcome();
        printf("请输入您的功能编号:");
        scanf("%d", &op);
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
                interact_del();
                break;
            case 5:
                break;
            case 6:
                break;
            case 0:
                belong_save();
                return;
            default:
                break;
        }
    }
}
