// Created by Github@TrialNeo(shenpanpro@gmail.com) 
// Created Time 2026/2/10.

#include <stdio.h>
unsigned gcd(unsigned x, unsigned y) {
    //这个其实是个递推公式omg a_n = a_(n-2) % a_(n-1)
    if (x < y) {
        unsigned temp = x;
        x = y;
        y = temp;
    }
    unsigned r = 0;
    while (1) {
        r = x % y;
        if (r == 0) {
            return y;
        }
        x = y;
        y = r;
    }
}

int main(){
	unsigned m,n ;
	scanf("%u%u",&m,&n);
	printf("%u\n",gcd(m,n));
}