#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>


//栈

// 支持动态增长的栈
//typedef int STDataType;
//typedef struct Stack
//{
//	STDataType* _a;
//	int _top;		// 栈顶
//	int _capacity;  // 容量 
//}Stack;
//// 初始化栈 
//void StackInit(Stack* ps)
//{
//	if (ps == NULL)
//		return;
//	ps->_a = NULL;
//	ps->_capacity = ps->_top = 0;
//}
//void checkcapacity(Stack* ps)
//{
//	if (ps->_capacity == ps->_top) {
//		int newcapacity = ps->_capacity == 0 ? 1 : 2 * ps->_capacity;
//		ps->_a = (STDataType*)realloc(ps->_a,sizeof(STDataType)*newcapacity);
//		ps->_capacity = newcapacity;
//	}
//}
//// 入栈 
//void StackPush(Stack* ps, STDataType data)
//{
//	if (ps == NULL)
//		return;
//	checkcapacity(ps);
//	ps->_a[ps->_top++]=data;
//}
//// 出栈 
//void StackPop(Stack* ps)
//{
//	if (ps == NULL || ps->_top == 0)
//		return;
//	--ps->_top;
//}
//// 获取栈顶元素 
//STDataType StackTop(Stack* ps)
//{
//	if (ps == NULL || ps->_top == 0)
//		return 0;
//	return ps->_a[ps->_top - 1];
//}
//// 获取栈中有效元素个数 
//int StackSize(Stack* ps)
//{
//	if (ps == NULL || ps->_top == 0)
//		return 0;
//	return ps->_top;
//}
//// 检测栈是否为空，如果为空返回非零结果，如果不为空返回0 
//int StackEmpty(Stack* ps)
//{
//	if (ps == NULL || ps->_top == 0)
//		return 1;              //栈空返回非零
//	else
//		return 0;
//}
//// 销毁栈 
//void StackDestroy(Stack* ps)
//{
//	if (ps == NULL)
//		return;
//	ps->_capacity = ps->_top = 0;
//	free(ps->_a);
//	ps->_a = NULL;
//}
//void StackPrint(Stack* ps)
//{
//	//打印
//	if (ps == NULL || ps->_top == 0)
//		return;
//	else {
//		for (int i = 0; i < ps->_top; ++i)
//			printf("%d ", ps->_a[i]);
//		printf("\n");
//	}
//}
//void test()
//{
//	Stack a;
//	StackInit(&a);
//	StackPush(&a, 1);
//	StackPush(&a, 2);
//	StackPush(&a, 3);
//	StackPush(&a, 4);
//	StackPrint(&a);
//
//	printf("%d ", StackTop(&a));
//	printf("\n");
//
//	StackPop(&a);
//	StackPop(&a);
//	StackPop(&a);
//	StackPrint(&a);
//
//	printf("%d ",StackSize(&a));
//	printf("\n");
//	StackDestroy(&a);
//}
//int main()
//{
//	test();
//	return 0;
//}





//队列
//// 链式结构：表示队列 

