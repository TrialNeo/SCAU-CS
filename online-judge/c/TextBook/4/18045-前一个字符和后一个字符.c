// Created by Github@TrialNeo(shenpanpro@gmail.com) 
// Created Time 2026/1/1.
#include <stdio.h>

char checkNumCh(char ch) {
    return ch >= '0' && ch <= '9' ? 1 : 0;
}

int main() {
    char c = getchar();
    if (checkNumCh(c)) {
        if (checkNumCh(c - 1)) {
            putchar(c - 1);
            putchar(' ');
        } else {
            printf("first ");
        }
        if (checkNumCh(c + 1)) {
            putchar(c + 1);
        } else {
            puts("last");
        }
    } else {
        // 压根不是数字字符
        printf("error");
    }
}
