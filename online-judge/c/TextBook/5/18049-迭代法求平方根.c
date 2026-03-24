//18049 迭代法求平方根
//使用迭代法求a的平方根。求平方根的迭代公式如下，要求计算到相邻两次求出的x的差的绝对值小于1E-5时停止，结果显示4位小数

#include <math.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    double x_np1 = 0,
            x_n = 0; //这个初始化可以随便的，根据但是取哪个值收敛得最快呢？？
    const double epsilon = 1e-5;
    double a = 0;
    scanf("%lf", &a);
    // 如果是0直接开出去得了
    if (a == 0 || a == 1) {
        printf("%.4f", (float) a);
        return 0;
    }
    if (a > 0 && a < 1) {
        x_n = 1;
    } else {
        x_n = a / 2;
    }
    //就是一个递推公式hh，直接往里面填数据就行了
    x_np1 = 0.5 * (x_n + a / x_n);
    while (fabs(x_np1 - x_n) >= epsilon) {
        x_n = x_np1;
        x_np1 = 0.5 * (x_n + a / x_n);
    }
    printf("%.4f", x_np1);
    return 0;
}
