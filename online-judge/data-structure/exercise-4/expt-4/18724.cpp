#include <cstdio>
#include <functional>
#include <iostream>
#include <string>
#include <vector>


using namespace std;

int main() {


    string pre_seq;
    string in_seq;
    string post_seq;

    cin >> pre_seq >> in_seq;

    auto n = pre_seq.size();

    function<void(int, int, int, int)> build_post = [&](int pre_left, int pre_right, int in_left, int in_right) {
        if (pre_left > pre_right) {    
            return;
        }

        char root = pre_seq[pre_left];
        int root_pos = in_left;

        while (root_pos <= in_right && in_seq[root_pos] != root) {
            root_pos++;
        }

        int left_size = root_pos - in_left;

        build_post(pre_left + 1, pre_left + left_size, in_left, root_pos - 1);
        build_post(pre_left + left_size + 1, pre_right, root_pos + 1, in_right);

        post_seq.push_back(root);
    };

    build_post(0, n - 1, 0, n - 1);

    printf("%s\n", post_seq.c_str());

    return 0;
}


/*
Description
二叉树的三种遍历都可以通过递归实现。
如果我们知道一棵二叉树的先序和中序序列，可以用递归的方法求后序遍历序列。



输入格式
两行，第一行一个字符串，表示树的先序遍历，第二行一个字符串，表示树的中序遍历。
树的结点一律用小写字母表示,且字符串长度不超过30。


输出格式
一个字符串，树的后序序列。


输入样例
abcde
bcade


输出样例
cbeda


*/
