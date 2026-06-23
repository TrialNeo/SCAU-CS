#include <cstdio>
#include <functional>
#include <vector>

using namespace std;


int main() {

    int n = 0;
    scanf("%d", &n);

    vector<vector<int>> tree(n + 1, vector<int>(3, 0)); // 一棵类似的树，序号是有规律的就可以用了


    for (int i = 1; i < n; i++) {
        int parent, child;
        scanf("%d%d", &parent, &child);
        if (tree[parent][1]) {
            tree[parent][2] = child;
        } else {
            tree[parent][1] = child;
        }
    }
    int ans = 0;

    function<int(int)> dfs = [&](int node) {
        if (!node) {
            return 0;
        }
        int first = 0, second = 0;
        first = dfs(tree[node][1]);
        second = dfs(tree[node][2]);
        ans = max(ans, first + second);
        return 1 + max(first, second);
    };
    dfs(1);
    printf("%d\n", ans);
}

/*
18923 二叉树的直径
时间限制:1000MS  代码长度限制:10KB
提交次数:0 通过次数:0

题型: 编程题   语言: G++;GCC

Description
给定一棵二叉树，你需要计算它的直径长度。一棵二叉树的直径长度是任意两个结点路径长度中的最大值。这条路径可能穿过也可能不穿过根结点。
          1
         / \
        2   3
       / \
      4   5
答案为3, 它的长度是路径 [4,2,1,3] 或者 [5,2,1,3]。



输入格式
共n行。
第一行一个整数n，表示有n个结点，编号为1至n。
第二行至第n行，每行有两个整数x和y，表示在二叉树中x为y的父节点。x第一次出现时y为左孩子


输出格式
输出二叉树的直径。


输入样例
5
1 2
1 3
2 4
2 5


输出样例
3
*/
