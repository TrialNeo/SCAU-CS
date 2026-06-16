#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    static int lengthOfLongestSubstring(string s) {
        pmr::unordered_map<char, bool> cnt;
        int left = 0, len = s.length(), ans = 0;
        for (int right = 0; right < len; right++) {
            while (cnt[s[right]]) {
                cnt[s[left++]] = false;
            }
            cnt[s[right]] = true;
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};


int main() {}
