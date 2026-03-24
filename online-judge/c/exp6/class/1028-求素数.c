// Created by Github@TrialNeo(shenpanpro@gmail.com) 
// Created Time 2026/2/26.


// Description
//     输出2到200之间（包括2、200）的所有素数（注：要求1行1个素数，按由小到大的顺序输出）。
// 输入样例
//     （无）
// 输出样例
//     2
//     3
//     5
//     7
//     ……
//     199
#include <math.h>
#include <stdio.h>

char isPrime(int number) {
    //因为肯定有一半是偶数的，筛除一半会快很多；但是再排除了3、5之后筛选掉多少数据呢？？
    if (number != 2 && !(number % 2) || number != 3 && !(number % 3) || number != 5 && !(number % 5)) {
        return 0;
    }

    for (int i = 7; i < sqrt(number); ++i) {
        if (!(number % i)) {
            return 0;
        }
    }
    return 1;
}

int main(int argc, char *argv[]) {
    for (int i = 2; i <= 200; i++) {
        if (isPrime(i)) {
            printf("%d\n", i);
        }
    }
}
