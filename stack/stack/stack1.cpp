#include<stdio.h>
#include<stdlib.h>

//练习题


//环形队列

//typedef struct {
//	int _front;
//	int _rear;    //队尾元素下一个位置
//	int _k;      //元素个数
//	int* _data; 
//}mycirclequeue;
//mycirclequeue* mycircle_queuecreat(int k)
//{
//	mycirclequeue* cq = (mycirclequeue*)malloc(sizeof(mycirclequeue));
//	cq->_front = cq->_rear = 0;        //队头==队尾   表示空队列
//	cq->_k = k;
//	cq->_data = (int*)malloc(sizeof(int)*(k + 1));
//	return cq;
//}
//bool mycircle_Enqueue(mycirclequeue* obj, int val)
//{
//	//入队
//	if (mycircle_isfull(obj))
//		return false;
//	obj->_data[obj->_rear++] = val;
//	if (obj->_rear > obj ->_k)
//		obj->_rear = 0;
//	return true;
//}
//bool mycircle_Dequeue(mycirclequeue* obj)
//{
//	//出队
//	if (mycircle_isempty(obj))
//		return false;
//	obj->_front++;   //队头出队
//
//	if (obj->_front > obj->_k)
//		obj->_front = 0;
//	return true;
//}
//int mycircle_frontqueue(mycirclequeue* obj)
//{
//	if (mycircle_isempty(obj))
//		return -1;
//	return obj->_data[obj->_front];
//}
//int mycircle_rearqueue(mycirclequeue* obj)
//{
//	if (mycircle_isempty(obj))
//		return -1;
//	if (obj->_rear != 0)
//		return obj->_data[obj->_rear - 1];
//	else
//		return obj->_data[obj->_k];
//}
//bool mycircle_isfull(mycirclequeue* obj)
//{
//	return (obj->_rear + 1) % (obj->_k + 1) == obj->_front;
//}
//bool mycircle_isempty(mycirclequeue* obj)
//{
//	return obj->_front == obj->_rear;
//}
//void mycircle_freequeue(mycirclequeue* obj)
//{
//	free(obj->_data);
//	free(obj);
//}







//括号匹配问题

//////利用栈的操作
//typedef int STdatatype;
//typedef struct stack {    //顺序表
//	STdatatype *_data;
//	int _size;
//	int _capacity;
//}stack;
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
//void stack_push(stack* st, STdatatype val)      //进栈
//{
//	if (st == NULL)           //空栈
//		return;
//	checkcapacity(st);
//	st->_data[st->_size++] = val;
//}
//void stack_pop(stack* st)       //删除栈顶元素----出栈
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
//STdatatype stack_top(stack*st)         //获取栈顶元素
//{
//	return st->_data[st->_size - 1];
//}
//void stack_destory(stack* st)       //销毁
//{
//	free(st->_data);
//	st->_capacity = st->_size = 0;
//}
//
//bool isValid(char *s)
//{
//	char map[3][2] = { {'(',')'},{'[',']'},{'{','}'} };
//	struct stack st;
//	int flag = 0;
//	stack_init(&st);
//	while (*s) {         //左括号入栈
//		for (int i = 0; i < 3; i++) {
//			if (*s == map[i][0]) {
//				stack_push(&st, *s);
//				++s;
//				flag = 1;
//				break;
//			}
//		}
//		if (flag == 0) {        //匹配
//			if (stack_empty)
//				return false;
//			char topchar = stack_top(&st);
//			stack_pop(&st);
//			for (int i = 0; i < 3; ++i) {
//				if (map[i][1] == *s) {
//					if (topchar == map[i][0]) {
//						++s;
//						break;
//					}
//					else
//						return false;
//				}
//				
//			}
//		}
//	}
//	return stack_empty(&st); //完全匹配
//}






//栈实现队列
//两个栈来实现----------入队栈与出队栈

//typedef int STdatatype;
//
//typedef struct stack {
//	STdatatype *_data;
//	int _size;
//	int _capacity;
//}stack;
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
//void stack_push(stack* st, STdatatype val)      //进栈
//{
//	if (st == NULL)           //空栈
//		return;
//	checkcapacity(st);
//	st->_data[st->_size++] = val;
//}
//void stack_pop(stack* st)       //删除栈顶元素----出栈
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
//	if (st) {
//		if (st->_data) {
//			free(st->_data);
//			st->_data = NULL;
//			st->_capacity = st->_size = 0;
//		}
//	}
//}
//////////////////////////////////////////////////////////////
//typedef struct {
//	stack pushST;     //入队栈 
//	stack popST;    //出队栈
//} MyQueue;
//MyQueue* myQueueCreate() {
//	//动态创建
//	MyQueue* pq = (MyQueue*)malloc(sizeof(MyQueue));
//	stack_init(&pq->pushST);
//	stack_init(&pq->popST);
//	return pq;
//}
//void myQueuePush(MyQueue* obj, int x) { 
//	//入队栈
//	stack_push(&obj->pushST,x);
//}
//int myQueuePop(MyQueue* obj) {
//	//出对栈------判断是否为空
//	//空，需要把入队栈的元素导入
//	//不空，之间出栈
//	int front;
//	if (!stack_empty(&obj->popST)) {
//		front = stack_top(&obj->popST);
//		stack_pop(&obj->popST);               //出栈
//	}
//	else {
//		while (!stack_empty(&obj->pushST)) {
//			stack_push(&obj->popST, stack_top(&obj->pushST));
//			stack_pop(&obj->pushST);
//		}
//		front = stack_top(&obj->popST);
//		stack_pop(&obj->popST);
//	}
//	return front;
//}
//int myQueuePeek(MyQueue* obj) {          //获取队头元素
//	if (stack_empty(&obj->popST));
//	{
//		while (!stack_empty(&obj->pushST)) {
//			stack_push(&obj->popST, stack_top(&obj->pushST));
//			stack_pop(&obj->pushST);
//		}
//	}
//	return stack_top(&obj->popST);
//}
//bool myQueueEmpty(MyQueue* obj) {
//	return stack_empty(&obj->popST) && stack_empty(&obj->pushST);
//}
//void myQueueFree(MyQueue* obj) {
//	stack_destory(&obj->pushST);
//	stack_destory(&obj->popST);
//	free(obj);
//}








