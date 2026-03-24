// Created by Github@TrialNeo(shenpanpro@gmail.com)
// Created Time 2026/3/21 12:05.


#include <stdio.h>
#include <stdlib.h>

#include "../admin/login.h"
#include "../database/belong.h"

// 清屏
void system_cls() { system("cls"); }

//检测登录，初始化密码相关
void system_user_init() {
    system_cls();
    if (!password_check_set()) {
        printf("因为您是第一次使用，请先设置密码：");
        char password[255] = {0} ;
        scanf(" %s",password);
        puts(password);
        password_set(password);
    }else {
        printf("请输入密码登录：");
        char password[255] = {0};
        scanf(" %s",password);
        while (password_login(password)!= SUCCESS) {
            printf("密码错误，请重新输入:");
            scanf(" %s",password);
        }
        printf("登录成功\n");

    }
}


//系统初始化，用于读取配置，数据相关
void system_init(){
    system_user_init(); //加载用户配置
    belong_init(); //加载个人物品的配置
}


void system_exit() {
    // 持久化存储
    belong_save();

}