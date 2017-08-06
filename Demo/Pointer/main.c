#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("————————————————指针————————————————\n");
    int var1 = 25;  /*实际变量声明*/
    char var2[20];
    int *ip;        /*指针变量声明*/

    ip = &var1;     /*在指针变量中存储var1变量的内存地址*/

    printf("var1变量的内存地址为：%p\n", &var1);
    printf("var2变量的内存地址为：%p\n", &var2);
    printf("指针变量ip中存的地址为：%p\n", ip);
    printf("指针变量的值为：%d\n", *ip);

    return 0;
}
