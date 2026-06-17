#include <cstdio>
#include <string>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    while (n--) {
        char buf[1100];
        scanf("%s", buf);
        string s(buf);
        string res;
        res.reserve(s.size());

        for (char c: s) {
            res.push_back(c);
            while (true) {
                int len = res.size();
                // 规则1：末尾三个字母相同 -> 去掉最后一个
                if (len >= 3 && res[len - 1] == res[len - 2] && res[len - 2] == res[len - 3]) {
                    res.pop_back();
                    continue;
                }
                // 规则2：末尾四个字母为 AABB 型 -> 去掉第二对里的一个（即最后一个）
                if (len >= 4 && res[len - 1] == res[len - 2] && // 第二对 BB
                    res[len - 3] == res[len - 4] && // 第一对 AA
                    res[len - 2] != res[len - 3]) { // A != B，避免和规则1冲突
                    res.pop_back();
                    continue;
                }
                break;
            }
        }
        printf("%s\n", res.c_str());
    }
    return 0;
}

/*
19084 万万没想到之聪明的编辑
时间限制:1000MS  代码长度限制:10KB
提交次数:0 通过次数:0

题型: 编程题   语言: G++;GCC;VC;JAVA;PYTHON

Description

字节跳动2019春招研发部分编程题
我叫王大锤，是一家出版社的编辑。我负责校对投稿来的英文稿件，这份工作非常烦人，因为每天都要去修正无数的拼写错误。
但是，优秀的人总能在平凡的工作中发现真理。我发现一个发现拼写错误的捷径：

1. 三个同样的字母连在一起，一定是拼写错误，去掉一个的就好啦：比如 helllo -> hello
2. 两对一样的字母（AABB型）连在一起，一定是拼写错误，去掉第二对的一个字母就好啦：比如 helloo -> hello
3. 上面的规则优先“从左到右”匹配，即如果是AABBCC，虽然AABB和BBCC都是错误拼写，应该优先考虑修复AABB，结果为AABCC

我特喵是个天才！我在蓝翔学过挖掘机和程序设计，按照这个原理写了一个自动校对器，工作效率从此起飞。
用不了多久，我就会出任CEO，当上董事长，迎娶白富美，走上人生巅峰，想想都有点小激动呢！
……
万万没想到，我被开除了，临走时老板对我说： “做人做事要兢兢业业、勤勤恳恳、本本分分，人要是行，
干一行行一行。一行行行行行；要是不行，干一行不行一行，一行不行行行不行。” 我现在整个人红红火火恍恍惚惚的……

请听题：请实现大锤的自动校对程序



输入格式
第一行包括一个数字N，表示本次用例包括多少个待校验的字符串。1<=N<=50

后面跟随N行，每行为一个待校验的字符串。字符串长度不超过1000。


输出格式
N行，每行包括一个被修复后的字符串。


输入样例
2
helloo
wooooooow


输出样例
hello
woow
*/
