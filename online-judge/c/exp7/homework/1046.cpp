// Created by Github@TrialNeo(shenpanpro@gmail.com) 
// Created Time 2026/3/16.

/*
Description
    由键盘输入两个位数很长的整数（一行一个，最多不超过80位），试计算并输出这两个数的和。
输入样例
    1234567890123456789353534532453453453434534
    987654321098765324534534534534532

输出样例
    1234567891111111110452299856987987987969066
提示
    注意，一个普通的变量不能保存十多位长的整数
*/

#include <iostream>
using namespace std;


//想骂人，这种算法不给我过emm
/*
int main(int argc, char *argv[]) {
    string x = "", y = "";
    cin >> x >> y;
    char bit = 0;
    // 检查长度
    if (x.length() < y.length()) {
        swap(x, y);
    }
    int delta = x.length() - y.length();
    for (int i = y.length() - 1; i >= 0; i--) {
        bit = x[delta + i] - '0' + y[i] - '0';
        if (bit >= 10) {
            x[delta + i] = bit - 10 + '0';
            if (i == 0) {
                x = '1' + x;
                continue;
            }
            x[delta + i - 1] += 1;
        } else {
            x[delta + i] = bit + '0';
        }
    }
    cout << x << endl;
}
*/


int main(int argc, char *argv[]) {

}
