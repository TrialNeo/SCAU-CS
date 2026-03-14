// Created by Github@TrialNeo(shenpanpro@gmail.com) 
// Created Time 2026/3/14.

/*
    从键盘输入十个整数，输出最小值
    输入格式
    输入的整数绝对值不会超过10000
    输出格式
    按样例格式输出结果
    输入样例
    12  45  76  87  5  87  43  55  99  21
    输出样例
    5
*/

#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
    int temp = 0,min = 0;
    cin >> min;
    for (int i = 0;i<9;i++) {
        cin >> temp;
        if (min > temp) {
            min = temp;
        }
    }
    cout << min << endl;
}
