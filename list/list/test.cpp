#include<stdio.h>
#include<stdlib.h>
#include<assert.h>


typedef struct ListNode
{
	int data;   // 数据域
	ListNode *next;
}ListNode;


typedef ListNode* List;

void ListInit(List *phead)   //初始化
{
	assert(phead != NULL);
	*phead = NULL;
}
void ListCreat_Tail(List *phead)      //后插
{
	assert(phead != NULL);
	*phead = (ListNode*)malloc(sizeof(ListNode));
	assert(*phead != NULL);
	(*phead)->data = 1;
	(*phead)->next = NULL;

	ListNode *p = *phead;
	for (int i = 2; i <= 10; i++) {
		ListNode *s = (ListNode*)malloc(sizeof(ListNode));
		assert(s != NULL);
		s->data = i;
		s->next = NULL;
		p->next = s;
		p = s;
	}
}
void ListCreat_Head(List *phead)   //头插
{
	assert(phead != NULL);
	*phead = (ListNode*)malloc(sizeof(ListNode));
	assert(*phead != NULL);
	(*phead)->data = 1;
	(*phead)->next = NULL;

	for (int i = 2; i <= 10; i++) {
		ListNode *s = (ListNode*)malloc(sizeof(ListNode));
		assert(s != NULL);
		s->data = i;
		s->next = *phead;
		*phead = s;
	}
}
void ListCreat(List *phead)
{
	assert(phead != NULL);
	*phead = (ListNode*)malloc(sizeof(ListNode));
	assert(*phead != NULL);
	(*phead)->data = 1;
	(*phead)->next = NULL;

	ListNode *p = *phead;
	for (int i = 2; i <= 10; ++i) {
		p = p->next = (ListNode*)malloc(sizeof(ListNode));
		p->data = i;
		p->next = NULL;
	}
}

void ListShow(List phead)   //显示
{
	ListNode *p = phead;
	while (p != NULL) {
		printf("%d->", p->data);
		p = p->next;
	}
	printf("over!\n");
}

int main()
{

	List mylist;  //ListNode* mylist
	ListInit(&mylist);
	ListCreat_Tail(&mylist);
	ListCreat_Head(&mylist);
	ListShow(mylist);

	return 0;
}