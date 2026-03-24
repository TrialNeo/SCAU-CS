// Created by Github@TrialNeo(shenpanpro@gmail.com) 
// Created Time 2026/2/1.
/*
* Description
由键盘输入5个整数，逐个判断它们能否被27整除，能的输出“YES”，不能的输出“NO”（注意，输出时，一个判断结果占一行，5个数的判断共占5行）。
输入格式 用空格分隔
输出格式
一行一个判断
输入样例
8  27  17577  325  54
 *
 */


#include <stdio.h>

int main() {
    int num = 0;
    for (int i =0;i<5;i++) {
        scanf("%d", &num);
        puts(num % 27 ? "NO": "YES" );
    }
    return 0;
}
