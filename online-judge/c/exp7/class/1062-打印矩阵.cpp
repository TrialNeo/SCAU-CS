// Created by Github@TrialNeo(shenpanpro@gmail.com) 
// Created Time 2026/3/14.


/*
由键盘输入一个3＊4的矩阵，要求输出它的转置矩阵。
输入格式
3行4列的矩阵，数与数之间由一个空格分隔
输出格式
4行3列的矩阵，数与数之间由一个空格分隔
输入样例
1 6 9 3
1 1 0 2
1 9 8 9

输出样例
1 1 1
6 1 9
9 0 8
3 2 9
*/

#include <iostream>

int main(int argc, char *argv[]) {
    int matrix[3][4];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            std::cin >> matrix[i][j];
        }
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << matrix[j][i] << " ";
        }
        std::cout << std::endl;
    }
}
