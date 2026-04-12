#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    int countGoodTriplets(vector<int> &arr, int a, int b, int c) {
        // 直接无脑遍历
        unsigned count = 0;
        for (size_t i = 0; i < arr.size(); i++) {
            for (size_t j = i + 1; j < arr.size(); j++) {
                for (size_t k = j + 1; k < arr.size(); k++) {
                    if (abs(arr[i] - arr[j]) <= a && abs(arr[j] - arr[k]) <= b && abs(arr[i] - arr[k]) <= c) {
                        count++;
                    }
                }
            }
        }
        return count;
    }
};

int main(int argc, char const *argv[]) {
    Solution s;
    vector nums = vector<int>({3, 0, 1, 1, 9, 7});
    cout << s.countGoodTriplets(nums, 7, 2, 3);
    return 0;
}
