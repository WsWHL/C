#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("------------------数组-------------------\n");
    int nums[10] = {0,1,2,3,4,5,6,7,8,9};
    char string[] = {'a','b','c','d','e','f'};
    char test[] = "Hello World!";
    printf("数组nums：%d\n", nums[3]);
    printf("数组string：%s\n",string);
    printf("字符串test：%s\n",test);


    return 0;
}
