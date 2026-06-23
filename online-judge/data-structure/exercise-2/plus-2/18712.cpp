#include <cstdio>
#include <functional>
#include <vector>

using namespace std;

int main() {
    int m, k;
    scanf("%d%d", &m, &k);

    vector<int> path;

    function<void(int)> dfs = [&](int start) {
        if ((int) path.size() == k) {
            for (int i = 0; i < k; i++) {
                printf("%d ", path[i]);
            }
            printf("\n");
            return;
        }

        for (int i = start; i <= m; i++) {
            if ((int) path.size() + (m - i + 1) < k) {
                break;
            }

            path.push_back(i);
            dfs(i + 1);
            path.pop_back();
        }
    };

    dfs(1);

    return 0;
}

/* 18712 递归实现组合
时间限制:1000MS  代码长度限制:10KB
提交次数:0 通过次数:0

题型: 编程题   语言: G++;GCC

Description
找出从自然数1、2、……、m中任取k个数的所有组合，组合中字典序小的先输出。
例如m=5，k=3，应输出
1 2 3
1 2 4
1 2 5
1 3 4
1 3 5
1 4 5
2 3 4
2 3 5
2 4 5
3 4 5



输入格式
两个整数m和k，(1<=k<=m<=10)


输出格式
按字典序输出所有组合


输入样例
5 2


输出样例
1 2
1 3
1 4
1 5
2 3
2 4
2 5
3 4
3 5
4 5   */
