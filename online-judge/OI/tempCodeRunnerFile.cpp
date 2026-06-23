#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;


int main() {
    ll n, m;
    cin >> n >> m;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    ll ans = 9999999999;
    do {
        if (!arr[0]) {
            continue;
        }
        ll num = 0;
        for (int i = 0; i < arr.size(); i++) {
            num = num * 10 + arr[i];
            if (!(num % m)) {
                ans = min(ans, num);
            }
        }
    } while (next_permutation(arr.begin(), arr.end()));
    if (ans = 9999999999) {
        cout << "-1";
        return 0;
    }
    cout << ans;
}
