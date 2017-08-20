#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status;
/* 链栈存储结构 */
typedef int SElemType;
typedef struct StackNode
{
	SElemType data;
	struct StackNode *next;
}StackNode, *LinkStackPtr;

typedef struct LinkStack
{
	LinkStackPtr top;
	int count;
}LinkStack;

/* 插入元素e为新的栈顶元素 */
Status Push(LinkStack *S, SElemType e)
{
	LinkStackPtr s = (LinkStackPtr)malloc(sizeof(StackNode));
	s->data = e;
	s->next = S->top;	/* 把当前栈顶元素赋值给新结点作为直接后继 */
	S->top = s;
	S->count++;
	return OK;
}

Status StackEmpty(LinkStack S)
{
	if(S.top == NULL && S.count == -1)
		return OK;
	return ERROR;
}

/* 将栈顶元素删除并用e返回其值 */
Status Pop(LinkStack *S, SElemType *e)
{
	LinkStackPtr p;
	if(StackEmpty(*S))
		return ERROR;
	*e = S->top->data;
	p = S->top;
	S->top = S->top->next;
	S->count--;
	free(p);
	return OK;
}

int main()
{
	LinkStack S = {.top = NULL,.count = -1};
	srand(time(0));
	SElemType num;
	int count;
	index:count = rand() % 20 + 1;
	if(count <= 0)
		goto index;
	for(int i = 0;i < count;i++)
	{
		num = rand() % 1000 + 1;
		Push(&S, num);
	}
	printf("总共%d随机数入栈成功!\n", S.count + 1);
	printf("链栈元素开始出栈...\n");
	while(S.count > -1)
	{
		Pop(&S, &num);
		printf("第%d个出栈的元素为->%d\n", (count - S.count - 1), num);
	}
	printf("所有随机元素出栈完毕！\n");
}
