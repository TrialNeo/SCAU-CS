// Created by Github@TrialNeo(shenpanpro@gmail.com) 
// Created Time 2026/2/24.

//从银行贷款金额为d，准备每月还款额为p，月利率为r。请编写程序输入这三个数值，计算并输出多少个月能够还清贷款，输出时保留1位小数。
//计算公式如下：见attachment/18073分期还款.png
#include <math.h>
#include <stdio.h>

int main() {
    // 这个其实是计算公式
    float d, p, r;
    scanf(" %f%f%f", &d, &p, &r);
    float m = log10(p / (p - d * r)) / log10(1 + r);
    printf("%.1f", m);
}
