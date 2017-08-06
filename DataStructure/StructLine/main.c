#include <stdio.h>
#include <stdlib.h>

//线性表顺序存储结构
#define MAXSIZE 20 /* 存储空间初始分配量 */
typedef int ElemType;   /* ElemType类型根据实际情况而定，这里假定为int */
typedef struct
{
    ElemType data[MAXSIZE]; /* 数组存储数据元素，最大个数为MAXSIZE */
    int length; /* 线性表当前长度 */
}SqlList;

//对线性表进行操作
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status; /* Status是函数的类型，其值是函数的结果状态码，比如OK等 */

//获取指定位置的数据
Status GetElem(SqlList L, int i, ElemType *e){
    if(L.length == 0 || i < 1 || i > L.length)
        return ERROR;
    *e = L.data[i - 1];
    return OK;
}

//向线性表中指定位置插入数据
Status InsertList(SqlList *L,int i,ElemType e){
    if(L->length == MAXSIZE)   /*当线性表已满*/
        return ERROR;
    if(i < 1 || i > L->length+1)    /*当i不在范围内*/
        return ERROR;
    if(i <= L->length){ /*插入数据位置不在表尾*/
        for(int k = L->length - 1;k >= i-1;k--)
            L->data[k+1] = L->data[k];
    }
    L->data[i-1] = e;
    L->length++;

    return OK;
}

//删除线性表中指定位置的数据，并返回其值
Status RemoveList(SqlList *L,int i,ElemType *e){
    if(L->length == 0)  /*线性表为空*/
        return ERROR;
    if(i < 1 || i > L->length)  /* 要删除的位置不正确 */
    if(i < L->length)   /* 要删除的位置不为最后一个 */
    {
        for(int k = i;k < L->length;k ++)
            L->data[k-1] = L->data[k];
    }
    *e = L->data[i-1];
    L->data[i-1] = 0;
    L->length--;
    return OK;
}


int main(){
//    初始化线性表
    SqlList list;
    list.length = 10;
    for(int i=0;i<list.length;i++){
        list.data[i] = (i+1) * 100;
    }
    printf("当前线性长度为：%d\n",list.length);
    //1.插入数据

    printf("请输入要插入的数据和插入的位置：\n");
    ElemType value;
    int num;
    scanf("%d,%d", &value,&num);
    printf("你输入的数据为：%d,插入位置为：%d\n",value,num);
    if(InsertList(&list,num,value) == OK)
        printf("当前线性表长度为：%d\n", list.length);
    else
        printf("数据插入失败！\n");


    //2.获取数据
    int result;
    get:printf("请输入你要获取线性表数据的序号：\n");
    scanf("%d", &num);
    if(GetElem(list,num,&result) == OK)
        printf("线性表中序号为%d的数据为：%d\n",num,result);
    else{
        printf("你输入的序号有误！\n");
        goto get;
    }

    //3.删除数据
    int data;
    printf("请输入要删除数据的位置：\n");
    scanf("%d", &num);
    if(RemoveList(&list,num,&data) == OK){
        printf("删除的数据为：%d\n", data);
        printf("当前线性表长度为：%d",list.length);
    }else
        printf("数据删除失败！");

    return 0;
}
