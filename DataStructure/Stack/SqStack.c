#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 5

//栈的顺序存储结构
typedef int Status;
typedef int SElemType;
typedef struct
{
	SElemType data[MAXSIZE];
	int top;	/* 用于栈顶的指针 */
}SqStack;


/* 插入元素e为新的栈顶元素 */
Status Push(SqStack *s, SElemType e)
{
	if(s->top == MAXSIZE - 1)
		return ERROR;
	s->top++;
	s->data[s->top] = e;	/* 栈顶指针增加一 */
	return OK;	/* 将新插入元素赋值给栈顶空间 */
}

/* 若栈不为空，则删除S栈顶元素，用e返回其值 */
Status Pop(SqStack *s, SElemType *e)
{
	if(s->top == -1)
		return ERROR;
	*e = s->data[s->top];
	s->top--;
	return OK;
}

int main()
{
	SqStack s = {.top = -1};
	SElemType num;
	Status status = OK;
	while(s.top < MAXSIZE - 1 && status == OK)
	{
		printf("请输入要入栈的数据：");
		scanf("%d", &num);
		status = Push(&s, num);
	}
	printf("数据入栈成功！\n");
	printf("数据开始出栈...\n");
	while(s.top > -1 && s.top < MAXSIZE)
	{
		if(Pop(&s, &num) == OK)
		{
			printf("第%d个出栈元素->%d\n", (MAXSIZE - s.top - 1), num);
		}			
	}
	printf("所有元素出栈完毕！\n");
}

