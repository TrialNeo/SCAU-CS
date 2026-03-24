// Created by Github@TrialNeo(shenpanpro@gmail.com) 
// Created Time 2026/2/13.

#include <stdio.h>
#include <math.h>
// 一个百万富翁遇到一个陌生人，陌生人找他谈了一个换钱的计划。该计划如下：我每天给你m元，
// 而你第一天只需给我一分钱。第二天我仍给你m元，你给我2分钱。第三天，我仍给你m元，
// 你给我4分钱。依次类推，你每天给我的钱是前一天的两倍，直到一个月(30天)。
// 百万富翁很高兴，欣然接受这个契约。现要求，编写一个程序，由键盘输入m，
// 计算多少天后，百万富翁开始亏钱。
int main(int argc, char *argv[]) {
    //注意单位 分 和 元，统一用分就行了
    //富豪给的钱是等比数列，陌生人给的钱是常数列
    float m = .0;
    int delta = 0;
    scanf("%f", &m);
    for (int days = 1; days++;) {
        delta = 100 * m * days - pow(2, days) + 1;
        if (delta < 0) {
            printf("%d", days);
            break;
        }
    }
}
