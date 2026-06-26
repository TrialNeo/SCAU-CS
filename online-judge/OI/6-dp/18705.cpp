// Created by Github@TrialNeo(shenpanpro@gmail.com)
// Created Time 2026/6/25 15:38.

#include <algorithm>
#include <cstdio>
#include <functional>
#include <vector>

using namespace std;


int main() {
    int c = 0, n = 0;

    scanf("%u%u", &c, &n);
    vector<unsigned> w(n), v(n);
    for (int i = 0; i < n; i++) {
        scanf("%u%u", &w[i], &v[i]);
    }
    /*
    function<unsigned(int, unsigned)> solve = [&](int i, unsigned c) -> unsigned { // c是背包的剩余容量
        if (i < 0) {
            return 0;
        }
        // 装不下
        if (c < w[i]) {
            return solve(i - 1, c);
        }
        return max(solve(i - 1, c), solve(i - 1, c - w[i]) + v[i]);
    };
    printf("%u\n", solve(n - 1, c));
    */
    // 正所谓dfs差不多都能改
    // 可以改进成记忆化搜索
    vector<vector<int>> memo(n, vector<int>(c + 1, -1));

    function<unsigned(int, unsigned)> solve = [&](int i, unsigned c) -> unsigned { // c是背包的剩余容量
        if (i < 0) {
            return 0;
        }
        if (memo[i][c] != -1) {
            return memo[i][c];
        }
        // 装不下
        if (c < w[i]) {
            return memo[i][c] = solve(i - 1, c);
        } else {
            return memo[i][c] = max(solve(i - 1, c), solve(i - 1, c - w[i]) + v[i]);
        }
    };
    printf("%u\n", solve(n - 1, c));


    // 还能改进成dp
    // 我们看state transition eqn
    // f_i max(f_{i - 1} , f_{i - 1} + v[i]) => f_{i + 1} max(f_{i} , f_{i} + v[i])
    // => f_{1} max(f_{0} , f_{0} + v[i])


    /*

    vector<vector<unsigned>> dp(n + 1, vector<unsigned>(c + 1, 0));

    // 自顶向下：i 从 n-1 到 0
    for (int i = 0; i < n; i++) {
        for (int capacity = 0; capacity <= c; capacity++) {
            if (capacity < w[i]) {
                // 装不下，只能跳过
                dp[i][capacity] = dp[i + 1][capacity];
            } else {
                // 装得下：选或不选取最大
                dp[i][capacity] = max(dp[i + 1][capacity], dp[i + 1][capacity - w[i]] + v[i]);
            }
        }
    }
    printf("%u\n", dp[0][c]);
    */
}

/*

18705 01背包问题
时间限制:300MS  代码长度限制:10KB
提交次数:0 通过次数:0

题型: 编程题   语言: G++;GCC

Description
有一个容积为C的背包和N件物品。第i件物品的体积W[i]，价值是V[i]。求解将哪些物品装入背包可使价值总和最大。每种物品只有一件，
可以选择放或者不放入背包。



输入格式
第一行：两个整数，C(背包容量，C<=200)和N(物品数量，N<=30)；
第2..N+1行：每行二个整数Wi，Vi，表示每个物品的重量和价值。


输出格式
一个数，表示最大总价值。


输入样例
10 4
2 1
3 3
4 5
7 9


输出样例
12

*/
