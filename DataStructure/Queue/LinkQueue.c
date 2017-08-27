#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define OK 1
#define ERROR 0
#define TRUR 1
#define FALSE 0

typedef int Status;
typedef int QElemType;

/* 链表队列结点数据结构 */
typedef struct QNode
{
   QElemType data;
   struct QNode *next;
}QNode, *QueuePtr;

/* 队列链表数据结构 */
typedef struct
{
   QueuePtr front, rear;  /* 队头，队尾指针 */
}LinkQueue;

/* 1.队列的入队操作 */
Status EnQueue(LinkQueue *Q, QElemType e)
{
   QueuePtr s = (QueuePtr)malloc(sizeof(QNode));
   if(!s)
      exit(0);
   s->data = e;
   s->next = NULL;
   Q->rear->next = s;
   Q->rear = s; /* 把当前的s设置为队尾结点 */
   return OK;
}

/* 2.队列的出队操作 */
Status DeQueue(LinkQueue *Q, QElemType *e)
{
   QueuePtr p;
   if(Q->front == Q->rear)
      return ERROR; 
   /* 头结点不存储数据 */
   p = Q->front->next;
   *e = p->data;
   Q->front->next = p->next;
   if(p == Q->rear)
      Q->rear = Q->front;
   free(p);
   return OK;
}

int main()
{
   QNode node = {.next = NULL}; /* 定义头结点,链表队列指针初始化对头队尾指向头结点 */
   LinkQueue queue = {.front = &node, .rear = &node}; 
   QElemType data,num;
   srand(time(0));
   num = rand() % 20 + 1;
   for(int i = 0;i < num;i++)
   {
      data = rand() % 10000 + 1;
      if(EnQueue(&queue, data))
         printf("第%d个元素入队成功,data->%d\n", i + 1, data); 
      else
         printf("第%d个元素%d入队失败！", i + 1, data);
   }
   printf("入队完成!\n");
   num = 1;
   while(queue.front != queue.rear)
   {
      DeQueue(&queue, &data); 
      printf("第%d个元素出队成功,data->%d\n", num, data);
      num++;
   }
   printf("出队完成！\n");
}
