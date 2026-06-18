// Created by Github@TrialNeo(shenpanpro@gmail.com)
// Created Time 2026/5/8 18:42.

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void print(vector<int> &arr) {
    for (auto it = arr.begin(); it < arr.end(); ++it) {
        printf("%d ", *it);
    }
    putchar('\n');
}

bool cmp(const int x, const int y) { return x < y; }

int main() {
    unsigned n = 0;
    scanf("%u", &n);
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    sort(arr.begin(), arr.end(), cmp);
    do {
        print(arr);
    } while (next_permutation(arr.begin(), arr.end()));

    return 0;
}


/*
19412 N个不同整数全排列
时间限制:1000MS  代码长度限制:10KB
提交次数:0 通过次数:0

题型: 编程题   语言: G++;GCC

描述：
由键盘输入N个不同的整数，输出这N个数的全部排列。

输入格式：
第一行一个正整数。N<=5
每二行N个整数，以空格分隔。

输出格式：
每行一个排列，数之间由一个空格分隔，要求排列按由小到大输出，不允许重复。

输入样例：
3
3 9 1

输出样例：
1 3 9
1 9 3
3 1 9
3 9 1
9 1 3
9 3 1
*/
