#include <cstdio>
#include <stack>
#include <vector>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);

    vector<int> push_seq(n);
    vector<int> pop_seq(n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &push_seq[i]);
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &pop_seq[i]);
    }

    stack<int> st;
    int j = 0;

    for (int i = 0; i < n; i++) {
        st.push(push_seq[i]);

        while (!st.empty() && j < n && st.top() == pop_seq[j]) {
            st.pop();
            j++;
        }
    }

    if (j == n) {
        printf("yes\n");
    } else {
        printf("no\n");
    }

    return 0;
}

/*
Description
每年期末考试必考题目。

一个栈的进栈序列是a、b、c、d、e，则可能的出栈序列是（  ）。

A．abecd         B．decba         C．dceab        D．cabde

输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否可能为该栈的弹出顺序。

假设压入栈的所有数字均不相等。例如序列1,2,3,4,5是某栈的压入顺序，序列4,5,3,2,1是该压栈序列对应的一个弹出序列，

但4,3,5,1,2就不可能是该压栈序列的弹出序列。（注意：这两个序列的长度是相等的）



输入格式
第一行一个整数n，表示输入序列的长度。(1<=n<=10000)

第二行n个整数，表示栈的压入顺序。

第三行n个整数，表示栈的出栈顺序。


输出格式
如果是弹出序列，输出yes，否则输出no。


输入样例
5
1 2 3 8 6
8 6 3 2 1

*/
