// Created by Github@TrialNeo(shenpanpro@gmail.com)
// Created Time 2026/5/29 12:05.
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;


void dfs(vector<char> arr) {

}


int main(int argc, char *argv[]) {
    int N = 0, m = 0;
    scanf("%d %d", &N, &m);
    vector<char> arr(N);
    for (int i = 0; i < N; i++) {
        scanf("%c", &arr[i]);
    }

    return 0;
}



/*
19010 最小的特殊数字
时间限制:1000MS  代码长度限制:10KB
提交次数:0 通过次数:0

题型: 编程题   语言: G++;GCC

Description
用全部N(N<=10)个0-9的数字组成一个“有效”整数（即没有前置0的整数），
求这些组成的数中能被K(0<K<10^10)整除的最小数字。



输入格式
输入分两行，第一行输入N, K，第二行输入N个数字。


输出格式
输出满足条件的最小的数（不含前置0），如果没有满足条件的数输出 -1。


输入样例
4 7
4 0 1 3


输出样例
1043


提示
413 % 7 = 0， 但是有前置0，所以满足条件的最小数是 1043 % 7 = 0。
此类题目需注意特殊情况，比如n=1时,如只输入一个0，答案只能是0。
注意long long


作者 30002692
 */
