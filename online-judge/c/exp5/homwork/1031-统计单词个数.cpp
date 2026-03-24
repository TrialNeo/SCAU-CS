// Created by Github@TrialNeo(shenpanpro@gmail.com) 
// Created Time 2026/3/14.

#include <iostream>
using namespace std;
// 写一个函数实现：输入一行字符，以空格分割单词，回车结束输入，输出单词的个数
// 输入样例
// There are many students and many trees!
// 输出样例
// 7

int main(int argc, char *argv[]) {
    char ch = 0;
    bool in_word = false;
    unsigned count = 0;
    while ((ch = getchar()) != '\n') {
        if (ch != ' ') {
            if (!in_word) {
                count++;
                in_word = true;
            }
        }else {
            in_word = false;
        }
    }
    cout << count;
}
