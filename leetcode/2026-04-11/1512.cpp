#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int numIdenticalPairs(vector<int> &nums) {
        int n = 0;
        for (auto it = nums.begin(); it != nums.end(); ++it) {
            for (auto it2 = it + 1; it2 != nums.end(); ++it2) {
                n += *it == *it2;
            }
        }
        return n;
    }
};


int main(int argc, char const *argv[]) {
    Solution s;
    vector<int> v = {1, 2, 3, 1, 1, 3};
    cout << s.numIdenticalPairs(v);
    return 0;
}
