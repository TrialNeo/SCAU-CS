// Created by Github@TrialNeo(shenpanpro@gmail.com) 
// Created Time 2026/3/2.

// 请写出下列程序的运行结果
#include<stdio.h>
int main( )
{   char   string[30]="How_are_you" ;
    char   *p=&string[0],   *p2=string+8;
    printf("%s,%s\n" , p , p2 ) ;
}


// #include <stdio.h>
//
// int main()
// {
//     printf("How_are_you,you");
// }