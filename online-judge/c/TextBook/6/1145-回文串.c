// Created by Github@TrialNeo(shenpanpro@gmail.com) 
// Created Time 2026/2/27.
// Description
//     读入一行字符串（不多于80个字符，以回车结束），判断该字符串是否为回文串（即从左向右拼写与从
//
// 右向左拼写是一样的），是则输出Y，不是则输出N。
// 输入格式
//     一行字符串
// 输出格式
//     是则输出Y，不是则输出N
// 输入样例
//     abba
// 输出样例
//     Y
// 提示
//     或
// input:
// abcba
//
// output:
// Y
//
// 或
// input:
// abc
//
// output:
// N

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char str[255];
    gets(str);
    int len = strlen(str);
    for (int i = 0; i < len / 2; ++i) {
        if (str[i] != str[len - 1 - i]) { //这个-1是换行符
            printf("N");
            return 0;
        }
    }
    printf("Y");
}
