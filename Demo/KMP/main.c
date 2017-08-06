#include <stdio.h>
#include <stdlib.h>
void get_next(char T[]);

int main()
{
    char t[] = "Hello World!";
    get_next(t);
    return 0;
}


void get_next(char T[]){
    printf("字符串T为：%s\n", T);
}
