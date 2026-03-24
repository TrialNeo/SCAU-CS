// Created by Github@TrialNeo(shenpanpro@gmail.com) 
// Created Time 2026/3/14.

#include <iostream>
using namespace std;
/*
Description
    由键盘输入一行字符（以回车作为结束），编程实现将该行字符中‘A’字符除去，其它字符及其顺序不变，处理后输出结果
输入格式
    一行字符
输出格式
    处理后的一行字符

输入样例
    I AamA a Astudent.

输出样例
    I am a student.

提示
*/


#include "stdio.h"
#include "string.h"

int main() {
    char s1[500], s2[500];
    int i, j;
    gets(s1);
    for (i = 0; i < strlen(s1); i++) {
        if (s1[i] != 'A') {
            s2[j++] = s1[i];
        }
    }
    s2[j] = 0;
    printf("%s\n", s2);
}
