#include<stdio.h>
#include<stdlib.h>

//��ϰ��

//ջʵ�ֶ���
//����ջ��ʵ��----------���ջ�����ջ

//typedef int STdatatype;
//
//typedef struct stack {
//	STdatatype *_data;
//	int _size;
//	int _capacity;
//}stack;
//
//void stack_init(stack* st)
//{
//	if (st == NULL)
//		return;
//	st->_data = NULL;
//	st->_size = st->_capacity = 0;
//}
//void checkcapacity(stack* st)
//{
//	if (st->_capacity == st->_size) {
//		int newcapacity = st->_capacity == 0 ? 1 : 2 * st->_capacity;
//		st->_data = (STdatatype*)realloc(st->_data, sizeof(STdatatype)*newcapacity);
//		st->_capacity = newcapacity;
//	}
//}
//void stack_push(stack* st, STdatatype val)      //��ջ
//{
//	if (st == NULL)           //��ջ
//		return;
//	checkcapacity(st);
//	st->_data[st->_size++] = val;
//}
//void stack_pop(stack* st)       //ɾ��ջ��Ԫ��----��ջ
//{
//	if (st == NULL || st->_size == 0)
//		return;
//	--st->_size;
//}
//int stack_size(stack * st)
//{
//	if (st == NULL)
//		return;
//	return st->_size;
//}
//int stack_empty(stack *st)
//{
//	if (st == NULL || st->_size == 0)
//		return 1;
//	else
//		return 0;
//}
//STdatatype stack_top(stack*st)
//{
//	return st->_data[st->_size - 1];
//}
//void stack_destory(stack* st)
//{
//	free(st->_data);
//	st->_capacity = st->_size = 0;
//}
//
//
//typedef struct {
//	stack pushST;     //���ջ 
//	stack popST;    //����ջ
//} MyQueue;
//
///** Initialize your data structure here. */
//
//MyQueue* myQueueCreate() {
//	//��̬����
//	MyQueue* pq = (MyQueue*)malloc(sizeof(MyQueue));
//	stack_init(&pq->pushST);
//	stack_init(&pq->popST);
//	return pq;
//}
//
///** Push element x to the back of queue. */
//void myQueuePush(MyQueue* obj, int x) {
//	//���ջ
//	stack_push(&obj->pushST,x);
//}
//
///** Removes the element from in front of queue and returns that element. */
//int myQueuePop(MyQueue* obj) {
//	//����ս------�ж��Ƿ�Ϊ��
//	//�գ���Ҫ�����ջ��Ԫ�ص���
//	//���գ�֮���ջ
//	int front;
//	if (!stack_empty(&obj->popST)) {
//		front = stack_top(&obj->popST);
//	}
//	else {
//		while (!stack_empty(&obj->pushST)) {
//			stack_push(&obj->popST, stack_top(&obj->pushST));
//			stack_pop(&obj->pushST);
//		}
//		front = stack_top(&obj->popST);
//		stack_pop(&obj->popST);
//	}
//}
//
///** Get the front element. */
//int myQueuePeek(MyQueue* obj) {          //��ջ����
//	if (stack_empty(&obj->popST));
//	{
//		while (!stack_empty(&obj->pushST)) {
//			stack_push(&obj->popST, stack_top(&obj->pushST));
//			stack_pop(&obj->pushST);
//		}
//	}
//	return stack_top(&obj->popST);
//}
//
///** Returns whether the queue is empty. */
//bool myQueueEmpty(MyQueue* obj) {
//	return stack_empty(&obj->popST)&& stack_empty(&obj->pushST);
//}
//void myQueueFree(MyQueue* obj) {
//	stack_destory(&obj->pushST);
//	stack_destory(&obj->popST);
//	free(obj);
//}






//�ö���ʵ��ջ     ?????????????????

