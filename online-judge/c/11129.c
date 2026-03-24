// Created by Github@TrialNeo(shenpanpro@gmail.com) 
// Created Time 2026/1/1.
#include  <stdio.h>

int main() {
    FILE *fp;
    char ch;
    if ((fp = fopen("case1.in", "r")) != NULL) {
        return 0;
    }
    //真不懂Scau的系统写得一坨，没考虑过char在某些系统只能表示0~255吗，这样还怎么可能变成-1,真的是问题一大堆。。
    while ((ch = fgetc(fp)) != EOF) {
        if (ch >= '0' && ch <= '9') {
            putchar(ch);
        }
    }
}