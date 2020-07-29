#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

#pragma warning(disable:4996)

//����ƥ��:�����ű����������ƥ��������ȷ��˳��ƥ��

//typedef  char ElemType;
//typedef struct LinkStackNode       //˳��ջ
//{
//	ElemType data;
//	struct LinkStackNode *link;
//}LinkStackNode;
//typedef LinkStackNode*LinkStack;
//void LinkStackInit(LinkStack *st)
//{
//	assert(st != NULL);
//	*st = NULL;
//}
//ElemType LinkStackEmpty(LinkStack*st)
//{
//	assert(st != NULL);
//	return (*st) == NULL;
//}
//void LinkStackPush(LinkStack*st, ElemType x)
//{
//	assert(st != NULL);
//	LinkStackNode*node = (LinkStackNode*)malloc(sizeof(LinkStackNode));
//	assert(node != NULL);
//	node->data = x;
//	node->link = *st;
//	*st = node;
//}
//void LinkStackPop(LinkStack *st)
//{
//	assert(st != NULL);
//	if (*st != NULL) {
//		LinkStackNode*p = *st;
//		*st = p->link;
//		free(p);
//	}
//}
//ElemType LinkStackTop(LinkStack *st)
//{
//	assert(st != NULL && *st != NULL);
//	return (*st)->data;
//}
//void LinkStackDestory(LinkStack *st)
//{
//	assert(st != NULL);
//	LinkStackNode*p = *st;
//	while (p != NULL) {
//		*st = p->link;
//		free(p);
//		p = *st;
//	}
//}
//////////////////////////////////////////////////////////////////////////
//bool isValid(char *s)
//{
//	if (s == NULL)
//		return false;
//	if (*s == '\0')
//		return true;
//	LinkStack st;
//	LinkStackInit(&st);
//	while (*s != '\0') {
//		if (*s == '{' || *s == '[' || *s == '(')
//			LinkStackPush(&st,*s);      //������ȫ����ջ��������������ջ��Ԫ�ؽ���ƥ��
//		else {
//			if (LinkStackEmpty(&st))    //ջΪ�յ�����£���û��������ֻ��������ʱ��
//				return false;
//			char top = LinkStackTop(&st);
//			if ((*s == '}' && top != '{') || (*s == ']' && top != '[') || (*s == ')' && top != ')'))
//				return false;
//			LinkStackPop(&st);
//		}
//		s++;
//	}
//	bool flag = LinkStackEmpty(&st);
//	LinkStackDestory(&st);
//	return flag;
//}



