#include <iostream>
#include <vector>
using namespace std;


void traversal(const vector<vector<bool>> &graph) {
    int n = graph.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", graph[i][j]);
        }
        putchar('\n');
    }
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    vector<vector<bool>> graph(n, vector<bool>(n, false));
    int x = 0, y = 0;
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &x, &y);
        graph[x - 1][y - 1] = true;
    }
    traversal(graph);
}


/* 8647 实现图的存储结构
时间限制:1000MS  代码长度限制:10KB
提交次数:1499 通过次数:1092

题型: 编程题   语言: G++;GCC

Description
实现有向图的邻接矩阵存储结构。



输入格式
第一行：输入图的顶点个数n（各个顶点的默认编号为1~n）， 边的条数m。
第二 ~ m+1行：每行输入两个顶点编号i、j，表示连接顶点i到顶点j的一条边。


输出格式
分n行输出n*n的邻接矩阵，表示所输入的图存储，顶点i和顶点j之间如果有边相连，则输出1，没边相连则输出0。


输入样例
4 4
1 2
1 3
3 4
4 1


输出样例
0 1 1 0
0 0 0 0
0 0 0 1
1 0 0 0
 */
