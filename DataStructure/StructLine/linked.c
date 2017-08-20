#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int ElemType;
typedef int Status;
typedef struct Node
{
    ElemType data;
    struct Node *next;
}Node, *LinkList;
//typedef struct Node *LinkList;

// init , add to tail
Status CreateListTail(LinkList *L, int n)
{
	LinkList p, r;
	int i;
	srand(time(0));
	*L = (LinkList)malloc(sizeof(Node));
	r = *L;
	for(i = 0; i < n; i++)
	{
		p = (LinkList)malloc(sizeof(Node));
		p->data = rand() % 1000 + 1;
		r->next = p;
		r = p;
	}
	r->next = NULL;

	return OK;
}

//init , add to head
Status CreateListHead(LinkList *L, int n)
{
	LinkList p;
	srand(time(0));
	*L = (LinkList)malloc(sizeof(Node));
	(*L)->next = NULL;
	for(int i = 0; i < n; i++)
	{
		p = (LinkList)malloc(sizeof(Node));
		p->data = rand() % 1000 + 1;
		p->next = (*L)->next;
		(*L)->next = p;
	}

	return OK;
}

// insert
Status ListInsert(LinkList *L,int i,ElemType e)
{
	int j;
	LinkList p,s;
	p = *L;
	j = 1;
	while(p && j < i)
	{
		p = p->next;
		++j;
	}
	if(!p || j > i)
		return ERROR;
	s = (LinkList)malloc(sizeof(Node));
	s->data = e;
	s->next = p->next;
	p->next = s;
	(*L)->data += 1; 

	return OK;
}


// get
Status GetElem(LinkList L, int i, ElemType *e)
{
	int j;
	LinkList p;
	p = L->next;
	j = 1;
	while(p && j < i)
	{
		p = p->next;
		++j;
	}
	if(!p || j > i)
		return ERROR;
	*e = p->data;

	return OK;
}

// delete
Status DeleteElem(LinkList *L, int i, ElemType *e)
{
	int j;
	LinkList p, q;
	p = *L;
	j = 1;
	while(p->next && j < i)
	{
		p = p->next;
		++j;
	}
	if(!(p->next) || j > i)
		return ERROR;
	q = p->next;
	p->next = q->next;
	(*L)->data -= 1;
	free(q);

	return OK;
}


// clear
Status ClearList(LinkList *L)
{
	LinkList p,q;
	p = (*L)->next;
	while(p)
	{
		q = p->next;
		free(p);
		p = q;
	}
	(*L)->next = NULL;
	return OK;
}

int main(){
	LinkList list;
	//init
	printf("input list length:\n");
	int length;
	scanf("%d", &length);
	if(CreateListTail(&list, length))
	{
		list->data = length;
		printf("Init success!\n");
	}
	//1.insert 
	printf("请输入你要插入数据的位置和数据：\n");
	int num;
	ElemType data;
	scanf("%d,%d", &num, &data);
	if(ListInsert(&list, num, data) == OK)
	{
		printf("Insert Success!\n");
		printf("Linklist current length is %d\n", list->data);
	}
	else
		printf("Insert Error!\n");
	// each
	LinkList node;
	node = list;
	for(int i = 0; i < list->data; i++)
	{
		node = node->next;
		printf("index:%d,data:%d\n", i, node->data);
	}
	
	//2.get
	if(GetElem(list, 1, &data) == OK)
	{
		printf("get data success!\n");
		printf("data is %d\n", data);
	}
	else
		printf("get data fail!\n");
	//3.delete
	if(DeleteElem(&list, 1, &data) == OK)
	{
		printf("delete data success!\n");
		printf("Linklist current length is %d\ndelete data value is %d\n",list->data , data);
	}
	else
		printf("delete data fail!\n");
	if(ClearList(&list) == OK)
		printf("LinkList clear success!\n");
	else
		printf("LinkList clear fail!\n");
		
	return 0;
}
