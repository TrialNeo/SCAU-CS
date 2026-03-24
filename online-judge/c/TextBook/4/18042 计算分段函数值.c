// Created by Github@TrialNeo(shenpanpro@gmail.com) 
// Created Time 2026/1/15.

// Description
// 根据如下数学公式，编写程序输入x，计算并输出y的值，保留两位小数
#include <stdio.h>

int c18042() {
    double x = 0, y = 0;
    scanf("%lf", &x);
    if (x < 1) {
        y = x;
    } else if (x < 10) {
        y = 2 * x - 1;
    } else {
        y = 3 * x - 11;
    }
    printf("%.2f", y);
    return 0;
}
