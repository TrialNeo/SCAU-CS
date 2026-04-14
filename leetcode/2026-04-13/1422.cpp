#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>

class Solution {
public:
    int maxScore(string s) {
        // 这个不就是前缀和吗。。
        // 先统计一下所有1的数量
        unsigned count_one = 0;
        for (auto it = s.begin() + 1; it != s.end(); it++) {
            if (*it == '1') {
                count_one++;
            }
        }
        unsigned max_score = count_one;
        unsigned left_score = 0;
        if (*s.begin() == '0') {
            max_score++;
            left_score = 1;
        }
        unsigned right_score = count_one;
        if (*s.end() - 1 == '1') {
            max_score++;
            right_score++;
        }

        for (auto it = s.begin() + 1; it != s.end() - 1; it++) {
            if (*it == '0') {
                left_score++;
            } else {
                right_score--;
            }
            max_score = max(max_score, left_score + right_score);
        }
        return max_score;
    }
};


int main(int argc, char const *argv[]) {
    Solution s;
    cout << s.maxScore("011");

    return 0;
}
