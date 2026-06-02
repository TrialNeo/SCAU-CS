#include <queue>
#include "AVLTree.h"

// 前向声明辅助函数
unsigned _depth_imp(AVLTree::AVLNode node);
void _mirror_imp(AVLTree::AVLNode &root);

// 利用广度优先去计算，因为是AVL层数比较低
unsigned AVLTree::count_leaves() {
    if (!this->root) {
        return 0;
    }
    queue<AVLNode> q;
    q.push(this->root);
    AVLNode curr;
    unsigned count = 0;
    while (!q.empty()) {
        AVLNode curr = q.front();
        q.pop();
        if (curr->left != nullptr) {
            q.push(curr->left);
        }
        if (curr->right != nullptr) {
            q.push(curr->right);
        }
        if (!curr->left && !curr->right) {
            count++;
        }
    }
    return count;
}


// 递归计算树的深度
unsigned AVLTree::_depth_imp(const AVLTree::AVLNode node) {
    if (!node) {
        return 0;
    }
    unsigned left_depth = _depth_imp(node->left);
    unsigned right_depth = _depth_imp(node->right);
    return max(left_depth, right_depth) + 1;
}

unsigned AVLTree::depth() { return _depth_imp(this->root); }


// （6） 交换各结点的左右子树 应该说的是取一个镜像树，但是会破坏原来结构的，破坏就破坏吧
void AVLTree::mirror() { _mirror_imp(this->root); }


void _mirror_imp(AVLTree::AVLNode &root) {
    if (!root) {
        return;
    }
    AVLTree::AVLNode t = root->left;
    root->left = root->right;
    root->right = t;
    _mirror_imp(root->left);
    _mirror_imp(root->right);
}