//ʹ�ö���ʵ��ջ
//typedef int ElemType;
//typedef struct LinkQueueNode
//{
//	ElemType data;
//	struct LinkQueueNode *link;
//}LinkQueueNode;
//typedef struct LinkQueue
//{
//	LinkQueueNode* head;  //��ͷָ��
//	LinkQueueNode* tail;  //��βָ��
//}LinkQueue;
//void LinkQueueInit(LinkQueue *pq)   //��ʼ��
//{
//	assert(pq != NULL);
//	pq->head = pq->tail = NULL;
//}
//void LinkQueueEn(LinkQueue *pq, ElemType x) //���
//{
//	assert(pq != NULL);
//	LinkQueueNode*node = (LinkQueueNode*)malloc(sizeof(LinkQueueNode));
//	assert(node != NULL);
//	node->data = x;
//	node->link = NULL;    //���Ϊβ������
//	if (pq->head == NULL)        //�����Ԫ��Ϊ��һ��Ԫ��
//		pq->head = pq->tail = node;
//	else {
//		pq->tail->link = node;
//		pq->tail = node;      //�޸�β��ָ��
//	}
//}
//int LinkQueueDe(LinkQueue *pq) //����
//{
//	assert(pq != NULL);
//	if (pq->head != NULL) {
//		LinkQueueNode*p = pq->head;
//		if (pq->head == pq->tail)      //������ֻ��һ��Ԫ��
//			pq->head = pq->tail = NULL;
//		else
//			pq->head = p->link;    //�Ӷ�ͷ����
//		free(p);
//	}
//}
//ElemType LinkQueueFront(LinkQueue *pq)  //��ͷ
//{
//	assert(pq != NULL);
//	assert(pq->head != NULL);
//	return pq->head->data;      //��β  return pq->tail->data
//}
//ElemType LinkQueueBack(LinkQueue*pq)
//{
//	assert(pq != NULL);
//	assert(pq->head != NULL);
//	return pq->tail->data;
//}
//int LinkQueueSize(LinkQueue *pq)  //��С
//{
//	assert(pq != NULL);
//	int size = 0;
//	LinkQueueNode *p = pq->head;
//	while (p != NULL) {
//		size++; p = p->link;
//	}
//}
//bool LinkQueueEmpty(LinkQueue *pq) //�п�
//{
//	assert(pq != NULL);
//	return pq->head == NULL;
//}
//void LinkQueueDestroy(LinkQueue *pq)  //����
//{
//	assert(pq != NULL);
//	LinkQueueNode*p = pq->head;
//	while (p != NULL) {
//		pq->head = p->link;
//		free(p);
//		p = pq->head;
//	}
//}
///////////////////////////////////////////////////////////
//typedef struct {
//	LinkQueue q1;
//	LinkQueue q2;
//}MyStack;
//MyStack* myStackCreate() 
//{
//	MyStack*pst = (MyStack*)malloc(sizeof(MyStack));
//	LinkQueueInit(&(pst->q1));
//	LinkQueueInit(&(pst->q2));
//	return pst;
//}
//void myStackPush(MyStack*obj,int x)
//{
//	LinkQueue*pnoempty;
//	if (LinkQueueEmpty(&(obj->q1)))
//		pnoempty = &(obj->q2);   //���ն���
//	else
//		pnoempty = &(obj->q1); 
//	LinkQueueEn(pnoempty, x);
//}
//int myStackPop(MyStack*obj)
//{
//	LinkQueue*pempty,*pnoempty;
//	if (LinkQueueEmpty(&(obj->q1))) {
//	    pempty=&(obj->q1);
//		pnoempty = &(obj->q2);
//	}
//	else {
//		pempty = &(obj->q2);
//		pnoempty = &(obj->q1);
//	}
//	ElemType val;
//	while (!LinkQueueEmpty(pnoempty)) {
//	     val = LinkQueueFront(pnoempty);
//		LinkQueueDe(pnoempty);
//		if (LinkQueueEmpty(pnoempty))
//			break;
//		LinkQueueEn(pempty,val);
//	}
//	return val;
//}
//int myStackTop(MyStack*obj)
//{
//	LinkQueue*pnoempty;
//	if (!LinkQueueEmpty(&(obj->q1)))
//		pnoempty = &(obj->q1);
//	else
//		pnoempty = &(obj->q2);
//	return LinkQueueBack(pnoempty);
//}
//bool myStackEmpty(MyStack*obj)
//{
//	return LinkQueueEmpty(&(obj->q1)) && LinkQueueEmpty(&(obj->q2));
//}
//void myStackFree(MyStack*obj)
//{
//	LinkQueueDestroy(&(obj->q1));
//	LinkQueueDestroy(&(obj->q2));
//	free(obj);
//}



