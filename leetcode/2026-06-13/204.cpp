#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;
typedef unsigned long long llu;

class Solution {
public:
    int minSubArrayLen(int target, vector<llu> &nums) {
        llu len = nums.size(), left = 0, sum = 0, ans = len + 1;
        for (llu right = 0; right < len; right++) {
            sum += nums[right];
            while (sum >= target) {
                ans = min(ans, right - left + 1);
                sum -= nums[left];
                left++;
            }
        }
        return ans <= len ? ans : 0;
    }
};


int main() {
    int n = 0, target = 0;
    scanf_s("%d %d", &target, &n);
    vector<llu> arr(n);
    for (int i = 0; i < n; i++) {
        scanf_s("%llu", &arr[i]);
    }
    Solution s;
    printf("%d", s.minSubArrayLen(target, arr));
    return 0;
}

/*
7
6
2 3 1 2 4 3
*/
