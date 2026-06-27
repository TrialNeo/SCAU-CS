// 填空题来的

#include <queue>
#include <stdio.h>
using namespace std;
typedef struct {
    int r; // row
    int c; // column
    int s; // step
} LOC;
int sr, sc, dr, dc;
int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
char d[100][100];
void solve() {
    int m, n, i, nr, nc;
    queue<LOC> q;
    scanf("%d%d", &m, &n);
    for (i = 0; i < m; i++)
        scanf("%s", d[i]);
    scanf("%d%d%d%d", &sr, &sc, &dr, &dc);
    LOC first = {sr, sc, 0};
    q.push(first);
    while (!q.empty()) {
        // 填这个位置
        LOC cur = q.front();
        q.pop();
        if (cur.r == dr && cur.c == dc) {
            printf("%d\n", cur.s);
            return;
        }
        for (int i = 0; i < 4; i++) {
            nr = cur.r + dir[i][0]; //row的变化
            nc = cur.c + dir[i][1]; //col的变化
            if (d[nr][nc] == '0') {
                q.push({nr, nc, cur.s+  1});
                d[nr][nc] = '1';
            }
        }
    }
    printf("die\n");
}
int main() {
    int n;
    scanf("%d", &n);
    while (n--)
        solve();
}

/*
输入格式
该程序为多CASE，第1行为CASE的数量
每一个CASE，第1行为两个数N（行）和M（列）
然后N行每行M个数，之后是起点坐标和终点坐标sc(行) sr(列) ec(行) er(列)
//这个出题人懂英文吗，为什么行row用的c??列column用的是r？？神奇
//他自己写代码的时候又搞对了，很无语


输出格式
如题


输入样例
2
4 3
011
000
110
110
0 0 3 2
2 2
01
10
0 0 1 1


输出样例
5
die

*/
