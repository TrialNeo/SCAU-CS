// Created by Github@TrialNeo(shenpanpro@gmail.com) 
// Created Time 2026/3/5.


// 描述
//     输入包含加速度（浮点数）与时间（整数，秒），两个数间使用空格分隔。
// 输入格式
//     移动的距离，显示两位小数
// 输出格式
//     5.1 10
// 输入样例
//     255.00

#include <stdio.h>
int main(int argc, char *argv[]) {
    double a = 0;
    int t = 0;
    scanf("%lf%d",&a,&t);
    printf("%.2lf",0.5*a*t*t);

}
