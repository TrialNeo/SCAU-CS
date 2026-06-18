#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
typedef long long ll;

/* ll solve(const vector<ll> &arr) {
    vector<ll> ans(arr.size(), 0);
    ans[0] = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        ans[i] = ans[i - 1] > 0 ? ans[i - 1] + arr[i] : arr[i];
    }
    auto max_ans = max_element(ans.begin(), ans.end());
    return *max_ans;
} */

// 再次优化
ll solve(const vector<ll> &arr) {
    ll max_ans = arr[0];
    ll sum = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        sum = sum > 0 ? sum + arr[i] : arr[i];
        max_ans = max(max_ans, sum);
    }
    return max_ans;
}


int main(int argc, char const *argv[]) {
    int n = 0;
    scanf("%d", &n);
    vector<ll> arr(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &arr[i]);
    }
    printf("%lld", solve(arr));
    return 0;
}


/*
Description
    一个整数序列，选出其中连续且非空的一段使得这段和最大。
输入格式
    第一行是一个正整数N，表示了序列的长度（0=<N<=200000）。
    第二行包含N个绝对值不大于10000的整数ai。
输出格式
    一个整数，为最大的子段和。子段的最小长度为1。数据确保结果在类型int范围内。
输入样例
7
2 -4 3 -1 2 -4 3
输出样例
4
提示
【样例说明】
2,-4,3,-1,2,-4,3中，最大的子段和为4，该子段为第三元素至第五元素，即3,-1,2。
*/
