#include <queue>
#include <vector>
#include "AVLTree.h"

// 前向声明辅助函数
void _traversal_preorder_impl(const AVLTree::AVLNode &root, vector<int> &arr);
void _traversal_in_impl(const AVLTree::AVLNode &root, vector<int> &arr);
void _traversal_post_impl(const AVLTree::AVLNode &root, vector<int> &arr);

// 先序遍历，遍历之后返回一个数组，之后再打印吧，通用一点
vector<int> AVLTree::traversal_preorder() {
    vector<int> arr;
    _traversal_preorder_impl(this->root, arr);
    return arr;
}

// 先序遍历，内部实现
void _traversal_preorder_impl(const AVLTree::AVLNode &root, vector<int> &arr) {
    if (root == nullptr) {
        return;
    }
    arr.push_back(root->key);
    _traversal_preorder_impl(root->left, arr);
    _traversal_preorder_impl(root->right, arr);
}


// 中序遍历，遍历之后返回一个数组
vector<int> AVLTree::traversal_in() {
    vector<int> arr;
    _traversal_in_impl(this->root, arr);
    return arr;
}

// 中序遍历，内部实现
void _traversal_in_impl(const AVLTree::AVLNode &root, vector<int> &arr) {
    if (root == nullptr) {
        return;
    }
    _traversal_in_impl(root->left, arr);
    arr.push_back(root->key);
    _traversal_in_impl(root->right, arr);
}


// 后序遍历，遍历之后返回一个数组
vector<int> AVLTree::traversal_post() {
    vector<int> arr;
    _traversal_post_impl(this->root, arr);
    return arr;
}

// 后序遍历，内部实现
void _traversal_post_impl(const AVLTree::AVLNode &root, vector<int> &arr) {
    if (root == nullptr) {
        return;
    }
    _traversal_post_impl(root->left, arr);
    _traversal_post_impl(root->right, arr);
    arr.push_back(root->key);
}


// 层次遍历，借助队列
vector<int> AVLTree::traversal_level() {
    if (this->root == nullptr) {
        return {};
    }
    vector<int> arr;
    queue<AVLNode> q;
    q.push(this->root);

    while (!q.empty()) {
        AVLNode curr = q.front();
        q.pop();
        arr.push_back(curr->key);
        if (curr->left != nullptr) {
            q.push(curr->left);
        }
        if (curr->right != nullptr) {
            q.push(curr->right);
        }
    }

    return arr;
}
