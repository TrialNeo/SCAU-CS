// Created by Github@TrialNeo(shenpanpro@gmail.com)
// Created Time 2026/4/10 19:45.

#include <iostream>
#include <map>
#include <stack>
using namespace std;
int main() {
    stack<int> st_num;
    stack<char> st_op;
    st_op.push('#'); // 哨兵
    map<char, int> prior = {{'#', 0}, {'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}, {'(', 3}};
    auto apply = [&]() {
        char op = st_op.top();
        st_op.pop();
        int r = st_num.top();
        st_num.pop();
        int l = st_num.top();
        st_num.pop();
        switch (op) {
            case '+':
                st_num.push(l + r);
                break;
            case '-':
                st_num.push(l - r);
                break;
            case '*':
                st_num.push(l * r);
                break;
            case '/':
                st_num.push(l / r);
                break;
            default:
                break;
        }
    };
    char ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {
        if (isdigit(ch)) {
            int num = 0;
            while (isdigit(ch)) {
                num = num * 10 + (ch - '0');
                ch = getchar();
            }
            st_num.push(num);
            if (ch == '\n' || ch == EOF)
                break;
        }
        if (ch == '(') {
            st_op.push(ch);
        } else if (ch == ')') {
            while (st_op.top() != '(')
                apply();
            st_op.pop(); // 弹出 '('
        } else if (ch == '=') {
            while (st_op.top() != '#')
                apply();
            cout << st_num.top() << endl;
            return 0;
        } else { // + - * /
            while (st_op.top() != '(' && prior[st_op.top()] >= prior[ch]) {
                apply();
            }
            st_op.push(ch);
        }
    }
    while (st_op.top() != '#')
        apply();
    cout << st_num.top() << endl;
    return 0;
}
