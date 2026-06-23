#include <cstdio>
#include <functional>
#include <vector>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    function<void(int, int)> dfs = [&](int start, int sum) {
        for (int i = start; i < n; i++) {
            int new_sum = sum + a[i];
            printf("%d\n", new_sum);
            dfs(i + 1, new_sum);
        }
    };

    dfs(0, 0);

    return 0;
}

/*
19071 递归实现指数型枚举
时间限制:1000MS  代码长度限制:10KB
提交次数:0 通过次数:0

题型: 编程题   语言: G++;GCC;VC;JAVA;PYTHON

Description
递归实现指数型枚举是一种常用的DFS算法，复杂度是2^n，只能在n比较小的时候使用。
一般用于：从 1∼n 这 n 个整数中随机选取（或者有某些规则限制）任意多个，输出所有可能的选择方案。
其实背包问题也可以用这种方法解决，只是复杂度会比较高......
一个旅行者有一个最多能装 M 公斤的背包，现在有 n 件物品，它们的重量分别是W1，W2，...,Wn，旅行者最多能装多少重量。

本题目题面：
给你N个整数，从中选取任意多个（至少选择一个），输出所有可能的选择方案，
无需输出每个数字，只需要输出选择数字的和。



输入格式
第一样输入一个整数 n。
第二行输入n个整数。1<=n<=10


输出格式
输出所有的方案，注意输出要按字典序。
即按如下次序
a1
a1+a2
a1+a2+a3
a1+a2+a3......
a2
a2+a3
a2+a3+......
......
an


输入样例
3
240 300 360


输出样例
240
540
900
600
300
660
360


提示
指数型枚举在每一步中都有两种选择，选中这个元素或不选中，对这两种情况分别递归即可。
*/
