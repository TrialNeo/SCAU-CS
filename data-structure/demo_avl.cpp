// ============================================
// AVL树 交互式演示程序
// ============================================
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <vector>
#include <limits>
#include <cmath>
#include "AVLTree.h"
using namespace std;

AVLTree tree;

void print_vec(const vector<int> &v, const string &label) {
    cout << "  " << label << ":  [";
    for (size_t i = 0; i < v.size(); ++i) {
        if (i) cout << ", ";
        cout << v[i];
    }
    cout << "]" << endl;
}

void clear_screen() { system("cls"); }

void pause() {
    cout << endl << "按回车键继续...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

int read_int(const string &prompt) {
    int val;
    while (true) {
        cout << prompt;
        if (cin >> val) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return val;
        }
        cout << "  [!] 请输入一个整数!" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

// 01 插入
void menu_insert() {
    clear_screen();
    cout << "=== [01] 插入数据 ===" << endl;
    cout << "请输入一组整数（空格隔开）:" << endl;
    cout << "> ";
    string line;
    getline(cin, line);
    stringstream ss(line);
    int k, cnt = 0, dup = 0;
    while (ss >> k) {
        if (tree.insert(k)) cnt++;
        else dup++;
    }
    cout << endl << "完成: 新增 " << cnt << " 个, 跳过 " << dup << " 个" << endl;
    auto in = tree.traversal_in();
    if (!in.empty()) print_vec(in, "中序遍历");
    else cout << "  树为空" << endl;
    pause();
}

// 02 删除
void menu_delete() {
    clear_screen();
    cout << "=== [02] 删除数据 ===" << endl;
    if (tree.traversal_in().empty()) {
        cout << "  树为空!" << endl; pause(); return;
    }
    int key = read_int("输入要删除的 key: ");
    if (tree.del(key)) {
        cout << "  [OK] " << key << " 删除成功" << endl;
        print_vec(tree.traversal_in(), "中序遍历");
    } else {
        cout << "  [失败] " << key << " 不存在!" << endl;
    }
    pause();
}

// 03 修改
void menu_modify() {
    clear_screen();
    cout << "=== [03] 修改数据 ===" << endl;
    if (tree.traversal_in().empty()) {
        cout << "  树为空!" << endl; pause(); return;
    }
    int old_key = read_int("输入要修改的 key: ");
    if (!tree.search(old_key)) {
        cout << "  [失败] " << old_key << " 不存在!" << endl; pause(); return;
    }
    int new_key = read_int("输入新的 key: ");
    if (tree.search(new_key)) {
        cout << "  [失败] " << new_key << " 已存在!" << endl; pause(); return;
    }
    tree.del(old_key); tree.insert(new_key);
    cout << "  [OK] " << old_key << " -> " << new_key << " 修改成功" << endl;
    print_vec(tree.traversal_in(), "中序遍历");
    pause();
}

// 04 先序
void menu_preorder() {
    clear_screen();
    cout << "=== [04] 先序遍历 ===" << endl;
    auto v = tree.traversal_preorder();
    if (v.empty()) { cout << "  树为空" << endl; pause(); return; }
    print_vec(v, "先序(递归)");
    auto vs = tree.traversal_preorder_s();
    print_vec(vs, "先序(栈)");
    cout << "  递归 vs 栈: " << (v == vs ? "一致" : "不一致!") << endl;
    pause();
}

// 05 中序
void menu_inorder() {
    clear_screen();
    cout << "=== [05] 中序遍历 ===" << endl;
    auto v = tree.traversal_in();
    if (v.empty()) { cout << "  树为空" << endl; pause(); return; }
    print_vec(v, "中序(递归)");
    auto vs = tree.traversal_in_s();
    print_vec(vs, "中序(栈)");
    cout << "  递归 vs 栈: " << (v == vs ? "一致" : "不一致!") << endl;
    pause();
}

// 06 后序
void menu_postorder() {
    clear_screen();
    cout << "=== [06] 后序遍历 ===" << endl;
    auto v = tree.traversal_post();
    if (v.empty()) { cout << "  树为空" << endl; pause(); return; }
    print_vec(v, "后序(递归)");
    auto vs = tree.traversal_post_s();
    print_vec(vs, "后序(栈)");
    cout << "  递归 vs 栈: " << (v == vs ? "一致" : "不一致!") << endl;
    pause();
}

// 07 层次
void menu_levelorder() {
    clear_screen();
    cout << "=== [07] 层次遍历 ===" << endl;
    auto v = tree.traversal_level();
    if (v.empty()) { cout << "  树为空" << endl; pause(); return; }
    print_vec(v, "层次遍历");
    pause();
}

// 08 查找
void menu_search() {
    clear_screen();
    cout << "=== [08] 查找关键字 ===" << endl;
    int key = read_int("输入要查找的 key: ");
    cout << "  key=" << key << ": " << (tree.search(key) ? "已找到" : "未找到") << endl;
    pause();
}

// 09 镜像
void menu_mirror() {
    clear_screen();
    cout << "=== [09] 交换左右子树 ===" << endl;
    if (tree.traversal_in().empty()) {
        cout << "  树为空!" << endl; pause(); return;
    }
    print_vec(tree.traversal_in(), "交换前");
    tree.mirror();
    print_vec(tree.traversal_in(), "交换后");
    cout << "  完成! (再次选择 09 可恢复)" << endl;
    pause();
}

// 10 深度
void menu_depth() {
    clear_screen();
    cout << "=== [10] 查看树深度 ===" << endl;
    unsigned d = tree.depth();
    cout << "  深度: " << d << endl;
    if (d > 0) {
        unsigned n = tree.traversal_in().size();
        cout << "  节点数: " << n << ", 理论上限: " << (int)ceil(1.45 * log2(n + 1)) << endl;
    }
    pause();
}

// 11 叶子
void menu_leaves() {
    clear_screen();
    cout << "=== [11] 查看叶子节点数 ===" << endl;
    cout << "  叶子数: " << tree.count_leaves() << endl;
    pause();
}

// 菜单
void show_menu() {
    clear_screen();
    cout << "========================================" << endl;
    cout << "          AVL树 交互式演示" << endl;
    cout << "========================================" << endl;
    cout << endl;
    cout << "  [01]  插入数据" << endl;
    cout << "  [02]  删除数据" << endl;
    cout << "  [03]  修改数据" << endl;
    cout << "  [04]  先序遍历" << endl;
    cout << "  [05]  中序遍历" << endl;
    cout << "  [06]  后序遍历" << endl;
    cout << "  [07]  层次遍历" << endl;
    cout << "  [08]  查找关键字" << endl;
    cout << "  [09]  交换左右子树" << endl;
    cout << "  [10]  查看树深度" << endl;
    cout << "  [11]  查看叶子节点数" << endl;
    cout << endl;
    cout << "  [00]  退出" << endl;
    cout << endl;
}

int main() {
    while (true) {
        show_menu();
        int choice = read_int("请输入选项 [00-11]: ");
        switch (choice) {
            case 0:  cout << endl << "再见!" << endl; return 0;
            case 1:  menu_insert();     break;
            case 2:  menu_delete();     break;
            case 3:  menu_modify();     break;
            case 4:  menu_preorder();   break;
            case 5:  menu_inorder();    break;
            case 6:  menu_postorder();  break;
            case 7:  menu_levelorder(); break;
            case 8:  menu_search();     break;
            case 9:  menu_mirror();     break;
            case 10: menu_depth();      break;
            case 11: menu_leaves();     break;
            default: cout << "  [X] 无效选项!" << endl; pause();
        }
    }
}