#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int n, m;
    scanf("%d%d", &n, &m);

    vector<vector<char>> maze(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        scanf("%s", &maze[i][0]);
    }

    if (maze[0][0] == '1' || maze[n - 1][m - 1] == '1') {
        printf("no\n");
        return 0;
    }

    vector<vector<int>> visited(n, vector<int>(m, 0));
    queue<pair<int, int>> q;

    q.push(make_pair(0, 0));
    visited[0][0] = 1;

    vector<int> dx(4);
    vector<int> dy(4);
    dx[0] = 1;
    dy[0] = 0;
    dx[1] = -1;
    dy[1] = 0;
    dx[2] = 0;
    dy[2] = 1;
    dx[3] = 0;
    dy[3] = -1;

    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();

        int x = cur.first;
        int y = cur.second;

        if (x == n - 1 && y == m - 1) {
            printf("yes\n");
            return 0;
        }

        for (int i = 0; i < 4; i++) {
            int next_x = x + dx[i];
            int next_y = y + dy[i];

            if (next_x >= 0 && next_x < n && next_y >= 0 && next_y < m) {
                if (!visited[next_x][next_y] && maze[next_x][next_y] == '0') {
                    visited[next_x][next_y] = 1;
                    q.push(make_pair(next_x, next_y));
                }
            }
        }
    }

    printf("no\n");

    return 0;
}

/*
输入格式
第一行两个整数n和m，代表n行m列。(1<=n,m<=10)
下面n行每行m个字符,0代表可以通行，1代表不可以通行。


输出格式
如果能从迷宫走出，输出yes，否则输出no。


输入样例
8 8
00100010
00100010
00001100
01110000
00010000
01000100
01110110
00001000


输出样例
yes
*/
