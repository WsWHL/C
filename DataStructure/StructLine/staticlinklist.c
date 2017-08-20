#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 1000	/* 假设链表最大长度1000 */


typedef char ElemType;
typedef int Status;

typedef struct
{
	ElemType data;
	int cur;	/* 游标（cursor）,为0时表示无指向 */
} Component, StaticLinkList[MAXSIZE];

// 1.初始化
Status InitList(StaticLinkList space)
{
	for(int i = 0; i < MAXSIZE - 1; i++)
		space[i].cur = i + 1;
	space[MAXSIZE - 1].cur = 0;
	return OK;
}

int Malloc_SLL(StaticLinkList space)
{
	int i = space[0].cur;
	if(space[0].cur)
		space[0].cur = space[i].cur;

	return i;
}

int ListLength(StaticLinkList L)
{
	int j = 0;
	int i = MAXSIZE - 1;
	while(i)
	{
		i = L[i].cur;
		j++;
	}

	return j;
}

// 2.静态链表插入
Status InsertList(StaticLinkList L, int i, ElemType e)
{
	int j, k, l;
	k = MAXSIZE - 1;	/* k取最后一个元素的下标 */
	if(i < 1 || i > L[0].cur)
		return ERROR;
	j = Malloc_SLL(L);
	if(j)
	{
		L[j].data = e;
		for(l = 1; l < i - 1; l++)
			k = L[l].cur;
		L[j].cur = L[k].cur;
		L[k].cur = j;
		return OK;
	}
	return ERROR;
}

void Free_SSL(StaticLinkList space, int k)
{
	space[k].cur = space[0].cur;
	space[0].cur = k;
}

// 3.静态链表删除
Status DeleteList(StaticLinkList L, int i, ElemType *e)
{
	int j, k;
	if(i < 1 || i > L[0].cur)
		return ERROR;
	k = MAXSIZE - 1;
	for(j = 1; j <= i -1; j++)
		k = L[k].cur;
	j = L[k].cur;
	L[k].cur = L[j].cur;
	*e = L[j].data;
	Free_SSL(L, j);
	return OK;
}



void PrintData(StaticLinkList L)
{
	int i;
	i = L[MAXSIZE - 1].cur;
	for(int i = 1; i < L[0].cur; i++)
		printf("下标为%d的数据为：%c\n", i,	 L[i].data);	
	printf("备用链表第一个结点下标为：%d\n", L[0].cur);
}

int main()
{
	StaticLinkList list;
	if(InitList(list) == OK)
		printf("静态链表初始化成功！\n");
	else
		printf("静态连初始化化失败！\n");
	for(int i = 1;i <= 7;i++)
	{
		list[i].data = 64 + i;
		list[0].cur = i + 1;
	}
	printf("静态链表的长度为：%d\n", ListLength(list));
	//打印数据
	PrintData(list);
	//插入数据
	int num;
	char data;
	printf("请输入插入数据的位置和数据：");
	scanf("%d,%c", &num, &data);
	if(InsertList(list, num, data) == OK)
	{
		PrintData(list);
		printf("插入位置%d前面元素的cur为：%d\n", num, list[num - 1].cur);
		printf("数据插入成功！\n");
	}
	else
		printf("数据插入失败！\n");
	// 删除数据
	printf("请输入要删除数据的位置：");
	scanf("%d", &num);
	if(DeleteList(list, num, &data) == OK)
		printf("删除位置的数据为：%c\n", data);
	PrintData(list);			
	return 0;
}
