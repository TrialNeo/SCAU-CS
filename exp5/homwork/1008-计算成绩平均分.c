// Created by Github@TrialNeo(shenpanpro@gmail.com) 
// Created Time 2026/2/10.
/*
*Description
输入10个学生成绩（浮点数），要求计算并输出平均分（保留两位小数位）
*/

#include <stdio.h>

int main(int argc, char *argv[]) {
    float sum, temp_score;
    for (int i = 0; i < 10; i++) {
        scanf("%f", &temp_score);
        sum += temp_score;
    }
    sum /= 10;
    printf("%.2f", sum);
}
