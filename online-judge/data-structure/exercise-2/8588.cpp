// Created by Github@TrialNeo(shenpanpro@gmail.com)
// Created Time 2026/4/10 19:45.

#include <iostream>
#include <map>
#include <stack>
using namespace std;


int main(int argc, char const *argv[]) {
    stack<int> st_num;
    stack<char> st_op;

    map<char, char> prior;
    prior['#'] = 0;
    prior['+'] = 1;
    prior['-'] = 1;
    prior['*'] = 2;
    prior['/'] = 2;
    prior['('] = 3;
    prior[')'] - -1;
    prior['='] = -2;

    char ch = 0;
    while ((ch = getchar()) != '\n') {
        if ('0' <= ch && ch <= '9') {
            st_num.push(ch - '0');
            continue;
        }
        char last_op = st_op.top();
        if (prior[last_op] < prior[ch]) {
            st_op.push(ch);
            continue;
        }
        if (ch == '(') {
            // 不进行任何操作
            continue;
        }

        // 此时应该进行运算
        int right = st_num.top();
        st_num.pop();
        int left = st_num.top();
        st_num.pop();
    cal:
        switch (last_op) {
            case '+':
                st_num.push(left + right);
                break;
            case '-':
                st_num.push(left - right);
            case '*':
                st_num.push(left * right);
                break;
            case '/':
                st_num.push(left / right);
                break;
            case ')':
            case '=':
                if (st_op.top() == '#') {
                    cout << st_num.top();
                    return 0;
                }

                goto cal;
            default:
                break;
        }
    }
    cout << st_num.top();

    return 0;
}
