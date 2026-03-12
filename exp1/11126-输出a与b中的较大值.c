// Created by Github@TrialNeo(shenpanpro@gmail.com) 
// Created Time 2026/3/12.


// Description
//     下面程序实现由键盘输入两个整数a和b，判断并输出a与b中较大值。请在计算机上执行并验证该程序的正确性，之后提交到在线评判系统。
// 输入格式
//     两个整数，以空格分隔
// 输出格式
//     输出较大的那个数
// 输入样例
//     5 7
// 输出样例
//     7

#include <stdio.h>

int main(int argc, char *argv[]) {
    int x = 0,y = 0;
    scanf("%d%d", &x, &y);
    printf("%d", x > y ? x : y);
}
