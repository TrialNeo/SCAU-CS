// Created by Github@TrialNeo(shenpanpro@gmail.com) 
// Created Time 2026/2/1.

#include <stdio.h>
#include <math.h>
// Description
// 由键盘输入一个不多于9位的正整数，要求输出它是几位数。
int main() {
    unsigned int n = 0;
    scanf("%u", &n);
    printf("%d", (int) log10(n) + 1);
}
