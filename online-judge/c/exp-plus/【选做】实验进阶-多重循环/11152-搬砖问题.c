// Created by Github@TrialNeo(shenpanpro@gmail.com) 
// Created Time 2026/2/27.
// Description
//     一个大男人一次可以搬3块砖，一个大女人一次可以搬2块砖，两个小孩一次可以搬1块砖，现由键盘输入总人数n以及总砖数m，问有多少种不同的分配方案，
// 正好n个人一次搬完所有的m块砖(无闲人且每人满负荷)，没有这样的方案则输出no
// 输入格式
//     n及m，以空格分隔
// 输出格式
//     方案数或no
// 输入样例
//     45 45
// 输出样例
//     4

#include <stdio.h>



int main(int argc, char *argv[]) {
    int m= 0,n = 0,count =0;
    scanf("%d%d", &m,&n);
    for (int x = 0; x < n; ++x) {
        for (int y = 0; y < n; ++y) {
            if (5*x+3*y == 2*m-n && n-x-y >= 0) {
                count++;
            }
        }
    }
    if (count == 0) {
        puts("no");
        return 0;
    }
    printf("%d", count);
}
