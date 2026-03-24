// Created by Github@TrialNeo(shenpanpro@gmail.com)
// Created Time 2026/2/28.


// Description
//     一个球从100米的高度自由落下，每次落地后弹起的原来高度的一半。计算并输出第n次落地时，
//     共经过了多少米，第n次弹起的高度是多少?结果显示3位小数。
// 输入格式
//     从键盘输入一个数n（n>0）
// 输出格式
//     输出两个数，分别为共经过的米数和第n次弹起的高度，以一个空格分隔
//
// 输入样例
//     1
// 输出样例
//     100.000 50.000
#include <math.h>
#include <stdio.h>


//问题的关键其实是第一次只有下落没有弹起来的。。可以假设第一次是第0次弹起来，然后最后减掉就行了。。
// int main(int argc, char *argv[]) {
//     int n = 0;
//     scanf("%d", &n);
//
//     double bound = 100, distance = 0;
//     for (int i = 0; i < n; i++) {
//         distance += 2 * bound;
//         bound /= 2;
//     }
//     distance -= 100;
//     printf("%.3f %.3f", distance, bound);
// }


//其实用纯数学解法比较好，如果考场有纸笔的话可以推一下。
//推导过程见README.md
int main(int argc, char *argv[]) {
    int n = 0;
    scanf("%d", &n);
    const double ratio = pow(0.5,n);
    printf("%.3f %.3f",300-400 * ratio,100 * ratio);
}