//typedef int QDataType;
//
//typedef struct QListNode
//{
//	struct QListNode* _next;
//	QDataType _data;
//}QNode;
//
//// 队列的结构 
//typedef struct Queue
//{
//	QNode* _front;
//	QNode* _rear;
//	int _size;
//}Queue;
//
//// 初始化队列 
//void QueueInit(Queue* q)
//{
//	if (q == NULL)
//		return;
//	q->_front = q->_rear = NULL;
//}
//QNode* creatNode(QDataType data)              //创建新节点
//{
//	QNode* node = (QNode*)malloc(sizeof(QNode));
//	node->_data = data;
//	node->_next = NULL;
//	return node;
//}
//// 队尾入队列 
//void QueuePush(Queue* q, QDataType data)
//{
//	if (q == NULL)
//		return;
//	QNode* node = creatNode(data);
//	if (q->_front == NULL) {
//		q->_front = q->_rear = node;          //创建第一个结点
//		q->_size = 1;
//	}
//	else {
//		q->_rear->_next = node;
//		q->_rear = node;
//		++q->_size;
//	}
//}
//// 队头出队列 
//void QueuePop(Queue* q)
//{
//	if (q == NULL || q->_front == NULL)
//		return;
//	if (q->_front == q->_rear) {          //只有一个结点时
//		free(q->_front);
//		q->_front = q->_rear = NULL;
//	}
//	else {
//		QNode* node = q->_front->_next;
//		free(q->_front);
//		q->_front = node;
//	}
//	--q->_size;
//}
//// 获取队列头部元素 
//QDataType QueueFront(Queue* q)
//{
//	if (q == NULL)
//		return NULL;
//	return q->_front->_data;
//}
//// 获取队列队尾元素 
//QDataType QueueBack(Queue* q)
//{
//	if (q == NULL)
//		return NULL;
//	return q->_rear->_data;
//}
//// 获取队列中有效元素个数 
//int QueueSize(Queue* q)
//{
//	if (q == NULL || q->_front == NULL)
//		return 0;
//	return q->_size;
//}
//// 检测队列是否为空，如果为空返回非零结果，如果非空返回0 
//int QueueEmpty(Queue* q)
//{
//	if (q == NULL || q->_size == 0)
//		return 1;
//	else
//		return 0;
//}
//// 销毁队列 
//void QueueDestroy(Queue* q)
//{
//	if (q == NULL)
//		return;
//	QNode* node = q->_front;
//	while (node) {
//		QNode* next = node->_next;
//		free(node);
//		node = next;
//	}
//	q->_front = q->_rear = NULL;
//} 
//void QueuePrint(Queue* q)                //打印
//{
//	if (q == NULL)
//		return;
//	QNode* node = q->_front;
//	while (node) {
//		printf("%d ", node->_data);
//		node = node->_next;
//	}
//	printf("\n");
//}
//void test()
//{
//	Queue q;
//	QueueInit(&q);
//	QueuePush(&q, 1);
//	QueuePush(&q, 2);
//	QueuePush(&q, 3);
//	QueuePush(&q, 4);
//	QueuePush(&q, 5);
//	QueuePrint(&q);
//
//	printf("%d \n", QueueBack(&q));   //队尾
//	printf("%d \n", QueueFront(&q));  //队头
//
//	QueuePop(&q);
//	QueuePop(&q);
//	QueuePop(&q);
//	QueuePrint(&q);
//
//	printf("%d \n", QueueSize(&q));
//
//	QueueDestroy(&q);
//}
//int main()
//{
//	test();
//	return 0;
//}








//链表练习题
// 带头+双向+循环链表增删查改实现


