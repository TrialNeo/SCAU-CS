// 这个是使用栈进行的遍历

#include <stack>
#include "AVLTree.h"
#define _left 0 // 下一步访问左子树
#define _right 1 // 下一步访问右子树
#define _leave 2 // 下一步弹出
/*

// 利用双栈实现：先序遍历
vector<int> AVLTree::traversal_preorder_s() {
    vector<int> arr;
    AVLNode curr;
    stack<AVLNode> s_node;
    stack<char> s_op;
    s_node.push(this->root);
    s_op.push(_left);
    while (!s_node.empty()) {
        curr = s_node.top();
        // 查看下一步的操作
        char op = s_op.top();
        s_op.pop();
        switch (op) {
            case _left:
                arr.push_back(curr->key); // 因为是先序遍历直接做这个操作就行了
                s_op.push(_right); // 当前节点下一步要访问右子树
                if (curr->left != nullptr) { // 下一个要访问的节点 是 左子树
                    s_node.push(curr->left);
                    s_op.push(_left); // 当前节点的左子树下一步 要 访问 左子树
                }
                break;
            case _right:
                s_op.push(_leave); // 当前节点下一步应该被弹出
                if (curr->right != nullptr) { // 下一个要访问的节点 是 右子树
                    s_node.push(curr->right);
                    s_op.push(_left);
                }
                break;
            case _leave:
                s_node.pop(); // 弹出
                break;
        }
    }
    return arr;
}
 */
// 利用双栈实现：中序遍历
vector<int> AVLTree::traversal_in_s() {
    vector<int> arr;
    AVLNode curr;
    stack<AVLNode> s_node;
    stack<char> s_op;
    s_node.push(this->root);
    s_op.push(_left);
    while (!s_node.empty()) {
        curr = s_node.top();
        // 查看下一步的操作
        char op = s_op.top();
        s_op.pop();
        switch (op) {
            case _left:
                s_op.push(_right); // 当前节点下一步要访问右子树
                if (curr->left != nullptr) { // 下一个要访问的节点 是 左子树
                    s_node.push(curr->left);
                    s_op.push(_left); // 当前节点的左子树下一步 要 访问 左子树
                }
                break;
            case _right:
                arr.push_back(curr->key); // 因为是先序遍历直接做这个操作就行了
                s_op.push(_leave); // 当前节点下一步应该被弹出
                if (curr->right != nullptr) { // 下一个要访问的节点 是 右子树
                    s_node.push(curr->right);
                    s_op.push(_left);
                }
                break;
            case _leave:
                s_node.pop(); // 弹出
                break;
        }
    }
    return arr;
}

// 利用双栈实现：后序遍历
vector<int> AVLTree::traversal_post_s() {
    vector<int> arr;
    AVLNode curr;
    stack<AVLNode> s_node;
    stack<char> s_op;
    s_node.push(this->root);
    s_op.push(_left);
    while (!s_node.empty()) {
        curr = s_node.top();
        // 查看下一步的操作
        char op = s_op.top();
        s_op.pop();
        switch (op) {
            case _left:
                s_op.push(_right); // 当前节点下一步要访问右子树
                if (curr->left != nullptr) { // 下一个要访问的节点 是 左子树
                    s_node.push(curr->left);
                    s_op.push(_left); // 当前节点的左子树下一步 要 访问 左子树
                }
                break;
            case _right:
                s_op.push(_leave); // 当前节点下一步应该被弹出
                if (curr->right != nullptr) { // 下一个要访问的节点 是 右子树
                    s_node.push(curr->right);
                    s_op.push(_left);
                }
                break;
            case _leave:
                arr.push_back(curr->key); // 因为是先序遍历直接做这个操作就行了
                s_node.pop(); // 弹出
                break;
        }
    }
    return arr;
}


// 单栈先序遍历
vector<int> AVLTree::traversal_preorder_s() {
    AVLNode curr = this->root;
    stack<AVLNode> s_node;
    vector<int> arr;
    s_node.push(this->root);
    while (!s_node.empty()) {
        curr = s_node.top();
        s_node.pop();
        arr.push_back(curr->key);
        // 这里是利用栈的先进后出的特点，先访问的是左子树那么应该后面入栈，后访问的是右子树应该先入栈。
        // 然后下一次拿出来就是我们要访问的节点了，这个非常简洁
        if (curr->right != nullptr) {
            s_node.push(curr->right);
        }
        if (curr->left != nullptr) {
            s_node.push(curr->left);
        }
    }
    return arr;
}
/*
// 单栈中序遍历
vector<int> AVLTree::traversal_in_s() {
    AVLNode curr = this->root;
    stack<AVLNode> s_node;
    vector<int> arr;
    s_node.push(this->root->left);
    while (!s_node.empty()) {
        curr = s_node.top();
        s_node.pop();
        arr.push_back(curr->key);

        if (curr->right != nullptr) {
            s_node.push(curr->right);
        }
        if (curr->left != nullptr) {
            s_node.push(curr->left);
        }
    }
    return arr;
}

// 单栈后序遍历
vector<int> AVLTree::traversal_post_s() {
    AVLNode curr = this->root;
    stack<AVLNode> s_node;
    vector<int> arr;
    while (!s_node.empty()) {
        curr = s_node.top();
        s_node.pop();

        if (curr->right != nullptr) {
            s_node.push(curr->right);
        }
        if (curr->left != nullptr) {
            s_node.push(curr->left);
        }
        arr.push_back(curr->key);
    }
    return arr;
}
 */
