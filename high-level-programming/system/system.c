// Created by Github@TrialNeo(shenpanpro@gmail.com)
// Created Time 2026/3/21 12:05.


#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../admin/login.h"
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
void system_split() { puts("+--------------------------------------------"); }

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
    if (!password_check_set()) {
        printf("因为您是第一次使用，请先设置密码：");
        char password[255] = {0};
        scanf(" %s", password);
        puts(password);
        password_set(password);
    } else {
        printf("请输入密码登录：");
        char password[255] = {0};
        scanf(" %s", password);
        while (password_login(password) != SUCCESS) {
            printf("密码错误，请重新输入:");
            scanf(" %s", password);
        }
        printf("登录成功\n");
    }
}


// 系统初始化，用于读取配置，数据相关
void system_init() {
    system_user_init(); // 加载用户配置
    belong_init(); // 加载个人物品的配置
}


void system_exit() {
    // 持久化存储
    belong_save();
}
