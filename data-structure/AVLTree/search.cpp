#include "AVLTree.h"


// 二分查找
bool AVLTree::search(int key) {
    AVLNode curr = this->root;
    bool b = false; // 做成统一出口吧

    while (curr) {
        if (curr->key == key) {
            b = true;
            break;
        }
        if (curr->key > key) {
            curr = curr->left;
        } else {
            curr = curr->right;
        }
    }
    return b;
}
