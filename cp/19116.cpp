#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>
// 这个居然在力扣做过，默写题了

typedef long long ll;


vector<ll> pre_ugly_num(unsigned size) {
    vector<ll> dp(size + 1);
    dp[1] = 1; // 把第一个位置空出来
    unsigned p2 = 1, p3 = 1, p5 = 1;
    for (size_t i = 2; i <= size; i++) {
        ll next_2 = dp[p2] * 2;
        ll next_3 = dp[p3] * 3;
        ll next_5 = dp[p5] * 5;

        ll next_ugly = min({next_2, next_3, next_5});
        dp[i] = next_ugly;
        if (next_ugly == next_2) {
            p2++;
        }
        if (next_ugly == next_3) {
            p3++;
        }
        if (next_ugly == next_5) {
            p5++;
        }
    }
    return dp;
}


int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<ll> pre = pre_ugly_num(10000);
    unsigned n = 0;
    cin >> n;
    for (size_t i = 0; i < n; i++) {
        unsigned id = 0;
        cin >> id;
        cout << pre[id] << '\n';
    }
    return 0;
}
