// Created by Github@TrialNeo(shenpanpro@gmail.com) 
// Created Time 2026/1/15.
// Description
// 从键盘输入一个华氏温度值，要求按格式输出其对应的摄氏温度值，精确到小数点后两位。
// 数学公式描述为：
//
// 摄氏温度值等于9分之5  乘上  华氏温度值减去32的差 所得到的积。
#include <stdio.h>

int main() {
    float F = 0;
    scanf("%f", &F);
    printf("%.2f", (F - 32) * 5 / 9);
    return 0;
}
