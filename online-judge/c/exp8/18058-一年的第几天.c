// Created by Github@TrialNeo(shenpanpro@gmail.com) 
// Created Time 2026/2/27.


/*
Description
    定义一个结构体类型表示日期类型（包括年、月、日）。程序中定义一个日期类型的变量，输入该日期的年、月、日，
计算并输出该日期是一年的第几天。
输入格式
    年月日，格式如样例
输出格式
    该年的第几天
输入样例
    2015-1-1
输出样例
    1
*/


#include <stdio.h>

struct DATE {
    unsigned year;
    unsigned month;
    unsigned day;
};

unsigned days(struct DATE date) {
    unsigned day_count = date.day;
    //利用fall-through特性，，，其他语言写起来比这个舒服多了
    for (unsigned i = 1; i < date.month; i++) {
        switch (i) {
            case 2:
                //判断闰年还是平年
                if (!(date.year % 400) || !(date.year % 4) && date.year % 100) {
                    day_count += 29;
                } else {
                    day_count += 28;
                }
                break;
            case 1: //这里肯定用不到12的，需要一年有13个月才能这样玩，就算是12月 这个月还没满嘛
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                day_count += 31;
                break;
            default:
                day_count += 30;
                break;
        }
    }
    return day_count;
}

int main()
{
    struct DATE d;
    scanf("%d-%d-%d", &d.year, &d.month, &d.day);
    printf("%d", days(d));
}