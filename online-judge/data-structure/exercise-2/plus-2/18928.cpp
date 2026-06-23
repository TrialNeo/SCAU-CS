#include <cstdio>
#include <functional>
#include <vector>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);

    vector<int> path;
    vector<int> used(n + 1, 0);

    function<void()> dfs = [&]() {
        if ((int) path.size() == n) {
            for (int i = 0; i < n; i++) {
                if (i > 0) {
                    printf(" ");
                }
                printf("%d", path[i]);
            }
            printf("\n");
            return;
        }

        for (int i = 1; i <= n; i++) {
            if (!used[i]) {
                used[i] = 1;
                path.push_back(i);

                dfs();

                path.pop_back();
                used[i] = 0;
            }
        }
    };

    dfs();

    return 0;
}

/*
18928 递归实现全排列
时间限制:1000MS  代码长度限制:10KB
提交次数:0 通过次数:0

题型: 编程题   语言: G++;GCC

Description
把 1至n 这 n 个整数排成一行后随机打乱顺序，输出所有可能的次序。

输入格式
一个整数n。(1<=n<=9)

输出格式
按照从小到大的顺序输出所有方案，每行一个方案。
同一行相邻两个数用一个空格隔开。
对于两个不同的行，对应下标的数一一比较，字典序较小的排在前面。

输入样例
3

输出样例
1 2 3
1 3 2
2 1 3
2 3 1
3 1 2
3 2 1


*/
