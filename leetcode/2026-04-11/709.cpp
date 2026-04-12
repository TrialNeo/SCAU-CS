#include <iostream>
using namespace std;
#include <string>

class Solution {
public:
    string toLowerCase(string s) {
        char tmp = 0;
        for (size_t i = 0; i < s.size(); i++) {
            tmp = s[i];
            if ('A' <= tmp && tmp <= 'Z') {
                // s[i] += 32;
                // 根据ascll表，我们好像直接去异或性能会更好
                s[i] = tmp ^ 0b00100000;
            }
        }
        return s;
    }
};


int main(int argc, char const *argv[]) {
    Solution s;
    string str = "Hello";
    cout << s.toLowerCase(str);
    return 0;
}
