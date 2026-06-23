#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int minSubArrayLen(int target, vector<int> &nums) {
        int ans = nums.size() + 1, sum = 0;
        int left = 0;
        for (int right = 0; right < nums.size(); right++) {
            sum += nums[right];
            while (sum >= target) {
                ans = min(ans, right - left + 1);
                sum -= nums[left++];
            }
        }
        return ans < nums.size() ? ans : 0;
    }
};