//��ջʵ�ֶ���
//typedef  int ElemType;
//typedef struct LinkStackNode       //˳��ջ
//{
//	ElemType data;
//	struct LinkStackNode *link;
//}LinkStackNode;
//typedef LinkStackNode*LinkStack;
//void LinkStackInit(LinkStack *st)
//{
//	assert(st != NULL);
//	*st = NULL;
//}
//ElemType LinkStackEmpty(LinkStack*st)
//{
//	assert(st != NULL);
//	return (*st) == NULL;
//}
//void LinkStackPush(LinkStack*st, ElemType x)
//{
//	assert(st != NULL);
//	LinkStackNode*node = (LinkStackNode*)malloc(sizeof(LinkStackNode));
//	assert(node != NULL);
//	node->data = x;
//	node->link = *st;
//	*st = node;
//}
//void LinkStackPop(LinkStack *st)
//{
//	assert(st != NULL);
//	if (*st != NULL) {
//		LinkStackNode*p = *st;
//		*st = p->link;
//		free(p);
//	}
//}
//ElemType LinkStackTop(LinkStack *st)
//{
//	assert(st != NULL && *st != NULL);
//	return (*st)->data;
//}
//void LinkStackDestory(LinkStack *st)
//{
//	assert(st != NULL);
//	LinkStackNode*p = *st;
//	while (p != NULL) {
//		*st = p->link;
//		free(p);
//		p = *st;
//	}
//}
//typedef struct {
//	LinkStack instack;
//	LinkStack outstack;
//}MyQueue;
//MyQueue*myQueueCreate()
//{
//	MyQueue *pq = (MyQueue*)malloc(sizeof(MyQueue));
//	LinkStackInit(&(pq->instack));
//	LinkStackInit(&(pq->outstack));
//	return pq;
//}
//void MmyQueuePush(MyQueue*obj, int x)
//{
//	LinkStackPush(&(obj->instack), x);
//}
//int myQueuePop(MyQueue*obj)
//{
//	if (LinkStackEmpty(&(obj->outstack)))
//	{
//		while (!LinkStackEmpty(&(obj->instack))) {
//			LinkStackPush(&(obj->outstack), LinkStackTop(&(obj->instack)));
//			LinkStackPop(&(obj->instack));
//		}
//	}
//	ElemType val = LinkStackTop(&(obj->outstack));
//	LinkStackPop(&(obj->outstack));
//	return val;
//}
//int myQueueTop(MyQueue*obj)
//{
//	if (LinkStackEmpty(&(obj->outstack)))
//	{
//		while (!LinkStackEmpty(&(obj->instack))) {
//			LinkStackPush(&(obj->outstack), LinkStackTop(&(obj->instack)));
//			LinkStackPop(&(obj->instack));
//		}
//	}
//	ElemType val = LinkStackTop(&(obj->outstack));
//	return val;
//}
//bool myQueueEmpty(MyQueue*obj)
//{
//	return LinkStackEmpty(&(obj->instack)) && LinkStackEmpty(&(obj->outstack));
//}
//void myQueueFree(MyQueue*obj)
//{
//	LinkStackDestory(&(obj->instack));
//	LinkStackDestory(&(obj->outstack));
//	free(obj);
//}



//��Сջ
//typedef  int ElemType;
//typedef struct LinkStackNode       //˳��ջ
//{
//	ElemType data;
//	struct LinkStackNode *link;
//}LinkStackNode;
//typedef LinkStackNode*LinkStack;
//void LinkStackInit(LinkStack *st)
//{
//	assert(st != NULL);
//	*st = NULL;
//}
//ElemType LinkStackEmpty(LinkStack*st)
//{
//	assert(st != NULL);
//	return (*st) == NULL;
//}
//void LinkStackPush(LinkStack*st, ElemType x)
//{
//	assert(st != NULL);
//	LinkStackNode*node = (LinkStackNode*)malloc(sizeof(LinkStackNode));
//	assert(node != NULL);
//	node->data = x;
//	node->link = *st;
//	*st = node;
//}
//void LinkStackPop(LinkStack *st)
//{
//	assert(st != NULL);
//	if (*st != NULL) {
//		LinkStackNode*p = *st;
//		*st = p->link;
//		free(p);
//	}
//}
//ElemType LinkStackTop(LinkStack *st)
//{
//	assert(st != NULL && *st != NULL);
//	return (*st)->data;
//}
//void LinkStackDestory(LinkStack *st)
//{
//	assert(st != NULL);
//	LinkStackNode*p = *st;
//	while (p != NULL) {
//		*st = p->link;
//		free(p);
//		p = *st;
//	}
//}
//typedef struct {
//	LinkStack st;
//	LinkStack min_st;
//}MinStack;
//MinStack*minStackCreat()
//{
//	MinStack*pst = (MinStack*)malloc(sizeof(MinStack));
//	LinkStackInit(&(pst->st));
//	LinkStackInit(&(pst->min_st));
//	return pst;
//}
//void minStackPush(MinStack*obj, int x)
//{
//	LinkStackPush(&(obj->st),x);
//	if (LinkStackEmpty(&(obj->min_st)) || x <= LinkStackTop(&(obj->min_st)))
//		LinkStackPush(&(obj->min_st), x);
//}
//void minStackPop(MinStack*obj)
//{
//	ElemType topval = LinkStackTop(&(obj->st));
//	LinkStackPop(&(obj->st));
//	if (topval == LinkStackTop(&(obj->min_st)))
//		LinkStackPop(&(obj->min_st));
//}
//int minStackTop(MinStack*obj)
//{
//	return LinkStackTop(&(obj->st));
//}
//int minStackGetMin(MinStack*obj)
//{
//	return LinkStackTop(&(obj->min_st));
//}
//void minStackFree(MinStack*obj)
//{
//	LinkStackDestory(&(obj->st));
//	LinkStackDestory(&(obj->min_st));
//	free(obj);
//}




//���ѭ������

