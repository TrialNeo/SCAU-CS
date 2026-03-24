// Created by Github@TrialNeo(shenpanpro@gmail.com) 
// Created Time 2026/3/12.

/*
Description
    从键盘输入一个3位数的正整数，要求先后输出该数的百位数字与个位数字，各占一行
输入格式
    一个三位整数
输出格式
    输出该数的百位数字与个位数字
输入样例
    123
输出样例
    1
    3
*/
#include  <stdio.h>

int main(int argc, char *argv[]) {
    int number = 0;
    scanf("%d", &number);
    printf("%d\n", number / 100);
    printf("%d\n", (number % 100)%10);
}
