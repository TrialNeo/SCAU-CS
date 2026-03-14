// Created by Github@TrialNeo(shenpanpro@gmail.com) 
// Created Time 2026/2/10.

#include <stdio.h>


int main(int argc, char *argv[]) {
    //由键盘输入一个int类型的正整数，计算输出构成该数的各位数字之和。
    int i = 0, sum = 0;
    scanf("%d", &i);
    while (i) {
        sum += i % 10;
        i /= 10;
    }
    printf("%d", sum);
}
