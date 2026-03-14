#include  <stdio.h>

void c1035() {
    //n=2,column = 2*n+1 = 5,row = column
    //row=1,1
    //row=2,3
    //row=3,5
    int n = 0;
    scanf("%d", &n);
    for (size_t row = 0; row <= n; row++) {
        for (size_t space = 0; space < n - row; space++) {
            putchar(' ');
        }
        for (size_t star = 0; star < 2 * row + 1; star++) {
            putchar('*');
        }
        putchar('\n');
    }

    for (size_t row = n; row > 0; row--) {
        for (size_t space = 0; space < n - (row-1); space++) {
            putchar(' ');
        }
        for (size_t star = 0; star < 2 * (row-1) + 1; star++) {
            putchar('*');
        }
        putchar('\n');
    }
}

//对着空格数量和*的数量和行指标的关系就行了，然后到中间层之后断开，虽然不会说把代码背下来，但是这个逻辑流程是可以通用的。
void c1035_2() {
    int row = 0;
    scanf("%d", &row);
    for (int i = 0; i < row+1; ++i) {
        //print space char
        for (int k = i; k < row; ++k) {
            putchar(' ');
        }
        //print * char
        for (int k = 0; k < 2 * i + 1; k++) {
            putchar('*');
        }
        putchar('\n');
    }
    for (int i = row-1; i >= 0; --i) {
        //print space char
        for (int k = i; k < row; ++k) {
            putchar(' ');
        }
        //print * char
        for (int k = 0; k < 2 * i + 1; k++) {
            putchar('*');
        }
        putchar('\n');
    }
}