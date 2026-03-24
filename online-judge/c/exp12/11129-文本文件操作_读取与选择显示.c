// Created by Github@TrialNeo(shenpanpro@gmail.com) 
// Created Time 2026/3/1.

// Description
//         在当前目录中存在文件名为"case1.in"的文本文件，现要求打开该文件，读出里面的所有字符，只将其中的数字字符按先后顺序显示在屏幕上。
//         （如case1.in内容如下）
//         13 cats and 22 bikes
//         （在屏幕上输出结果如下）
//         1322

#include <stdio.h>

int main(int argc, char *argv[]) {
    FILE *fp = fopen("case1.in", "r");
    if (fp == NULL) {
        return 1;
    }
    char ch = 0;
    while ((ch = fgetc(fp)) != EOF) {
        if ('0' <= ch && ch <= '9') {
            putchar(ch);
        }
    }
    fclose(fp);
}
