// Created by Github@TrialNeo(shenpanpro@gmail.com) 
// Created Time 2026/3/14.

#include <stdio.h>
#include <stdlib.h>
int main()
{
    double a,b,c;
    char op;
    scanf("%lf%c%lf",&a,&op,&b );
    switch (op)
    {
        case  '+':
            c=  a+ b;
            break;
        case  '-':
            c = a-b;
            break;
        case  '*':
            c = a*b;
            break;
        case  '/':
            c = a/b;
            break;
        default:
            printf("error");
            return 0;
    }
    printf("result=%.2lf", c);
    return 0;
}