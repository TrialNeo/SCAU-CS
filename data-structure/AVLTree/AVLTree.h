#ifndef AVLTree

#include <algorithm>
#include <vector>
using namespace std;


class AVLTree {
public:
    typedef struct Node {
        Node *parent; // 父节点
        Node *left; // 左子树
        Node *right; // 右子树
        int key;
        int bf; // 平衡因子balance factor
        unsigned h; // 树深度
        Node(int k) : key(k), parent(nullptr), left(nullptr), right(nullptr), h(1) {}
    } *AVLNode;
    // -------------------------丑陋的分割线-------------------------------------
    vector<int> traversal_preorder(); // 基于递归的先序遍历
    vector<int> traversal_in(); // 基于递归的中序遍历
    vector<int> traversal_post(); // 基于递归的后序遍历

    vector<int> traversal_level(); // 基于队列的层次遍历

    vector<int> traversal_preorder_s(); // 基于栈的先序遍历
    vector<int> traversal_in_s(); // 基于栈的中序遍历
    vector<int> traversal_post_s(); // 基于栈的后序遍历
    // -------------------------华丽的分割线-------------------------------------
    bool insert(int key);
    bool search(int key);
    bool del(int key);
    // -------------------------随便的分割线-------------------------------------
    unsigned count_leaves();
    void mirror();
    // -------------------------简单的分割线-------------------------------------

    AVLTree() : root(nullptr) {}


private:
    AVLNode root;
    AVLNode rotate_right(const AVLNode &broken);
    AVLNode rotate_left(const AVLNode &broken);
    AVLNode rotate_left_right(const AVLNode &broken);
    AVLNode rotate_right_left(const AVLNode &broken);

    void re_BF(AVLNode &node);
};

#endif
