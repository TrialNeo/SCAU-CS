#include <algorithm>
#include <cstdio>
#include <functional>
#include <vector>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int n;
        scanf("%d", &n);

        vector<int> a(n);
        int total_sum = 0;

        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            total_sum += a[i];
        }

        int ans = total_sum;

        function<void(int, int, int)> dfs = [&](int index, int diff, int throw_sum) {
            if (index == n) {
                if (diff == 0) {
                    ans = min(ans, throw_sum);
                }
                return;
            }

            dfs(index + 1, diff + a[index], throw_sum);

            dfs(index + 1, diff - a[index], throw_sum);

            dfs(index + 1, diff, throw_sum + a[index]);
        };

        dfs(0, 0, 0);

        printf("%d\n", ans);
    }

    return 0;
}


/*
19044 平分物品（递归实现指数型枚举）
时间限制:1000MS  代码长度限制:10KB
提交次数:0 通过次数:0

题型: 编程题   语言: G++;GCC;VC;JAVA;PYTHON

Description
网易2021校招笔试-文本挖掘算法工程师（提前批）第一题

现在有n个物品，每一个物品都有一个价值，现在想将这些物品分给两个人，
要求这两个人每一个人分到的物品的价值总和相同（个数可以不同，总价值相同即可，
剩下的物品就需要扔掉，现在想知道最少需要扔多少价值的物品才能满足要求分给两个人。

要求：时间复杂度O(3^n)，空间复杂度O(n)







输入格式
第一行输入一个整数 T，代表有 T 组测试数据。
对于每一组测试数据，一行输入一个整数 n ，代表物品的个数。
接下来 n 个数，a[i] 代表每一个物品的价值。
1<= T <= 10
1 <= n <= 15
1 <= a[i] <= 100000


输出格式
对于每一组测试数据，输出一个答案代表最少需要扔的价值。
多组数据需要换行。


样例解释，扔掉第三个和第四个物品，然后将第一个物品和第五个物品给第一个人，
第二个物品给第二个人，每一个人分到的价值为60，扔掉的价值为20。


输入样例
1
5
30 60 5 15 30


输出样例
20
*/

/*
思路：对每个物品都有 3 种选择：

分给第一个人
分给第二个人
扔掉
用递归枚举所有情况，复杂度就是 O(3^n)。

递归过程中维护：

diff：两个人当前价值差，diff = 第一个人的总价值 - 第二个人的总价值
throw_sum：当前已经扔掉的总价值
当所有物品都处理完时：

如果 diff == 0，说明两个人分到的价值相等
用 throw_sum 更新最小答案
*/
