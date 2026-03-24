// Created by Github@TrialNeo(shenpanpro@gmail.com) 
// Created Time 2026/3/5.

// Description
//     用指针方法解决，输入一个字符串，删除字符串中所有空格后，输出字符串
// 输入格式
//     一行字符，以换行回车结束，最多不超过80个字符
// 输出格式
//     删除所有空格后输出
// 输入样例
//     abc    456
// 输出样例
//     abc456

#include <stdio.h>

void removeSpace(char *s) {
    char *p = s, *res = s;
    do {
        if (*p != ' ') {
            *res++ = *p;
        }
    }while (*p++);
    *res = 0;
}

int main() {
    char s[81];
    gets(s);
    removeSpace(s);
    printf("%s", s);
    return 0;
}