//typedef struct {
//	int *base;
//	int capacity;
//	int front;
//	int rear;
//}MyCircularQueue;
//MyCircularQueue*myCircularQueueCreate(int k)
//{
//	MyCircularQueue* pcq = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
//	pcq->base = (int*)malloc(sizeof(int)*(k + 1));
//	pcq->capacity = k ;
//	pcq->front = pcq->rear = 0;
//	return pcq;
//}
//bool myCircularQueueIsEmpty(MyCircularQueue*obj)
//{
//	return obj->front == obj->rear;
//}
//bool myCircularQueueIsFull(MyCircularQueue*obj)
//{
//	return (obj->rear + 1) % (obj->capacity + 1) == obj->front;
//}
//bool myCircularQueueEn(MyCircularQueue*obj, int value)
//{
//	if (myCircularQueueIsFull(obj))
//		return false;
//	obj->base[obj->rear] = value;
//	obj->rear = (obj->rear + 1) % (obj->capacity + 1);
//	return true;
//}
//bool myCircularQueuePop(MyCircularQueue*obj)
//{
//	if (myCircularQueueIsEmpty(obj))
//		return false;
//	obj->front = (obj->front + 1) % (obj->capacity + 1);
//	return true;
//}
//int myCircularQueueFront(MyCircularQueue*obj)
//{
//	if (myCircularQueueIsEmpty(obj))
//		return -1;
//	return obj->base[obj->front];
//}
//int myCircularQueueBack(MyCircularQueue*obj)
//{
//	if (myCircularQueueIsEmpty(obj))
//		return -1;
//	return obj->base[(obj->rear - 1+(obj->capacity+1))%(obj->capacity+1)];
//}
//void myCircularQueueFree(MyCircularQueue*obj)
//{
//	free(obj->base);
//	free(obj);
//}



//�Ƴ�����Ԫ��

//struct ListNode { 
//	int val;
//	struct ListNode*next;
//}ListNode;
//struct ListNode* removeElements(struct ListNode*head, int val)
//{
//	if (head == NULL)
//		return NULL;
//	struct ListNode*p = head;
//	struct ListNode*prev = NULL;
//	while (p != NULL) {
//		struct ListNode*next = p->next;
//		if (p->val == val) {
//			if (prev == NULL)     //ɾ�����ǵ�һ�����
//				head = head->next;
//			else
//				prev->next = p->next;
//			free(p);
//			p = next;
//		}
//		else {
//			prev = p;
//			p = p->next;
//		}
//	}
//	return head;
//}



//��ת����
//struct ListNode {
//	int val;
//	struct ListNode*next;
//}ListNode;
//struct ListNode*reverseList(struct ListNode*head)
//{
//	if (head == NULL || head->next == NULL)
//		return head;
//	struct ListNode*p = head;
//	struct ListNode*q = p->next;
//	p->next = NULL;
//	while (q != NULL) {
//		p = q;
//		q = q->next;
//		p->next = head;
//		head = p;
//	}
//	return head;
//}




//������м��㣨�����м�ڵ㷵�صڶ�����

//struct ListNode {
//	int val;
//	struct ListNode*next;
//}ListNode;
//// �� 1
////struct ListNode*middleNode(struct ListNode*head)
////{
////	int len = 0;
////	struct ListNode*p = head;
////	while (p != NULL) {
////		len++;
////		p = p->next;
////	}
////	p = head; 
////	len /= 2;
////	while (len-- > 0) {
////		p = p->next;
////		return p;
////	}
////}
////  �� 2������ָ��
//struct ListNode*middleNode(struct ListNode*head)
//{
//	if (head == NULL)
//		return NULL;
//	struct ListNode*fast, *slow;
//	fast = slow = head;
//	while (fast && fast->next != NULL) {
//		fast = fast->next->next;
//		slow = slow->next;
//	}
//	return slow;
//}



//����������� K �����

//struct ListNode {
//	int val;
//	struct ListNode*next;
//}ListNode;
//struct ListNode*FindKthToTail(struct ListNode*PListHead, unsigned int k)
//{
//	if (PListHead == NULL)
//		return NULL;
//	struct ListNode*fast, *slow;
//	fast = slow = PListHead;
//	while (k-- > 0) {
//		if (fast == NULL)
//			return NULL;
//		fast = fast->next;
//	}
//	while (fast != NULL) {
//		fast = fast->next;
//		slow = slow->next;
//	}
//	return slow;
//}