//typedef int LTDataType;
//typedef struct ListNode
//{
//	LTDataType _data;
//	struct ListNode* _next;
//	struct ListNode* _prev;
//}ListNode;
//
//typedef struct List {
//	ListNode* pHead;
//}List;
//
//void ListInit(List* lst)        //初始化
//{
//	lst->pHead = (ListNode*)malloc(sizeof(ListNode));
//	lst->pHead->_next = lst->pHead->_prev = lst->pHead;
//}
//
//// 创建返回链表的头结点.
//ListNode* ListCreate(LTDataType val)
//{
//	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
//	node->_data = val;
//	node->_next = node->_prev = NULL;
//	return node;
//}
//// 双向链表销毁
//void ListDestory(List* lst)
//{
//	if (lst == NULL)
//		return;
//	ListNode* next = lst->pHead->_next;
//	while (next!= lst->pHead) {
//		ListNode* nextnext = next->_next;
//		free(next);
//		next = nextnext;
//	}
//	free(lst->pHead);
//	lst->pHead == NULL;        //只有一个头节点
//}
//// 双向链表打印
//void ListPrint(List* lst)
//{
//	if (lst->pHead == NULL || lst->pHead->_next == lst->pHead)
//		return;
//	ListNode* next = lst->pHead->_next;
//	while (next != lst->pHead)  {
//		printf("%d ", next->_data);
//		next = next->_next;
//	}
//	printf("\n");
//}
//// 双向链表尾插
//void ListPushBack(List* lst, LTDataType x)
//{
//	ListNode* node = ListCreate(x);
//	ListNode* tail = lst->pHead->_prev;
//	tail->_next = node;
//	node->_prev = tail;
//	node->_next = lst->pHead;
//	lst->pHead->_prev = node;
//}
//// 双向链表尾删
//void ListPopBack(List* lst)
//{
//	if ( lst->pHead == NULL )
//		return;             //空链表 
//	if (lst->pHead->_next == lst->pHead || lst->pHead->_prev == lst->pHead) {
//		free(lst->pHead);         //只有一个头节点
//		lst->pHead = NULL;
//	}
//	ListNode* pre = lst->pHead->_prev;       //尾节点的位置
//	if (pre != lst->pHead) {
//		ListNode* node = pre->_prev;
//		free(pre);
//		node->_next = lst->pHead;
//		lst->pHead->_prev = node;
//	}
//}
//// 双向链表头插
//void ListPushFront(List* lst, LTDataType x)
//{
//	ListNode* node = ListCreate(x);
//	node->_next = lst->pHead->_next;
//	lst->pHead->_next->_prev = node;
//	lst->pHead->_next = node;
//	node->_prev = lst->pHead;
//}
//// 双向链表头删
//void ListPopFront(List* lst)
//{
//	if (lst->pHead == NULL)
//		return;
//	ListNode* node = lst->pHead->_next;
//	if (node != lst->pHead) {
//		ListNode* next = node->_next;
//		lst->pHead->_next = next;
//		next->_prev = lst->pHead;
//		free(node);
//	}
//}
//// 双向链表查找
//ListNode* ListFind(List* lst, LTDataType x)
//{
//	if (lst->pHead == NULL || lst->pHead->_next == lst->pHead)
//		return NULL;
//	ListNode* node = lst->pHead->_next;
//	while (node != lst->pHead) {
//		if(node->_data!=x)
//			node = node->_next;
//		return node;
//	}
//	return NULL;
//}
//// 双向链表在pos的前面进行插入
//void ListInsert(ListNode* pos, LTDataType x)
//{
//	ListNode* node = ListCreate(x);
//	ListNode* pre = pos->_prev;
//	node->_next = pos;
//	pre->_next = node;
//	node->_prev = pre;
//	pos->_prev = node;
//}
//// 双向链表删除pos位置的节点
//void ListErase(ListNode* pos)
//{
//	ListNode* pre = pos->_prev;
//	ListNode* next = pos->_next;
//	if (pre == pos ||  next == pos) {
//		free(pos);      //只有一个节点pos
//	}
//	pre->_next = next;
//	next->_prev = pre;
//	free(pos);
//}
//
//void test()
//{
//	List lst;
//	ListInit(&lst);
//	ListPushBack(&lst, 1);
//	ListPushBack(&lst, 2);
//	ListPushBack(&lst, 3);
//	ListPushBack(&lst, 4);
//	ListPushBack(&lst, 5);
//	ListPrint(&lst);
//
//	ListPushFront(&lst, 6);
//	ListPushFront(&lst, 7);
//	ListPushFront(&lst, 8);
//	ListPushFront(&lst, 9);
//	ListPrint(&lst);
//
//	ListPopFront(&lst);
//	ListPopFront(&lst);
//	ListPopFront(&lst);
//	ListPrint(&lst);
//
//	ListPopBack(&lst);
//	ListPopBack(&lst);
//	ListPrint(&lst);
//
//}
//
//int main()
//{
//	test();
//	return 0;
//}


