// Created by Github@TrialNeo(shenpanpro@gmail.com)
// Created Time 2026/5/29 15:25.
#include <cstdio>
#include <functional>
#include <math.h>
#include <vector>

using namespace std;
/*
bool check(const vector<int> &chessboard, const int q) {
    for (int i = 0; i < q; i++) {
        if (chessboard[i] == chessboard[q] || abs(chessboard[i] - chessboard[q]) == abs(i - q)) {
            return false;
        }
    }
    return true;
}

void solve(vector<int> &chessboard, const int r, int forbidden_x, int forbidden_y, int &res) {
    if (r >= chessboard.size()) {
        res++;
        return;
    }

    for (int i = 0; i < chessboard.size(); i++) {
        if (r == forbidden_x && i == forbidden_y) {
            continue;
        }
        chessboard[r] = i;
        if (check(chessboard, r)) {
            solve(chessboard, r + 1, forbidden_x, forbidden_y, res);
        }
    }
}

int main() {
    int n = 0, m = 0, x = 0, y = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int res = 0;
        scanf("%d%d%d", &m, &x, &y);
        x--, y--;
        vector<int> chessboard(m, 0);
        solve(chessboard, 0, x, y, res);
        printf("%d\n", res);
    }
    return 0;
}
 */

int main() {
    int n = 0;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int m = 0, x, y;
        scanf("%d%d%d", &m, &x, &y);
        x--, y--;
        vector<int> board(m); // 通过行号获取列号
        int ans = 0;
        function<void(int)> dfs = [&](int row) {
            if (row == m) {
                ans++;
                return;
            }

            auto check = [&](int col) {
                for (int r = 0; r < row; r++) {
                    if (col == board[r] || abs(col - board[r]) == abs(r - row)) {
                        return false;
                    }
                }
                return true;
            };

            for (int c = 0; c < m; c++) {
                if (row == x && c == y) {
                    continue;
                }
                if (check(c)) {
                    board[row] = c;
                    dfs(row + 1);
                }
            }
        };

        dfs(0);
        printf("%d\n", ans);
    }
}

/*
19735 M皇后问题
时间限制:5000MS  代码长度限制:10KB
提交次数:0 通过次数:0

题型: 编程题   语言: G++;GCC

描述：
有M*M的国际象棋棋盘，要求在上面放M个皇后，要求任意两个皇后不会互杀，除此之外，棋盘中有一个指定的特殊位置不能放置皇后，问符合要求的放置方法有多少种？

输入格式：
每一个数为T，代表CASE的数量，T<=13
此后，每行三个数M，X, Y（13>=M>0，M>=X>=1, M>=Y>=1），（X，Y）是不能放置皇后的位置。

输出格式：
每一个CASE，输出对应答案，一行一个数

输入样例：
2
4 1 3
5 2 2

输出样例：
1
8
 */
