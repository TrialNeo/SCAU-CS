#include <queue>
#include "AVLTree.h"

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


unsigned AVLTree::depth() { return this->root ? this->root->height : 0; }


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
