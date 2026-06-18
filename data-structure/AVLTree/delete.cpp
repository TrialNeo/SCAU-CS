#include "AVLTree.h"

// del 删除某个节点，如果删除失败返回false，删除成功返回true
bool AVLTree::del(int key) {
    if (!this->root) {
        return false;
    }

    // 先找到要删除的节点，这里跟二分查找一样的，其实可以抽出来做一个函数解耦一下
    AVLNode curr = this->root;
    while (curr && curr->key != key) {
        if (key < curr->key) {
            curr = curr->left;
        } else {
            curr = curr->right;
        }
    }

    // 没找到
    if (!curr) {
        return false;
    }

    AVLNode parent = curr->parent;

    //  被删除节点是叶子节点
    if (!curr->left && !curr->right) {
        if (!parent) {
            this->root = nullptr;
        } else if (parent->left == curr) {
            parent->left = nullptr;
        } else {
            parent->right = nullptr;
        }
        delete curr;
        re_BF(parent);
        return true;
    }

    //  被删除节点只有一个子节点
    if (!curr->left || !curr->right) {
        AVLNode child = curr->left ? curr->left : curr->right;
        child->parent = parent;

        if (!parent) {
            this->root = child;
        } else if (parent->left == curr) {
            parent->left = child;
        } else {
            parent->right = child;
        }
        delete curr;
        re_BF(parent);
        return true;
    }

    AVLNode nxt = curr->right;
    while (nxt->left) {
        nxt = nxt->left;
    }

    curr->key = nxt->key;


    AVLNode s_parent = nxt->parent;
    if (s_parent->left == nxt) {
        s_parent->left = nxt->right;
    } else {
        s_parent->right = nxt->right;
    }
    if (nxt->right) {
        nxt->right->parent = s_parent;
    }

    delete nxt;
    re_BF(s_parent);
    return true;
}
