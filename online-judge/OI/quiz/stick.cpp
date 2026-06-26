#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;

/* int main() {
    int n;
    scanf("%d", &n);

    vector<int> sticks(n);
    int total_len = 0;
    int max_len = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &sticks[i]);
        total_len += sticks[i];
        if (sticks[i] > max_len) {
            max_len = sticks[i];
        }
    }

    sort(sticks.begin(), sticks.end(), greater<int>());

    for (int k = n; k > 0; k--) {
        if (total_len % k != 0) {
            continue;
        }

        int target_len = total_len / k;
        if (target_len < max_len) {
            continue;
        }

        vector<int> used(n, 0);

        function<bool(int, int, int)> dfs = [&](int group_count, int start_pos, int current_len) {
            if (group_count == k - 1) {
                return true;
            }

            if (current_len == target_len) {
                return dfs(group_count + 1, 0, 0);
            }

            int last_len = -1;

            for (int i = start_pos; i < n; i++) {
                if (used[i] || sticks[i] == last_len) {
                    continue;
                }

                if (current_len + sticks[i] > target_len) {
                    continue;
                }

                used[i] = 1;

                if (dfs(group_count, i + 1, current_len + sticks[i])) {
                    return true;
                }

                used[i] = 0;
                last_len = sticks[i];

                if (current_len == 0 || current_len + sticks[i] == target_len) {
                    return false;
                }
            }

            return false;
        };

        if (dfs(0, 0, 0)) {
            printf("%d\n", k);
            return 0;
        }
    }

    printf("1\n");
    return 0;
}
 */


int main() {
    int n;
    cin >> n;
    vector<unsigned> stick(n);
    unsigned sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> stick[i];
        sum += stick[i];
    }

    unsigned ans = 0;
    function<void(int, int)> dfs = [&](int i, int c) {
        if (i < 0 && c == 0) {

            return;
        }

        dfs(i - 1, c);
    };


    return 0;
}

/* 描述：
给定N条整数长度的木棍，需要将这N条木根分为K组，要求每组的木棍总长相等，如果有多种分法，输出K值最大的解Kmax。

输入格式：
第一行为一个整数N，（1<=N<=30）

输出格式：
输出K值最大的解Kmax

输入样例：
7
4 3 2 3 5 2 1

输出样例：
4

提示
K=4，每组木棍总长为5 */
