#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    vector<int> shuffle(vector<int> &nums, int n) {
        vector<int> res;
        for (size_t i = 0; i < n; i++) {
            res.push_back(nums[i]);
            res.push_back(nums[n + i]);
        }
        return res;
    }
};


int main(int argc, char const *argv[]) {
    Solution s;
    vector a = {2, 5, 1, 3, 4, 7};
    auto r = s.shuffle(a, 3);
    for (size_t i = 0; i < r.size(); i++) {
        cout << r[i] << ' ';
    }

    return 0;
}
