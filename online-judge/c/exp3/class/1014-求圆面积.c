// Created by Github@TrialNeo(shenpanpro@gmail.com) 
// Created Time 2026/3/12.


/*
Description
    由键盘输入圆半径r，请计算并输出该圆的面积。（注：π取3.14159，结果采用浮点数表示，且要求仅显示两位小数位）

输入格式
    一个实数
输出格式
    输出以该实数为半径的圆面积
输入样例
    65.2
输出样例
    13355.02
*/
#define PI  3.14159
#include <stdio.h>

int main(int argc, char *argv[]) {
    float r = 0;
    scanf("%f", &r);
    printf("%.2f",PI * r * r);
}

