// Created by Github@TrialNeo(shenpanpro@gmail.com) 
// Created Time 2026/1/1.
// 由键盘输入10个浮点数，任取其中两数相减求绝对值，求其中最小值（保留两位小数)
// 1.1 2.2 3.3 4.4 5.5 6.6 7.7 8.8 9.9 9

#include <math.h>
#include  <stdio.h>

//
// void c1011() {
//     //先扫描进来,然后无脑去遍历就行了，用这么多脑子干什么hh
//     double nums[10];
//     for (int i = 0; i < 10; i++) {
//         scanf("%lf", nums + i);
//     }
//     double min = fabs(nums[0] - nums[1]), tmp = 0;
//     for (int i = 0; i < 10; i++) {
//         for (int j = i+1; j < 10; j++) {
//             tmp = fabs(nums[i] - nums[j]);
//             if (min > tmp) {
//                 min = tmp;
//             }
//         }
//     }
//     printf("%.2f", min);
// }