//typedef int Qdatatype;
//typedef struct QNode {
//	Qdatatype _data;
//	struct QNode* _next;
//}QNode;
//typedef struct Queue {
//	QNode* _head;
//	QNode* _tail;
//	int _size;
//}Queue;
//void Queue_init(Queue * q)
//{
//	if (q == NULL)
//		return;
//	q->_head = q->_tail = NULL;
//	q->_size = 0;
//}
//QNode* creatNode(Qdatatype val)              //�����½ڵ�
//{
//	QNode* node = (QNode*)malloc(sizeof(QNode));
//	node->_data = val;
//	node->_next = NULL;
//}
//void Queue_push(Queue* q, Qdatatype val)     //����------��β
//{
//	QNode* node = creatNode(val);
//	if (q->_head == NULL)
//		q->_head = q->_tail = node;
//	else {
//		q->_tail->_next = node;
//		q->_tail = node;
//	}
//	++q->_size;
//}
//void Queue_pop(Queue* q)                 //ɾ��------��ͷ
//{
//	if (q == NULL || q->_head == NULL)
//		return;
//	QNode* next = q->_head->_next;
//	free(q->_head);
//	q->_head = next;
//
//	//���������ֻ��һ������
//	if (q->_head == NULL)
//		q->_tail = NULL;
//	--q->_size;
//}
//int Queue_empty(Queue* q)                //�п�
//{
//	/*if (q == NULL || q->_head == NULL)
//		return 1;
//	return 0;*/
//	return q->_head == NULL;
//}
//Qdatatype Queue_front(Queue* q)      //ȡ��ͷ
//{
//	/*if (q == NULL || q->_head == NULL)
//		return;*/
//	return q->_head->_data;
//}
//Qdatatype Queue_back(Queue* q)      //ȡ��β
//{
//	return q->_tail->_data;
//}
//int	Queue_size(Queue* q)
//{
//	if (q == NULL)
//		return 0;
//	return q->_size;
//}
//
//typedef struct {                           //?????????????????????????????????????????????????
//	Queue q;
//}MyStack;
//MyStack* mystackcreat()
//{
//	//��̬����
//	MyStack* pst = (MyStack*)malloc(sizeof(MyStack));
//	Queue_init(&pst->q);
//	return pst;
//}
//void mystack_push(MyStack* obj, int x)
//{
//	Queue_push(&obj->q, x);
//}
//void mystack_pop(MyStack* obj)
//{
//	int n = Queue_size(&obj->q);
//	while (n > 1) {
//		int front = Queue_front(&obj->q);
//		Queue_pop(&obj->q);
//		Queue_push(&obj->q,front);
//	}
//	int top = Queue_front(&obj->q);
//	Queue_pop(&obj->q);
//}
//bool mystack_empty(MyStack* obj)
//{
//	return Queue_empty(&obj->q);
//}
//bool mystack_size(MyStack* obj)
//{
//	return Queue_size(&obj->q);
//}
//void queuedestory(Queue* q)
//{
//	QNode* cur = q->_head;
//	while (cur) {
//		QNode* next = cur->_next;
//		free(cur);
//		cur = next;
//	}
//}
//void mystack_free(MyStack* obj)
//{
//	queuedestory(&obj->q);
//	free(obj);
//}









////����ƥ������----------����ƥ�䡢˳��ƥ��
//
//typedef int STdatatype;
//
//typedef struct stack {
//	STdatatype *_data;
//	int _size;
//	int _capacity;
//}stack;
//
//void stack_init(stack* st)
//{
//	if (st == NULL)
//		return;
//	st->_data = NULL;
//	st->_size = st->_capacity = 0;
//}
//void checkcapacity(stack* st)
//{
//	if (st->_capacity == st->_size) {
//		int newcapacity = st->_capacity == 0 ? 1 : 2 * st->_capacity;
//		st->_data = (STdatatype*)realloc(st->_data, sizeof(STdatatype)*newcapacity);
//		st->_capacity = newcapacity;
//	}
//}
//void stack_push(stack* st, STdatatype val)      //��ջ
//{
//	if (st == NULL)           //��ջ
//		return;
//	checkcapacity(st);
//	st->_data[st->_size++] = val;
//}
//void stack_pop(stack* st)       //ɾ��ջ��Ԫ��----��ջ
//{
//	if (st == NULL || st->_size == 0)
//		return;
//	--st->_size;
//}
//int stack_size(stack * st)
//{
//	if (st == NULL)
//		return;
//	return st->_size;
//}
//int stack_empty(stack *st)
//{
//	if (st == NULL || st->_size == 0)
//		return 1;
//	else
//		return 0;
//}
//STdatatype stack_top(stack* st)
//{
//	return st->_data[st->_size - 1];
//}
//
//
//
//bool IsValid(char *s)
//{
//	char map[3][2] = { {'(',')'},{'[',']'},{'{','}'} };
//	stack st;        //ջ
//	stack_init(&st);
//	int flag = 0;
//	while (*s) {
//		int i = 0;
//		for (; i < 3; ++i) {
//			if (*s == map[i][0]) {
//				//��������ջ
//				stack_push(&st, *s);
//				++s;
//				flag = 1;
//				break;
//			}
//		}
//		if (flag == 0) {
//			if (stack_empty(&st))
//				return false;
//			//ȡջ��Ԫ�ؽ���ƥ��
//			char topchar = stack_top(&st);
//			stack_pop(&st);
//			if(map[i][1] == *s){
//				if (topchar == map[i][0]) {
//					++s;
//					break;
//				}
//				else
//					return false;
//			}
//		}
//	}
//	return stack_empty(&st);
//}

