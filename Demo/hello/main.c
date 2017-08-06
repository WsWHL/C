#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Hello world!\n");
    printf("递归方法：\n");
//    int result = fun(50);
//    printf(result);
switch(1){
case 1:
    printf("yes");
    break;
case 2:
    printf("no");
    break;
}
    return 0;
}

int fun(int num){
    if(num < 2){
        return 1;
    }
    return fun(num - 1) + fun(num - 2);
}
