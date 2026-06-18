#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

typedef unsigned long long ull;

int main() {
    int n, m;
    while (scanf("%d %d", &n, &m) == 2 && n && m) {
        vector<int> heads(n);
        vector<int> knights(m);
        for (int i = 0; i < n; i++) {
            scanf("%d", &heads[i]);
        }
        for (int i = 0; i < m; i++) {
            scanf("%d", &knights);
        }
        sort(heads.begin(), heads.end());
        sort(knights.begin(), knights.end());
        ull cost = 0;
        int p = 0, q = 0;
        // double pointer
        while (p < n && q < m) {
            if (knights[q] < heads[p]) {
                q++;
                continue;
            }
            cost += knights[q++];
            p++;
        }
        if (p == n) {
            printf("%llu\n", cost);
        } else {
            printf("Loowater is doomed!\n");
        }
    }
}
