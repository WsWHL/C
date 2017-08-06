#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("-------------------1.运算符---------------\n");
    int num = 10, n = 2, result = 0;
    result += num;
    printf("num + result = %d\n", result);
    result -= n;
    printf("result - n = %d\n", result);
    result *= n;
    printf("result x n = %d\n", result);
    result %= num;
    printf("result %% num = %d\n", result);

    printf("--------------------2.三目运算-----------------\n");
    printf("result = %d, num = %d\n", result,num);
    const int* rst =result == num ? result : num;
    printf("%d", rst);


    return 0;
}
