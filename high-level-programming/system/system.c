// Created by Github@TrialNeo(shenpanpro@gmail.com)
// Created Time 2026/3/21 12:05.


#include <ctype.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../admin/users.h"
#include "../database/belong.h"


// 清屏
void system_cls() { system("cls"); }

// 等待确认
void system_pause() { system("pause"); }


char *system_get_line(char *buf) {
    if (fgets(buf, sizeof(*buf), stdin)) {
        buf[strcspn(buf, "\n")] = '\0';
        return buf;
    }
    return NULL;
}

// 功能开始的提示线
void system_fun_start() { puts("+===============================================+"); }

// 分割线
void system_split() { puts("+-----------------------------------------------+"); }

// 询问
void system_ask(const char *msg) { printf("+ %s:", msg); }

// 系统提示
void system_tip(const char *msg) { printf("- %s\n", msg); }


// 获取操作id，左右都是闭区间
unsigned system_get_op_id(unsigned min, unsigned max) {
    unsigned op = 0;
    char ch = 0;
    while (true) {
        while ((ch = getchar()) != EOF && isspace(ch)) {
        }
        op = ch - '0';
        if (min <= op && op <= max) {
            return op;
        }
    }

    scanf(" %u", &op);
    return op;
}


// 检测登录，初始化密码相关
void system_user_init() {
    system_cls();
    system_fun_start();
    if (user_is_nil()) {
        char username[255], password[255];
        system_split();
        system_tip("由于您是初次使用本程序，请先创建一个管理员账号");
        system_ask("请输入账号");
        scanf(" %s", username);
        system_ask("请输入密码");
        scanf(" %s", password);
        user non_admin;
        non_admin->role = ROLE_ADMIN;
        char error[255] = {0};
        if (!user_regist(non_admin, username, password, error)) {
            system_tip(error);
        } else {
            system_tip("创建成功");
        }
        system_pause();
    } else {
        // 这里做一个登录
        global_user = malloc(sizeof(user));
        char error[255] = {0};
        system_tip("请先进行登录");
        system_split();
        system_ask("请输入账号");
        scanf(" %s", global_user->username);
        system_ask("请输入密码");
        scanf(" %s", global_user->password);
        if (!user_login(global_user, error)) {
            system_tip(error);
            system_pause();
            exit(0);
        } else {
            system_tip("登录成功");
            system_pause();
        }
    }
}


// 系统初始化，用于读取配置，数据相关
void system_init() {
    // 注册特定的文件目录
    mkdir("./data");
    mkdir("./data/users");
    mkdir("./data/belongs");
    system_user_init(); // 加载用户配置
    belong_init(); // 加载个人物品的配置
}


void system_exit() {
    // 持久化存储
    belong_save();
}
