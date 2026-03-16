// Created by Github@TrialNeo(shenpanpro@gmail.com) 
// Created Time 2026/3/14.


/*
由键盘输入一个点的坐标, 要求编程判断这个点是否在单位圆(圆心在坐标0,0)上，点在圆上输出Y, 不在圆上输出N。
使用小数点后3位精度进行判断。
输入样例
0.707,0.707
输出样例
Y
提示
本题区域分为圆外、圆上、圆内，点在圆上指该点到圆心的距离等于半径（由于浮点数输入和计算存在误差，因而当判断相等的两个数相差小于给定误差，即判断为相等）
*/


#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
#define epsilon 1e-3


int main(int argc, char *argv[]) {
    float x, y = 0;
    scanf("%f,%f", &x, &y);
    if (fabs(x * x + y * y - 1.) <= epsilon) {
        cout << "Y";
    } else {
        cout << "N";
    }
}
