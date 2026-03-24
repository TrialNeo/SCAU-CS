// Created by Github@TrialNeo(shenpanpro@gmail.com) 
// Created Time 2026/2/1.

#include <stdio.h>
/*
Description
由键盘输入三个整数a、b、c，按从小到大的顺序输出这三个数。
输入格式
三个数由逗句分隔
输入样例
65,45,90
输出样例
45,65,90
*/
int main() {
    int a, b, c, temp;
    scanf("%d,%d,%d", &a, &b, &c);
    if (a > b) {
        temp = b;
        b = a;
        a = temp;
    }
    if (a>c) {
        temp = c;
        c = a;
        a = temp;
    }
    if (b>c) {
        temp = b;
        b = c;
        c = temp;
    }
    printf("%d,%d,%d", a, b, c);

}
