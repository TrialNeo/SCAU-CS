#include <stdio.h>
// Created by Github@TrialNeo(shenpanpro@gmail.com)
// Created Time 2026/1/15.

// Description
// 输入底面半径r和高h，输出圆柱体的表面积，保留3位小数.(圆周率取3.14159)
int c1009() {
    const float pi =  3.14159;
    float r =0,h=0;
    scanf("%f%f", &r, &h);
    //上下两个圆，加上长为圆的周长，宽为圆柱的高的长方形
    printf("%.3f",2 * pi * r * r + 2 * pi * r * h);

    return 0;

}