//用队列实现栈     

//typedef int qdatatype;
//typedef struct qnode {
//	qdatatype _data;
//	struct qnode* _next;
//}qnode;
//typedef struct queue {
//	qnode* _head;
//	qnode* _tail;
//	int _size;
//}queue;
//void queue_init(queue * q)
//{
//	if (q == NULL)
//		return;
//	q->_head = q->_tail = NULL;
//	q->_size = 0;
//}
//qnode* creatnode(qdatatype val)              //创建新节点
//{
//	qnode* node = (qnode*)malloc(sizeof(qnode));
//	node->_data = val;
//	node->_next = NULL;
//}
//void queue_push(queue* q, qdatatype val)     //插入------队尾
//{
//	qnode* node = creatnode(val);
//	if (q->_head == NULL)
//		q->_head = q->_tail = node;
//	else {
//		q->_tail->_next = node;
//		q->_tail = node;
//	}
//	++q->_size;
//}
//void queue_pop(queue* q)                 //删除------队头
//{
//	if (q == NULL || q->_head == NULL)
//		return;
//	qnode* next = q->_head->_next;
//	free(q->_head);
//	q->_head = next;
//
//	//如果队列中只有一个数据
//	if (q->_head == NULL)
//		q->_tail = NULL;
//	--q->_size;
//}
//int queue_empty(queue* q)                //判空
//{
//	/*if (q == null || q->_head == null)
//		return 1;
//	return 0;*/
//	return q->_head == NULL;
//}
//qdatatype queue_front(queue* q)      //取队头
//{
//	/*if (q == null || q->_head == null)
//		return;*/
//	return q->_head->_data;
//}
//qdatatype queue_back(queue* q)      //取队尾
//{
//	return q->_tail->_data;
//}
//int	queue_size(queue* q)
//{
//	if (q == NULL)
//		return 0;
//	return q->_size;
//}
//void queue_destory(queue* q)
//{
//	qnode* cur = q->_head;
//	while (cur) {
//		qnode* next = cur->_next;
//		free(cur);
//		cur = next;
//	}
//	q->_head = q->_tail = NULL;
//}
/////////////////////////////////////////////////////////
//typedef struct {  
//	queue q;             //定义一个队列
//}mystack;
//mystack* mystackcreat()
//{
//	//动态创建一个队列栈
//	mystack* pst = (mystack*)malloc(sizeof(mystack));
//	queue_init(&pst->q);   //进行初始化
//	return pst;
//}
//void mystack_push(mystack* obj, int x)
//{
//	queue_push(&obj->q, x);          //进栈 -- 进队
//}
//int mystack_pop(mystack* obj)     //出栈：要找到入队的最后一个元素--相当于是栈顶元素
//{
//	int n = queue_size(&obj->q);
//	while (n > 1) {
//		int front = queue_front(&obj->q);
//		queue_pop(&obj->q);
//		queue_push(&obj->q,front);
//		--n;
//	}
//	int top = queue_front(&obj->q);   //找到栈顶元素
//	queue_pop(&obj->q);        //出栈
//	return top;
//}
//int mystack_top(mystack* obj)       //栈顶元素---入队的队尾元素
//{
//	return queue_back(&obj->q);
//}
//bool mystack_empty(mystack* obj)
//{
//	return queue_empty(&obj->q);
//}
//bool mystack_size(mystack* obj)
//{
//	return queue_size(&obj->q);
//}
//void mystack_free(mystack* obj)
//{
//	queue_destory(&obj->q);
//	free(obj);
//}







////括号匹配问题----------类型匹配、顺序匹配
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
//void stack_push(stack* st, STdatatype val)      //进栈
//{
//	if (st == NULL)           //空栈
//		return;
//	checkcapacity(st);
//	st->_data[st->_size++] = val;
//}
//void stack_pop(stack* st)       //删除栈顶元素----出栈
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

//bool IsValid(char *s)
//{
//	char map[3][2] = { {'(',')'},{'[',']'},{'{','}'} };
//	stack st;        //栈
//	stack_init(&st);
//	int flag = 0;
//	while (*s) {
//		int i = 0;
//		for (; i < 3; ++i) {
//			if (*s == map[i][0]) {
//				//左括号入栈
//				stack_push(&st, *s);
//				++s;
//				flag = 1;
//				break;
//			}
//		}
//		if (flag == 0) {
//			if (stack_empty(&st))
//				return false;
//			//取栈顶元素进行匹配
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

