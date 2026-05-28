// Created by Github@TrialNeo(shenpanpro@gmail.com)
// Created Time 2026/5/27 15:38.

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

// N<=10 超时的概率其实不太大

void traversal(const vector<ll> &arr) {
    for (int i = 0; i < arr.size(); i++) {
        printf("%lld ", arr[i]);
    }
    putchar('\n');
}

bool check(vector<ll> &arr) {
    // 直接用双指针来找就行了
    auto p = arr.begin(), q = arr.begin() + 1;
    while (p != arr.end() || q != arr.end()) {
    }
}


int main(int argc, char *argv[]) {
    int n = 0;
    scanf("%d", &n);
    vector<ll> arr(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &arr[i]);
    }
    while (next_permutation(arr.begin(), arr.end())) {
        while (check(arr)) {
            traversal(arr);
        }
    }
    return 0;
}


/*
19650 有重复元素排列问题
时间限制:1000MS  代码长度限制:10KB
提交次数:0 通过次数:0

题型: 编程题   语言: G++;GCC

描述：
从键盘输入N个整数N<=10,要求输出这N个整数的全排列，且每一个排列当中，相邻两个数不能同为奇数。

输入格式：
第一行一个正整数N
第二行N个整数，以空格分隔

输出格式：
一行一个排列，按小到大的顺序输出

输入样例：
3
1 1 2

输出样例：
1 2 1
*/
