#include <cstdio>
#include <stack>
#include <vector>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);

    vector<int> push_seq(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &push_seq[i]);
    }

    vector<int> suffix_max(n + 1, 0);
    for (int i = n - 1; i >= 0; i--) {
        if (push_seq[i] > suffix_max[i + 1]) {
            suffix_max[i] = push_seq[i];
        } else {
            suffix_max[i] = suffix_max[i + 1];
        }
    }

    stack<int> st;
    vector<int> pop_seq;
    int pos = 0;

    while ((int) pop_seq.size() < n) {
        if (st.empty()) {
            st.push(push_seq[pos]);
            pos++;
        } else if (pos < n && st.top() < suffix_max[pos]) {
            st.push(push_seq[pos]);
            pos++;
        } else {
            pop_seq.push_back(st.top());
            st.pop();
        }
    }

    for (int i = 0; i < n; i++) {
        if (i > 0) {
            printf(" ");
        }
        printf("%d", pop_seq[i]);
    }
    printf("\n");

    return 0;
}

/*
18715 出栈序列
时间限制:1000MS  代码长度限制:10KB
提交次数:0 通过次数:0

题型: 编程题   语言: G++;GCC

Description
一种简洁的栈定义方法如下
int st[1000],top=0;//以top作为栈顶指针，top==0为空栈
st[top++]=x;//把x入栈，栈顶指针+1
top--;//出栈
现在有一个1-n的排列，入栈序列已知，请给出字典序最大的出栈序列。



输入格式
第一行一个整数n。(1<=n<=100)
第二行n个整数，数据确保为1-n的排列。


输出格式
输出n个整数，既字典序最大的出栈序列。


输入样例
5
1 2 4 5 3


输出样例
5 4 3 2 1

*/
