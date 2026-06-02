#include "AVLTree.h"


// LL-type的重新平衡，右旋操作，看那个csdn的图就很好写了
AVLTree::AVLNode AVLTree::rotate_right(const AVLTree::AVLNode &broken) {
    if (broken == nullptr || broken->left == nullptr) {
        return nullptr;
    }
    // 做一下保存操作
    AVLNode left = broken->left;
    AVLNode parent = broken->parent;

    // 右旋
    broken->left = left->right;
    if (broken->left) {
        broken->left->parent = broken;
    }
    left->right = broken;
    broken->parent = left;
    left->parent = parent;

    // 更新父节点的子指针
    if (parent) {
        if (parent->left == broken) {
            parent->left = left;
        } else {
            parent->right = left;
        }
    }

    return left;
}

// RR-type 左旋
AVLTree::AVLNode AVLTree::rotate_left(const AVLTree::AVLNode &broken) {
    if (broken == nullptr || broken->right == nullptr) {
        return nullptr;
    }
    // 备份
    AVLNode r = broken->right;
    AVLNode parent = broken->parent;

    // 左旋操作
    broken->right = r->left;
    if (broken->right) {
        broken->right->parent = broken;
    }

    r->left = broken;
    broken->parent = r;
    r->parent = parent;

    // 更新父节点的子指针
    if (parent) {
        if (parent->left == broken) {
            parent->left = r;
        } else {
            parent->right = r;
        }
    }

    return r;
}
// LR-type
AVLTree::AVLNode AVLTree::rotate_left_right(const AVLTree::AVLNode &broken) {
    if (broken == nullptr || broken->left == nullptr) {
        return nullptr;
    }
    broken->left = rotate_left(broken->left);
    return rotate_right(broken);
}

// RL-type
AVLTree::AVLNode AVLTree::rotate_right_left(const AVLTree::AVLNode &broken) {
    if (broken == nullptr || broken->right == nullptr) {
        return nullptr;
    }
    broken->right = rotate_right(broken->right);
    return rotate_left(broken);
}


void AVLTree::re_BF(AVLNode &node) {
    while (node) {
        // 更新Balance Factor
        int left_height = this->_depth_imp(node->left);
        int right_height = this->_depth_imp(node->right);
        node->bf = right_height - left_height;
        // 需要旋转
        if (node->bf < -1) { // 左子树过深
            if (node->left && node->left->bf <= 0) {
                node = rotate_right(node); // LL-type
            } else if (node->left) {
                node = rotate_left_right(node); // LR-type
            }
        } else if (node->bf > 1) { // 右子树过深
            if (node->right && node->right->bf >= 0) {
                node = rotate_left(node); // RR-type
            } else if (node->right) {
                node = rotate_right_left(node); // RL-type
            }
        }
        // 向上更新父节点
        if (!node->parent) {
            this->root = node; // 更新root
        }
        node = node->parent;
    }
}

// 插入操作
bool AVLTree::insert(int key) {
    if (!this->root) {
        this->root = new Node(key);
        return true;
    }
    AVLNode curr = this->root, p = nullptr;

    // 找到插入位置
    while (curr) {
        p = curr;
        if (key < curr->key) {
            curr = curr->left;
        } else if (key > curr->key) {
            curr = curr->right;
        } else {
            // 已经存在相同key，不插入
            return false;
        }
    }

    // 创建新节点
    AVLNode new_node = new Node(key);
    new_node->parent = p;

    if (key < p->key) {
        p->left = new_node;
    } else {
        p->right = new_node;
    }

    // 插入后沿父节点向上更新balance factor
    re_BF(new_node);

    return true;
}
