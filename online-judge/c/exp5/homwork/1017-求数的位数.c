// Created by Github@TrialNeo(shenpanpro@gmail.com) 
// Created Time 2026/2/10.
/*
Description
    由键盘输入一个不多于9位的正整数，要求输出它是几位数。
*/

#include <math.h>
#include <stdio.h>


int main(int argc, char *argv[]) {
    int n = 0, digit = 1;
    scanf("%d", &n);
    //一种思路可以做一个循环，一直取模就行了
    while (n /= 10) {
        digit++;
    }
    printf("%d", digit);
}

int main_2(int argc, char *argv[]) {
    int n = 0;
    scanf("%u", &n);
    //log10函数
    printf("%d", (unsigned)log10(n) + 1);
}
