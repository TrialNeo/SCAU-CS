#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

vector<ll> pre(int size) {
    vector<ll> res(1 + size, 0);
    res[1] = 1;
    int p2 = 1, p3 = 1, p5 = 1;
    for (int i = 2; i < size; i++) {
        ll next2 = res[p2] * 2, next3 = res[p3] * 3, next5 = res[p5] * 5;
        ll next = min({next2, next3, next5});
        res[i] = next;
        if (next == next5) {
            p5++;
        }
        if (next == next2) {
            p2++;
        }
        if (next == next3) {
            p3++;
        }
    }
    return res;
}


int main() {
    const vector<ll> res = pre(1e6);
    int n = 0;
    int m = 0;
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &n);
        printf("%d\n", res[n]);
    }
    return 0;
}
