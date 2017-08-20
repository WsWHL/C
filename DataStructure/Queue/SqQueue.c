#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20

/* 队列的顺序存储结构，循环队列 */
typedef int Status;
typedef int QElemType;
typedef struct
{
	QElemType data[MAXSIZE];
	int front;	/* 头指针 */
	int rear;	/* 尾指针 */
}SqQueue;

/* 初始化空队列 */
Status InitQueue(SqQueue *Q)
{
	Q->front = 0;
	Q->rear = 0;
	return OK;
}

/* 循环队列求队列长度 */
int QueueLength(SqQueue Q)
{
	return (Q.rear - Q.front + MAXSIZE) % MAXSIZE;
}

/* 循环队列入队列操作 */
Status EnQueue(SqQueue *Q, QElemType e)
{
	if((Q->rear + 1) % MAXSIZE == Q->front)	/* 队列满 */
		return ERROR;
	Q->data[Q->rear] = e;
	Q->rear = (Q->rear + 1) % MAXSIZE;	/* rear指针向后移一位 */
	return OK;
}

/* 循环队列出队 */
Status DeQueue(SqQueue *Q, QElemType *e)
{
	if(Q->front == Q->rear)	/* 空队列 */
		return ERROR;
	*e = Q->data[Q->front];
	Q->front = (Q->front + 1) % MAXSIZE;
	return OK;
}

int main()
{
	SqQueue queue;
	InitQueue(&queue);
	QElemType data;
	srand(time(0));
	Status status = OK;
	printf("开始入队列...\n");
	int count = 0;
	while(QueueLength(queue) < MAXSIZE - 1 && status == OK)
	{
		data = rand() % 10000 + 1;
		status = EnQueue(&queue, data);
		printf("第%d个入队元素为->%d\n", ++count, data);
	}
	printf("入队完毕！\n");
	printf("开始出队列...\n");
	count = 0;
	while(QueueLength(queue) > 0 && status == OK)
	{
		status = DeQueue(&queue, &data);
		printf("第%d个出队列的元素为->%d\n", ++count, data);
	}
	printf("出队完毕！\n");
}
