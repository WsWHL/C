#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num = 1;
    printf("打印9x9乘法表：\n");
    output:for(int row = 1;row <= 9;row++){
        for(int line = 1;line <= row;line++){
            printf("%d x %d = %d  ", line, row, row * line);
        }
        printf("\n");
    }
    num++;
    if(num == 2){
        printf("重新打印一遍：\n");
        goto output;
    }

    return 0;
}
