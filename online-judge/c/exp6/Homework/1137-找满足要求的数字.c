// Created by Github@TrialNeo(shenpanpro@gmail.com) 
// Created Time 2026/3/1.


// Description
//     输出1到9999中能被7整除，而且至少有一位数字是5的所有数字
// 输出格式
//     一行一个
// 输出样例
//     35
//     56
//     105
//     154
//     ......
#include <stdio.h>

int main(int argc, char *argv[]) {
    // for (int number = 1; number < 10000; number++) {
    //     if (!(number % 7)) {
    //         //150  15...0
    //         //15   1....5
    //         //1    0....1
    //         //观察里面有没有5，就是一直取模呗
    //         int q = 0;
    //         while (1) {
    //             q = number / 10;
    //             if (!q && number % 10 == 5) {
    //                 printf("%d", number);
    //                 break;
    //             }
    //         }
    //     }
    // }
    //大哥爬楼梯
    //
    // for (int number = 1; number < 10000; number++) {
    //     if (number % 7) {
    //         continue;
    //     }
    //     int q = number;
    //     do {
    //         if (q % 10 == 5) {
    //             printf("%d\n", number);
    //             break;
    //         }
    //     }while (q/=10);
    // }
    //还能超进化调整步长 直接+=7
    for (int number = 7; number < 10000; number+=7) {
        int q = number;
        do {
            if (q % 10 == 5) {
                printf("%d\n", number);
                break;
            }
        }while (q/=10);
    }
}
