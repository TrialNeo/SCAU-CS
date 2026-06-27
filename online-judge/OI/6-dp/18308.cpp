#include <functional>
#include <iostream>
#include <string>
#include <vector>

using namespace std;


int main() {

    string a, b;
    cin >> a >> b;
    auto len_a = a.length(), len_b = b.length();
    // vector<vector<int>> memo(len_a, vector<int>(len_b, -1));
    // function<int(int, int)> dfs = [&](int p, int q) {
    //     if (p < 0 || q < 0) {
    //         return 0;
    //     }
    //     if (memo[p][q] > -1) {
    //         return memo[p][q];
    //     }
    //     return a[p] == b[q] ? dfs(p - 1, q - 1) + 1 : max(dfs(p - 1, q), dfs(p, q - 1));
    // };
    // cout << dfs(len_a - 1, len_b - 1) << endl;

    // //连记忆化搜索都超时。改成dp。
    vector<vector<int>> memo(len_a + 1, vector<int>(len_b + 1, 0));
    for (int i = 0; i < len_a; i++) {
        for (int j = 0; j < len_b; j++) {
            memo[i + 1][j + 1] = a[i] == b[j] ? memo[i][j] + 1 : max(memo[i][j + 1], memo[i + 1][j]);
        }
    }
    cout << memo[len_a][len_b] << endl;

    


}

/*
18308 最长公共子序列长度
时间限制:1000MS  代码长度限制:10KB
提交次数:0 通过次数:0

题型: 编程题   语言: G++;GCC

Description
给定两个字符串，请输出这两个字符串的最大公共子序列



输入格式
两行，一行一个字符串（不包括空格，Tab键）,长度不超过1000


输出格式
输出最大公共子序列的长度


输入样例
abbca
aba


输出样例
3

*/
