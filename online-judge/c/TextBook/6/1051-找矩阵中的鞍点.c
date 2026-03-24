// Created by Github@TrialNeo(shenpanpro@gmail.com) 
// Created Time 2026/2/27.

// Description
//     由键盘输入一个3＊4（3行4列）的数字矩阵，其中任意两个数字均不相同。要求输出该数字矩阵中的鞍点
//     （即在矩阵行中最大，列中最小的数）。
// 若没有鞍点，输出“NO”字样。
// 输入样例
//     87  90  110  98
//     70  97  210  65
//     99  45  120  30
//
// 输出样例
//     110

#include <stdio.h>

int main(int argc, char *argv[]) {
    int matrix[3][4];
    for (int i = 0; i < 3; ++i) {
        //先扫描进来再说
        for (int j = 0; j < 4; ++j) {
            scanf(" %d", &matrix[i][j]);
        }
    }
    char hasSaddlePoint = 0;
    //寻找行中最大
    for (int i = 0; i < 3; ++i) {
        hasSaddlePoint = 1;
        int max_column_index = 0;
        for (int j = 0; j < 4; ++j) {
            if (matrix[i][j] > matrix[i][max_column_index]) {
                max_column_index = j;
            }
        }
        for (int j = 0; j < 3; ++j) {
            if (matrix[i][max_column_index] > matrix[j][max_column_index]) {
                hasSaddlePoint = 0;
                break;
            }
        }
        if (hasSaddlePoint) {
            printf("%d", matrix[i][max_column_index]);
            break;
        }
    }
    if (!hasSaddlePoint) {
        printf("NO");
    }
}
