#include "AVLTree.h"


// LL-type的重新平衡，右旋操作，看那个csdn的图就很好写了
AVLTree::AVLNode AVLTree::rotate_right(const AVLTree::AVLNode &broken) {
    if (broken == nullptr || broken->left == nullptr) {
        return nullptr;
    }
    AVLNode left = broken->left;
    AVLNode parent = broken->parent;

    broken->left = left->right;
    if (broken->left) {
        broken->left->parent = broken;
    }
    left->right = broken;
    broken->parent = left;
    left->parent = parent;

    if (parent) {
        if (parent->left == broken) {
            parent->left = left;
        } else {
            parent->right = left;
        }
    }

    update_height(broken);
    update_height(left);

    return left;
}

// RR-type 左旋
AVLTree::AVLNode AVLTree::rotate_left(const AVLTree::AVLNode &broken) {
    if (broken == nullptr || broken->right == nullptr) {
        return nullptr;
    }
    AVLNode r = broken->right;
    AVLNode parent = broken->parent;

    broken->right = r->left;
    if (broken->right) {
        broken->right->parent = broken;
    }

    r->left = broken;
    broken->parent = r;
    r->parent = parent;

    if (parent) {
        if (parent->left == broken) {
            parent->left = r;
        } else {
            parent->right = r;
        }
    }

    update_height(broken);
    update_height(r);

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


void AVLTree::update_height(AVLNode node) {
    unsigned left_h = node->left ? node->left->height : 0;
    unsigned right_h = node->right ? node->right->height : 0;
    node->height = max(left_h, right_h) + 1;
}

void AVLTree::re_BF(AVLNode &node) {
    while (node) {
        update_height(node);
        node->bf = (node->right ? node->right->height : 0)
                 - (node->left ? node->left->height : 0);

        if (node->bf < -1) {
            if (node->left && node->left->bf <= 0) {
                node = rotate_right(node);
            } else if (node->left) {
                node = rotate_left_right(node);
            }
        } else if (node->bf > 1) {
            if (node->right && node->right->bf >= 0) {
                node = rotate_left(node);
            } else if (node->right) {
                node = rotate_right_left(node);
            }
        }
        if (!node->parent) {
            this->root = node;
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

    while (curr) {
        p = curr;
        if (key < curr->key) {
            curr = curr->left;
        } else if (key > curr->key) {
            curr = curr->right;
        } else {
            return false;
        }
    }

    AVLNode new_node = new Node(key);
    new_node->parent = p;

    if (key < p->key) {
        p->left = new_node;
    } else {
        p->right = new_node;
    }

    re_BF(new_node);

    return true;
}
