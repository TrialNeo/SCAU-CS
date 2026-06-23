#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

vector<vector<int>> tree;
vector<int> width;

void dfs(int node, int depth) {
    width[depth]++;

    for (int child: tree[node]) {
        dfs(child, depth + 1);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    tree.resize(n + 1);
    width.resize(n, 0);

    for (int i = 1; i < n; i++) {
        int parent, child;
        scanf("%d%d", &parent, &child);

        tree[parent].push_back(child);
    }

    dfs(1, 0);

    printf("%d", *max_element(width.begin(), width.end()));

    return 0;
}


/*
Description
二叉树的宽度指的是具有节点数目最多的那一层的节点个数。
          1
         / \
        2   3
       /
      4
答案为2, 第二层节点数最多，为2个节点。



输入格式
共n行。
第一行一个整数n，表示有n个结点，编号为1至n,结点1为树根。（1<=n<=50）
第二行至第n行，每行有两个整数x和y，表示在二叉树中x为y的父节点。x第一次出现时y为左孩子


输出格式
输出二叉树的宽度。


输入样例
5
1 2
1 3
2 4
2 5


输出样例
2
*/
