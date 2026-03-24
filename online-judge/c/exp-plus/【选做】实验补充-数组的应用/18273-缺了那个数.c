// Created by Github@TrialNeo(shenpanpro@gmail.com) 
// Created Time 2026/3/1.
//
// Description
//     从1到n，n(2<=n<=10)个整数中拿走一个数，你能判断出中拿走了哪个数吗？
// 输入格式
//     第一行是一个整数n
// 第二行是n-1个数，由空格分开。
// 输出格式
//     输出缺少的那个数
// 输入样例
//     5
//     5 1 4 3
//
// 输出样例
//     2

#include <stdio.h>

//还是数学解法，就是一个完整的从1-n的等差数列 然后减掉 给的这个数组的和就能找到了。。
int main(int argc, char *argv[]) {
    int n = 0, sum = 0,
            temp = 0, sum_given = 0;
    scanf("%d", &n);
    sum = n * (1 + n) / 2;
    for (int i = 0; i < n-1; i++) {
        scanf("%d", &temp);
        sum_given+=temp;
    }
    printf("%d", sum - sum_given);
}
