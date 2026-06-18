#include <cmath>
#include <cstdio>
#include <fstream>
#include <vector>

using namespace std;


class Solution {
public:
    int numSubarrayProductLessThanK(vector<int> &nums, int k) {
        if (k <= 1) {
            return 0;
        }
        int left = 0, ans = 0, prod = 1, len = nums.size();
        for (int right = 0; right < len; right++) {
            prod *= nums[right];
            while (prod >= k) {
                prod /= nums[left++];
            }
            ans += right - left + 1;
        }
        return ans;
    }
};


int main() {
    int n = 0, target = 0;
    scanf_s("%d %d", &target, &n);
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        scanf_s("%d", &arr[i]);
    }
    Solution s;
    printf_s("%d", s.numSubarrayProductLessThanK(arr, target));
    return 0;
}
