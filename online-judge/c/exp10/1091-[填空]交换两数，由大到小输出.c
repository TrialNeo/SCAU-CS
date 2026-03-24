// Created by Github@TrialNeo(shenpanpro@gmail.com) 
// Created Time 2026/2/26.

// Description
//     下面程序，交换两数，使两数由大到小输出，请填空
// 输入样例
//     1 2
// 输出样例
//     2 1

#include "stdio.h"

void swap(int *p1, int *p2) {
    int temp;
    temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int main() {
    int a, b;
    int *pa, *pb;
    scanf("%d%d", &a, &b);
    pa = &a;
    pb = &b;
    if (a < b) swap(pa, pb);
    printf("%d %d\n", a, b);
}
