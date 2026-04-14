// 18104 练习使用多case解题
#include <iostream>
using namespace std;
#include <algorithm>
typedef long long ll; // 这里大坑来的

ll gcd(ll a, ll b) {
    if (a < b) {
        swap(a, b);
    }
    // 辗转相除法
    ll m = 0;
    while (true) {
        m = a % b;
        if (m == 0) {
            return b;
        }
        a = b;
        b = m;
    }
    return 0;
}

// https://cloud.tencent.com/developer/article/2617354 这篇文章告诉我们的a*b = lcd(a,b) * gcd(a,b)
ll lcd(ll a, ll b) {
    if (a == 0 || b == 0) { // 还有这个除0的大坑
        return 0;
    }

    return (a / gcd(a, b) * b);
}

int main(int argc, char const *argv[]) {
    ll a = 0, b = 0;
    for (size_t i = 1; i <= 3; i++) {
        ll n = 0;
        switch (i) {
            case 1:
                cin >> n;
                for (size_t i = 0; i < n; i++) {
                    cin >> a >> b;
                    cout << lcd(a, b) << '\n';
                }
                cout << "group 1 done" << '\n';
                break;
            case 2:
                while (true) {
                    cin >> a >> b;
                    if (!a && !b) { // 2个0
                        break;
                    }
                    cout << lcd(a, b) << '\n';
                }
                cout << "group 2 done" << '\n';
                break;
            case 3:
                while (cin >> a >> b) {
                    cout << lcd(a, b) << '\n';
                }
                cout << "group 3 done" << '\n';
                break;
            default:
                break;
        }
    }
    return 0;
}
/*
Description
    多CASE的问题在般有3种情形：（1）有一个数字开始表明CASE数目；（2）以特殊标志表示结束；（3）要求处理到最后一行。
现要求你在程序一次运行中，依次处理上述3种情况。

有三批测试数据，第1批测试数据，开头会以一个数字告之该批CASE数量，每一个CASE是两个正整数；
第1批测试数据结束后，紧接着是第2批数据，每一个CASE同样是两个正整数，第2批测试数据以两个0结束；
第2批测试数据结束后，紧接着是第3批数据，每一个CASE也是两个正整数，第3批测试数据一直到数据输入结束；

要求，每一个CASE，输出两数的最小公倍数
第1批测试数据处理完毕时，输出“group 1 done”
第2批测试数据处理完毕时，输出“group 2 done”
第3批测试数据处理完毕时，输出“group 3 done”

输入格式
    有三批测试数据，第1批测试数据，开头会以一个数字告之该批CASE数量，每一个CASE是两个正整数(最大2的31次方)；
第1批测试数据结束后，紧接着是第2批数据，每一个CASE同样是两个正整数，第2批测试数据以两个0结束；
第2批测试数据结束后，紧接着是第3批数据，每一个CASE也是两个正整数，第3批测试数据一直到数据输入结束；
输出格式
    要求，每一个CASE，输出两数的最小公倍数
    第1批测试数据处理完毕时，输出“group 1 done”
    第2批测试数据处理完毕时，输出“group 2 done”
    第3批测试数据处理完毕时，输出“group 3 done”
输入样例
    2
    6 10
    5 12
    8 16
    12 18
    8 4
    0 0
    4 5
    4 6

输出样例
    30
    60
    group 1 done
    16
    36
    8
    group 2 done
    20
    12
    group 3 done

*/
