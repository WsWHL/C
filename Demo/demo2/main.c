#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("-----------------1.自动类型转换----------------\n");
    int num = 5;
    char ch = 'a';
    float price = 5.24;
    double dec = 5.9999997;
    printf("num = %d\n", num);

    printf("ch = %c\n", ch);
    printf("price = %f\n", price);
    printf("dec = %f\n", dec);
    num = ch;
    printf("字符自动转整形：%d\n", num);
    for(int i = 0;i < 7;i++){
        ch += i;
        num = ch;
        printf("字符运算：%c = %d\n", ch,num);
    }

    printf("----------------2.强类型转换-------------------\n");
    printf("dec的整数部分为：%d", (int)dec);

    return 0;
}
