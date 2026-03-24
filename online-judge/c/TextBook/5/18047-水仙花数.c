// Created by Github@TrialNeo(shenpanpro@gmail.com) 
// Created Time 2026/2/28.


// Description
//     输出所有的水仙花数。所谓水仙花数是一个3位的正整数，其各位数字的立方和等于这个数本身。
// 例如，153是水仙花数，因为1^3+5^3+3^3=153。 ^代表上标
// 输入格式
//     无
// 输出格式
//     一行一个，由小到大输出所有水仙花数
// 输入样例
//     无
// 输出样例
//     略
#include <stdio.h>

int main(int argc, char *argv[]) {
    // 因为是三位数:100-999
    for (int number = 100; number < 1000; number++) {
        int a = number / 100,
                b = (number % 100)/10,
                c = number % 10;
        if (a * a * a + b * b * b + c * c * c == number) {
            printf("%d\n", number);
        }
    }
}
