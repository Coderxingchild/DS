
//单链表的建立、逆置、插入、删除、合并等操作

//#include<stdio.h>
//#include<stdlib.h>
//
//#pragma warning(disable:4996)
//
//typedef int ElemType;
//
//typedef struct Node
//{
//	ElemType data;
//	struct Node *next;
//}Node, *Linklist;
//
//void Createheadlist(Linklist &L) //建立一个带头结点的单链表
//{
//	Node *p, *s;
//	ElemType x;
//	L = (Linklist)malloc(sizeof(Node));    //动态空间申请
//	L->next = NULL;
//	p = L;
//	printf("请输入你的数据元素:>\n");
//	scanf("%d", &x);
//	while (x != 0)
//	{
//		s = (Linklist)malloc(sizeof(Node));
//		s->data = x;
//		s->next = NULL;
//		p->next = s;
//		p = s;
//		scanf("%d", &x);
//	}
//	printf("带有头节点的单链表建立成功！\n");
//	printf("////////////////////////////////////////////////////////////////////////////////\n");
//	printf("////////////////////////////////////////////////////////////////////////////////\n");
//}
//void printlist(Linklist L)       //遍历单链表（输出）
//{
//	Node *p;
//	p = L;
//	while (p->next != NULL)
//	{
//		p = p->next;
//		printf("%d", p->data);
//		printf("\t");
//	}
//	printf("\n");
//}
//void reverse(Linklist &L)         //逆置单链表
//{
//	Node *p, *s;
//	p = L->next;
//	L->next = NULL;
//	while (p) {
//		s = p;
//		p = p->next;
//		s->next = L->next;
//		L->next = s;
//	}
//}
//void Insertelement(Linklist &L, ElemType x)   //在非递减有序单链表中插入一个元素使链表仍然有序
//{
//	Node *p, *s;
//	s = (Linklist)malloc(sizeof(Node));
//	s->data = x;
//	p = L;
//	while (p->next && p->next->data <= x)
//		p = p->next;
//	s->next = p->next;
//	p->next = s;
//}
//void Createundecrease(Linklist &L)     //建立一个非递减有序单链表
//{
//	ElemType y;
//	L = (Linklist)malloc(sizeof(Node));
//	L->next = NULL;
//	printf("输入以0结束的整型数据:\n");
//	scanf("%d", &y);
//	while (y) {
//		Insertelement(L, y);
//		scanf("%d", &y);
//	}
//}
//Linklist combine(Linklist LA, Linklist LB)
////将递增有序的单链表LA和LB合并成一个递增有序的单链表LC
//{
//	Node *pa, *pb;
//	Node *r;
//	Linklist LC;
//	pa = LA->next;
//	pb = LB->next;
//	LC = LA;
//	LC->next = NULL;
//	r = LC;
//	while (pa != NULL && pb != NULL)
//	{
//		if (pa->data <= pb->data)
//		{
//			r->next = pa;
//			r = pa;
//			pa = pa->next;
//		}
//		else
//		{
//			r->next = pb;
//			r = pb;
//			pb = pb->next;
//		}
//	}
//	if (pa)                  //若表LA未完，将表LA中后续元素链到新表LC表尾
//		r->next = pa;
//	else                     //否则将表LB中后续元素链到新表LC表尾
//		r->next = pb;
//	free(LB);
//	return(LC);
//}
//void Deletelement(Linklist &L, ElemType x)    //在非递减有序链表中删除值为x的结点
//{
//	Node *p, *q;
//	p = L;
//	q = L->next;
//	while (q && q->data != x) {
//		p = q;
//		q = q->next;
//	}
//	if (!q)
//		printf("\n not deleted");
//	else { p->next = q->next; free(q); }
//}
//int main()
//{
//	Linklist L1, L2, L3;
//	Node *p;
//	L1 = (Node*)malloc(sizeof(Node));
//	L1->next = NULL;
//	ElemType x;
//	int select;
//	printf("################################################################################\n");
//	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
//	printf("################                  单链表的操作                ##################\n");
//	printf("################             1.建立单链表，以0结束            ##################\n");
//	printf("################             2.遍历单链表                     ##################\n");
//	printf("################             3.把单向链表中元素逆置           ##################\n");
//	printf("################             4.建立一个非递减有序单链表       ##################\n");
//	printf("################   5.建立两个非递减有序单链表，然后合并成一个非递减链表   ######\n");
//	printf("################   6.在非递减有序单链表中插入一个元素仍然有序  #################\n");
//	printf("################   7.在非递减有序链表中删除指定的元素          #################\n");
//	printf("################             0.退出程序                        #################\n");
//	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
//	printf("################################################################################\n");
//	while (true) {
//		printf("Please Enter your select: >");
//		scanf("%d", &select);
//		switch (select)
//		{
//		case 1:
//			Createheadlist(L1); 
//			break;
//		case 2:
//			printf("你所建立的单链表是：\n");
//			printlist(L1); 
//			printf("////////////////////////////////////////////////////////////////////////////////\n");
//			break;
//		case 3:
//			printf("逆置后的单链表为：\n");
//			reverse(L1);
//			printlist(L1); 
//			printf("////////////////////////////////////////////////////////////////////////////////\n");
//			break;
//		case 4:
//			Createundecrease(L1);
//			printlist(L1);
//			printf("////////////////////////////////////////////////////////////////////////////////\n");
//			break;
//		case 5:
//			Createundecrease(L1);
//			printf("单链表 A 中元素为:\n");
//			p = L1->next;
//			while (p != NULL)
//			{
//				printf("%d", p->data);
//				p = p->next;
//			}
//			printf("\n");
//			L2 = (Node*)malloc(sizeof(Node));
//			L2->next = NULL;
//			Createundecrease(L2);
//			printf("单链表 B 中元素为:\n");
//			p = L2->next;
//			while (p != NULL)
//			{
//				printf("%d", p->data);
//				p = p->next;
//			}
//			printf("\n");
//			L3 = combine(L1, L2);
//			printf("单链表 C 中元素为:\n");
//			p = L3->next;
//			while (p != NULL)
//			{
//				printf("%d", p->data);
//				p = p->next;
//			}
//			printf("////////////////////////////////////////////////////////////////////////////////\n");
//			break;
//		case 6:Createundecrease(L1);
//			printlist(L1);
//			printf("请输入你想要插入的元素 x :");
//			scanf("%d", &x);
//			Insertelement(L1, x);
//			printlist(L1); 
//			printf("////////////////////////////////////////////////////////////////////////////////\n");
//			break;
//		case 7:Createundecrease(L1);
//			printlist(L1);
//			printf("请输入你想要删除的元素 x :");
//			scanf("%d", &x);
//			Deletelement(L1, x);
//			printlist(L1); 
//			printf("////////////////////////////////////////////////////////////////////////////////\n");
//			break;
//		case 0:
//			printf("退出程序！\n");
//			break;
//		default:printf("Select error! Please Enter your select again: >"); 
//			printf("\n");
//			break;
//		}
//	}
//}




//栈与队列---------链栈、顺序栈、链队、顺序队

//#include<stdio.h>
//#include<stdlib.h>    
//#include <malloc.h>
//#include<windows.h>
//#pragma warning(disable:4996)
//#define MAXSIZE 256
//typedef int datatype; 
//typedef struct node                //定义链栈
//{
//	datatype data;
//	struct node *next;
//}StackNode, QNode, *LinkStack;
//typedef struct                    //定义顺序栈
//{
//	datatype data[MAXSIZE];
//	int front, rear;
//	int num;
//	int top;
//}SeqStack, C_SeQueue;
//typedef struct                   //定义链队
//{
//	QNode *front, *rear;
//}LQueue;
//LinkStack Init_LinkStack()      //链栈初始化函数
//{
//	StackNode *L;
//	L = (StackNode*)malloc(sizeof(StackNode));
//	L->data = -32767;
//	L->next = NULL;
//	return L;
//}
//LinkStack Push_LinkStack(LinkStack top, datatype x)  //链栈入栈函数
//{
//	StackNode *s;
//	s = (StackNode*)malloc(sizeof(StackNode));
//	s->data = x;
//	s->next = top->next;
//	top->next = s;
//	return top;
//}
//LinkStack Pop_LinkStack(LinkStack top, datatype *s)   //链栈出栈函数
//{
//	StackNode *p;
//	int j = 0;
//	p = top->next;
//	if (p != NULL)
//	{
//		*s = p->data;
//		top->next = p->next;
//		free(p);
//	}
//	return top;
//}
//SeqStack * init_SeqStack()                           //顺序栈初始化函数
//{
//	SeqStack *S;
//	S = (SeqStack*)malloc(sizeof(SeqStack));
//	S->top = -1;
//	return S;
//}
//int Push_SeqStack(SeqStack *S, datatype x)          //顺序栈入栈函数
//{
//	if (S->top == MAXSIZE - 1)
//	{
//		return(0);
//	}
//	else
//	{
//		S->top++;
//		S->data[S->top] = x;
//		return(1);
//	}
//}
//int Pop_SeqStack(SeqStack *S, datatype *p)            //顺序栈出栈函数
//{
//	{
//		*p = S->data[S->top];
//		S->top--;
//		return 1;
//	}
//}
//LQueue *Init_LQueue()                             //链队初始化函数
//{
//	LQueue *q;
//	QNode *p;
//	q = (LQueue*)malloc(sizeof(LQueue));
//	p = (QNode*)malloc(sizeof(QNode));
//	p->next = NULL;
//	q->front = q->rear = p;
//	return q;
//}
//void In_LQueue(LQueue *q, datatype x)              //链队入队函数
//{
//	QNode *p;
//	p = (QNode*)malloc(sizeof(QNode));
//	p->data = x;
//	p->next = NULL;
//	q->rear->next = p;
//	q->rear = p;
//}
//int Out_LQueue(LQueue *q, datatype *s)              //链队出队函数
//{
//	QNode *p;
//	p = q->front->next;
//	q->front->next = p->next;
//	*s = p->data;
//	free(p);
//	if (q->front->next == NULL)
//		q->rear = q->front;
//	return 1;
//}
//C_SeQueue *init_SeQueue()                       //顺序队初始化函数
//{
//	C_SeQueue *q;
//	q = (C_SeQueue*)malloc(sizeof(C_SeQueue));
//	q->front = q->rear = MAXSIZE - 1;
//	q->num = 0;
//	return q;
//}
//int In_SeQueue(C_SeQueue *q, datatype x)            //顺序队入队函数
//{
//	if (q->num == MAXSIZE)
//	{
//		return(-1);
//	}
//	else
//	{
//		q->rear = (q->rear + 1) % MAXSIZE;
//		q->data[q->rear] = x;
//		q->num++;
//		return(1);
//	}
//}
//int Out_SeQueue(C_SeQueue *q, datatype *p)                 //顺序队出队
//{
//	if (q->num == 0)
//	{
//		return -1;
//	}
//	else
//	{
//		q->front = (q->front + 1) % MAXSIZE;
//		*p = q->data[q->front];
//		q->num--;
//		return 1;
//	}
//}
//C_SeQueue *init_SeQueue();                            //顺序队初始化
//
//int In_SeQueue(C_SeQueue *q, datatype x);             //顺序队入队
//int Out_SeQueue(C_SeQueue *q, datatype *p);          //顺序队出队
//int main() {
//	int n, m, t = 1;
//	while (t)
//	{
//		printf("\n");
//		printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
//		printf("###########     1.链栈     #########\n");
//		printf("###########     2.顺序栈   #########\n");
//		printf("###########     3.链队     #########\n");
//		printf("###########     4.顺序队   #########\n");
//		printf("###########     0.结束     #########\n");
//		printf("###########     请选择:    #########\n");
//		printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
//		printf("Please Enter Your Select:>");
//		scanf("%d", &n);
//		switch (n)
//		{
//		case 1://选择链栈相关操作
//		{
//			LinkStack  L = NULL;
//			while (t)
//			{
//				printf("\n");
//				printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
//				printf("###########     1.初始化   #########\n");
//				printf("###########     2.入栈     #########\n");
//				printf("###########     3.出栈     #########\n");
//				printf("###########  4.返回上一层  #########\n");
//				printf("###########     请选择:    #########\n");
//				printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
//				printf("Please Enter Your Select:>");
//				scanf("%d", &m);
//				if (m == 4)
//					break;
//				else
//				{
//					switch (m)
//					{
//					case 1: L = Init_LinkStack(); break;//链栈初始化
//					case 2: {LinkStack p; //链栈入栈
//						datatype x;
//						printf("请输入要入栈的元素 x:\n");
//						scanf("%d", &x);
//						L = Push_LinkStack(L, x);
//						p = L->next;
//						while (p)
//						{
//							printf("%d", p->data);
//							p = p->next;
//						}
//						printf("\n");
//						break;
//					}
//					case 3: {
//						datatype x, *s;
//						LinkStack p;
//						s = &x;
//						L = Pop_LinkStack(L, s);
//						p = L->next;
//						while (p)
//						{
//							printf("%d", p->data);
//							p = p->next;
//						}
//
//						printf("出栈1数为：%d", x);
//						printf("\n");
//						break;
//					}
//					case 4:break;
//					}
//				}
//			}
//		}break;
//		case 2: {//选择顺序栈相关操作
//			SeqStack *S=0;
//			while (t)
//			{
//				printf("\n");
//				printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
//				printf("~~~~~~~~~~    1.初始化    ~~~~~~~~~~\n");
//				printf("~~~~~~~~~~    2.入栈1     ~~~~~~~~~~\n");
//				printf("~~~~~~~~~~    3.出栈1     ~~~~~~~~~~\n");
//				printf("~~~~~~~~~~  4.返回上一层  ~~~~~~~~~~\n");
//				printf("~~~~~~~~~~ 请输入你的选择 ~~~~~~~~~~\n");
//				printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
//				printf("Please Enter Your Select:>");
//				scanf("%d", &m);
//				if (m == 4)
//					break;
//				else
//				{
//					switch (m)
//					{
//					case 1:
//						S = init_SeqStack(); break;//顺序栈初始化
//					case 2: {//顺序栈入栈
//						int i, success;
//						datatype x;
//						printf("请输入x:\n");
//						scanf("%d", &x);
//						success = Push_SeqStack(S, x);
//						if (success == 1)
//						{
//							for (i = 0; i <= S->top; i++)
//							{
//								printf("%d ", S->data[i]);
//							}
//						}
//						else
//							printf("stack full!\n");
//					}printf("\n");
//							break;
//					case 3: {//顺序栈出栈
//						int i, success;
//						datatype x, *p;
//						p = &x;
//						success = Pop_SeqStack(S, p);
//						if (success == 1)
//						{
//							for (i = 0; i <= S->top; i++)
//							{
//								printf("%d ", S->data[i]);
//							}
//							printf("出栈1数：%d", x);
//						}
//						else
//							printf("stack empty!\n");
//						printf("\n");
//					}break;
//					}
//				}
//			}
//		}
//		case 3: {//链队相关操作
//			LQueue *Q = NULL;
//			while (t)
//			{
//				printf("\n");
//				printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
//				printf("############   1.初始化    #########\n");
//				printf("############   2.入队      #########\n");
//				printf("############   3.出队      #########\n");
//				printf("############  4.返回上一层 #########\n");
//				printf("############    请选择:    #########\n");
//				printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
//				printf("Please Enter Your Select:>");
//				scanf("%d", &m);
//				if (m == 4)
//					break;
//				else
//				{
//					switch (m)
//					{
//					case 1:Q = Init_LQueue();//链队初始化
//						break;
//					case 2: {//链队入队
//						datatype x;
//						QNode *p;
//						printf("请输入x:\n");
//						scanf("%d", &x);
//						In_LQueue(Q, x);
//						p = Q->front->next;
//						while (p != NULL)
//						{
//							printf("%d", p->data);
//							p = p->next;
//						}
//					}printf("\n");
//							break;
//					case 3: {//链队出队
//						int flag;
//						datatype x, *s;
//						QNode *p;
//						s = &x;
//						flag = Out_LQueue(Q, s);
//						p = Q->front->next;
//						if (flag == 1)
//						{
//							while (p != NULL)
//							{
//								printf("%d ", p->data);
//								p = p->next;
//							}
//							printf("出队为：%d\n", x);
//						}
//						else
//							printf("queue empty!\n");
//					}break;
//					}
//				}
//			}
//		}
//		case 4: {//顺序队的相关操作
//			C_SeQueue *Q=0;
//			while (t)
//			{
//				printf("\n");
//				printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
//				printf("############   1.初始化    #########\n");
//				printf("############   2.入队      #########\n");
//				printf("############   3.出队      #########\n");
//				printf("############  4.返回上一层 #########\n");
//				printf("############    请选择:    #########\n");
//				printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
//				printf("Please Enter Your Select:>");
//				scanf("%d", &m);
//				if (m == 4)
//					break;
//				else
//				{
//					switch (m)
//					{
//					case 1:
//						Q = init_SeQueue(); 
//						break;                  //顺序队初始化
//					case 2: {                                      //顺序队入队
//						int i, flag, number;
//						datatype x;
//						printf("请输入x:\n");
//						scanf("%d", &x);
//						flag = In_SeQueue(Q, x);
//						number = Q->num;
//						if (flag == 1)
//						{
//							for (i = (Q->front + 1) % MAXSIZE; number > 0; number--, i = (i + 1) % MAXSIZE)
//							{
//								printf("%d", Q->data[i]);
//							}
//						}
//						else
//							printf("queue full!\n");
//					}
//							break;
//					case 3: {
//						int i, flag, number;
//						datatype x, *p;
//						p = &x;
//						flag = Out_SeQueue(Q, p);
//						number = Q->num;
//						if (flag == 1)
//						{
//							for (i = (Q->front + 1) % MAXSIZE; number > 0; number--, i = (i + 1) % MAXSIZE)
//							{
//								printf("%d", Q->data[i]);
//							}
//							printf("出队为:%d\n", x);
//						}
//						else
//							printf("queue empty!\n");
//					}break;
//
//					}
//				}
//			}}
//		case 0:return 0;
//		}
//	}
//	system("pause");
//	return 0;
//}




//二叉树

//#include <stdio.h>
//#include<windows.h>
//#include <malloc.h>
//#define MAXSIZE 80
//typedef char DataType;
//#pragma warning (disable:4996)
//typedef struct BiTNode           //二叉链表存储结构
//{
//	DataType data;
//	struct BiTNode *lchild, *rchild;
//}BiTree;
//typedef BiTree* ElemType;           //栈中数据元素类型，栈中保存结点指针
//typedef struct
//{
//	ElemType  data[MAXSIZE];
//	int top;
//}SeqStack;                           //栈的类型定义，顺序栈
//typedef struct
//{
//	ElemType queue[MAXSIZE];
//	int front, rear;
//}SP;
//SeqStack *initSeqStack()                 //初始化栈
//{
//	SeqStack *s;                 //首先建立栈空间，然后初始化栈顶指针
//	s = (SeqStack*)malloc(sizeof(SeqStack));
//	s->top = -1;
//	return s;
//}
//int push(SeqStack *s, ElemType x)
//{
//	if (s->top == MAXSIZE - 1) {         //栈满不能入栈
//		printf("栈满");
//		return 0;
//	}
//	s->top++;
//	s->data[s->top] = x;
//	return 1;
//}
//void pop(SeqStack *s)                       //出栈，假设栈不空
//{
//	s->top--;
//}
//int empty(SeqStack *s)                   //判栈空
//{
//	if (s->top == -1) return 1;
//	else return 0;
//}
//ElemType top(SeqStack *s)                         //取栈顶元素
//{
//	return (s->data[s->top]);
//}
//BiTree *createBiTree()
//{
//	DataType ch;
//	BiTree *T;
//	ch = getchar();
//	if (ch == '*') 
//		return NULL;
//	else {
//		if (!(T = (BiTree*)malloc(sizeof(BiTree)))) {
//			perror("malloc\n");
//		}
//		T->data = ch;
//		T->lchild = createBiTree();
//		T->rchild = createBiTree();
//	}
//	return T;
//}                                          
//void InOrder(BiTree *T)                            //中序遍历二叉树的递归算法
//{
//	if (T)
//	{
//		InOrder(T->lchild);
//		printf("%c", T->data);
//		InOrder(T->rchild);
//	}
//}                                                     //中序遍历二叉树的非递归算法
//void InOrderFei(BiTree *p)
//{
//	SeqStack *s; s = initSeqStack();
//	while (1)
//	{
//		while (p) { push(s, p); p = p->lchild; }         //先将结点指针压栈，待出栈时再访问
//		if (empty(s))
//			break;
//		p = top(s); pop(s); 
//		printf("%c", p->data); p = p->rchild;
//	}
//}
//void LevelOrder(BiTree *T) {
//	SP *p;
//	p = (SP*)malloc(sizeof(SP));
//	p->front = 0;
//	p->rear = 0;
//	if (T != NULL) {
//		p->queue[p->front] = T;
//		p->front = p->front + 1;
//	}
//	while (p->front != p->rear) {
//		T = p->queue[p->rear];
//		p->rear = p->rear + 1;
//		printf("%c", T->data);
//		if (T->lchild != NULL) {
//			p->queue[p->front] = T->lchild;            //左孩子进队列
//			p->front = p->front + 1;
//		}
//		if (T->rchild != NULL) {
//			p->queue[p->front] = T->rchild;           //右孩子进队列
//			p->front = p->front + 1;
//		}
//	}
//}                                                  //求二叉树的高度
//int height(BiTree *T)
//{
//	int i, j;
//	if (!T)
//		return 0;
//	i = height(T->lchild);                        //求左子树的高度
//	j = height(T->rchild);                       // 求右子树的高度
//	return  i > j ? i + 1 : j + 1;               //二叉树的高度为左右子树中较高的高度加1
//}
//int Nodes(BiTree *T) {                              //求二叉树的所有结点个数
//	int n1, n2;
//	if (T == NULL)
//		return 0;
//	else if (T->lchild == NULL && T->rchild == NULL)return 1;
//	else {
//		n1 = Nodes(T->lchild);
//		n2 = Nodes(T->rchild);
//		return n1 + n2 + 1;
//	}
//}                                                 //求二叉树的叶子结点个数
//int leafs(BiTree *T)
//{
//	int num1, num2;
//	if (T == NULL) return 0;
//	else {
//		if (T->lchild == NULL && T->rchild == NULL) return 1;
//		num1 = leafs(T->lchild);                          //求左子树中叶子结点数
//		num2 = leafs(T->rchild);                         //求右子树中叶子结点数
//		return num1 + num2;
//	}
//}
//void exchange(BiTree *T)
//{
//	BiTree *temp = NULL;
//	if (T->lchild == NULL && T->rchild == NULL)
//		return ;
//	else {
//		temp = T->lchild;
//		T->lchild = T->rchild;
//		T->rchild = temp;
//	}
//	if (T->lchild)
//		exchange(T->lchild);
//	if (T->rchild)
//		exchange(T->rchild);
//}
//int main()
//{
//	BiTree*bt; 
//	bt = NULL;
//	int n;
//	while (1) {
//		printf("############################################################\n");
//		printf("############################################################\n");
//		printf("~~~~~~~~~~~~~~~~~    1.递归-创建二叉链表    ~~~~~~~~~~~~~~~~\n");
//		printf("~~~~~~~~~~~~~~~~~    2.递归-中序遍历二叉树  ~~~~~~~~~~~~~~~~\n");
//		printf("~~~~~~~~~~~~~~~~~   3.非递归-中序遍历二叉树  ~~~~~~~~~~~~~~~\n");
//		printf("~~~~~~~~~~~~~~~~~    4.层次-遍历二叉树       ~~~~~~~~~~~~~~~\n");
//		printf("~~~~~~~~~~~~~~~~~    5.二叉树的高度          ~~~~~~~~~~~~~~~\n");
//		printf("~~~~~~~~~~~~~~~~~    6.二叉树的结点个数      ~~~~~~~~~~~~~~~\n");
//		printf("~~~~~~~~~~~~~~~~~    7.二叉树的叶子结点个数  ~~~~~~~~~~~~~~~\n");
//		printf("~~~~~~~~~~~~~~~~~ 8.交换二叉树的所有左右子树 ~~~~~~~~~~~~~~~\n");
//		printf("~~~~~~~~~~~~~~~~~    0.退出系统              ~~~~~~~~~~~~~~~\n");
//		printf("############################################################\n");
//		printf("############################################################\n");
//		printf("please enter your select:>");
//		scanf("%d", &n); 
//		getchar();
//		switch (n) {
//		case 1:
//			printf("请输入结点的先序序列创建二叉树,其中*表示空: \n");
//			bt = createBiTree();
//			break;
//		case 2:printf("递归-中序遍历二叉树:\n");
//			InOrder(bt); 
//			printf("\n"); break;
//		case 3:printf("非递归-中序遍历二叉树\n");
//			inorderfei(bt); 
//			printf("\n"); break;
//		case 4:printf("按层次遍历二叉树:");
//			levelorder(bt); 
//			printf("\n"); break;
//		case 5:printf("二叉树的高度为:%d\n", height(bt));
//			printf("\n"); break;
//		case 6:printf("二叉树的结点数为:%d\n", nodes(bt)); 
//			printf("\n"); break;
//		case 7:printf("二叉树中叶子结点数为:%d\n", leafs(bt)); break;
//		case 8:printf("交换二叉树的所有左右子树\n"); 
//			printf("\n");
//			exchange(bt); 
//			printf("交换后以中序遍历二叉树\n");
//			inorder(bt);
//			printf("\n\n");
//			break;
//		case 0:
//			printf("即将退出系统！\n");break;
//		default:
//			printf("输入错误！"); break;
//		}
//	}
//	system("pause");
//	return 0;
//}






//查找

//#include <stdio.h>
//#include <malloc.h>
//#pragma warning (disable:4996)
//typedef struct Node
//{
//	int data;
//	struct Node *lchild, *rchild;
//}NodeType;
//typedef struct
//{
//	int num;
//}datatype;
//typedef struct
//{
//	datatype *data;
//	int length;
//}S_TBL;
//int SearchData(NodeType *T, NodeType **p, NodeType **q, int kx)
//{
//	int flag = 0;
//	*q = T;
//	while (*q) {
//		if (kx > (*q)->data)
//		{
//			*p = *q;
//			*q = (*q)->rchild;
//		}
//		else {
//			if (kx < (*q)->data) {
//				*p = *q;
//				*q = (*q)->lchild;
//			}
//			else {
//				flag = 1;
//				break;
//			}
//		}
//	}
//	return flag;
//}
//int InsertNode(NodeType **T, int kx) {
//	int flag = 0;
//	NodeType *p = *T, *q, *s;
//	if (!SearchData(*T, &p, &q, kx))
//	{
//		s = (NodeType*)malloc(sizeof(NodeType));
//		s->data = kx;
//		s->lchild = NULL;
//		s->rchild = NULL;
//		if (p == NULL) {
//			*T = s;
//		}
//		else {
//			if (kx > p->data)
//				p->rchild = s;
//			else
//				p->lchild = s;
//		}
//		flag = 1;
//	}
//	return flag;
//}
//int  DeleteNode(NodeType **T, int kx)
//{
//	int flag = 0;
//	NodeType *p = *T, *q, *s, **f;
//	if (SearchData(*T, &p, &q, kx))
//	{
//		if (p == q)
//		{
//			f = T;
//		}
//		else
//		{
//			f = &(p->lchild);
//			if (kx > p->data)
//				f = &(p->rchild);
//		}
//		if (q->rchild == NULL)
//		{
//			*f = q->lchild;
//		}
//		else
//		{
//			if (q->lchild == NULL)
//			{
//				*f = q->rchild;
//			}
//			else
//			{
//				p = q->rchild;
//				s = p;
//				while (p->lchild)
//				{
//					s = p;
//					p = p->lchild;
//				}
//				*f = p;
//				p->lchild = q->lchild;
//				if (s != p)
//				{
//					s->lchild = p->rchild;
//					p->rchild = q->rchild;
//				}
//			}
//		}
//		free(q);
// //  	flag = 1;
//	}
//	return flag;
//}
//void InOrder(NodeType *bt)
//{
//	if (bt == NULL)
//		return;
//	InOrder(bt->lchild);
//	printf("\t%5d", bt->data);
//	InOrder(bt->rchild);
//}
//int Binary_Search(S_TBL *tbl, int kx) {
//	int low, high, mid, flag;
//	flag = 0;
//	low = 1;
//	high = tbl->length;
//	while (low <= high)
//	{
//		mid = (low + high) / 2;
//		if (kx < tbl->data[mid].num)
//		{
//			high = mid - 1;
//		}
//		else if (kx > tbl->data[mid].num)
//		{
//			low = mid + 1;
//		}
//		else
//		{
//			flag = mid;
//			break;
//		}
//	}
//	return flag;
//}
//void menu()
//{
//	printf("################################################\n");
//	printf("################################################\n");
//	printf("####    1.用折半查找法查找一个已知关键字    ####\n");
//	printf("####  2.随机产生一组关键字，建立二叉排序树  ####\n");
//	printf("####    3.删除指定关键字元素                ####\n");
//	printf("################################################\n");
//	printf("################################################\n");
//	printf("please enter your select:>");
//}
//
//void main()
//{
//	int n, m = 1;
//	NodeType *T = NULL;
//	while (m)
//	{
//		menu();
//		scanf("%d", &n);
//		switch (n)
//		{
//		case 1:
//		{
//			int i, flag;
//			int kx;
//			S_TBL *tbl = (S_TBL *)malloc(sizeof(S_TBL));
//			printf("\t关键字长度m=");
//			scanf("%d", &(tbl->length));
//			tbl->data = (datatype *)calloc(tbl->length, sizeof(datatype));
//			printf("\t输入元素:");
//			for (i = 1; i <= tbl->length; i++)
//			{
//				scanf("%d", &((tbl->data[i]).num));
//			}
//			printf("\t输入要查找的数:");
//			scanf("%d", &kx);
//			flag = Binary_Search(tbl, kx);
//			if (flag == 0)
//			{
//				printf("\t查找错误\n");
//			}
//			else
//			{
//				printf("\t该关键字序号为%6d\n", flag);
//			}break;
//		}
//		case 2: /*插入并建立二叉树*/
//		{
//			int flag;
//			int kx;
//			printf("\t请输入一组数据(以000结尾):");
//			scanf("%d", &kx);
//			while (kx != 000) {
//				flag = InsertNode(&T, kx);
//				if (flag == 0)
//				{
//					printf("插入失败\n");
//					break;
//				}
//				scanf("%d", &kx);
//			}
//			printf("二叉排序树为:\n");
//			{
//				InOrder(T);
//				printf("\n");
//				break;
//			}
//		}
//		case 3:
//		{ /*删除二叉树上的结点*/
//			int flag;
//			int kx;
//			printf("\t输入要删除的关键字元素:");
//			scanf("%d", &kx);
//			flag = DeleteNode(&T, kx);
//			if (flag == 0)
//			{
//				printf("\t删除失败\n");
//			}
//			else
//			{
//				printf("\t删除成功\n");
//			}
//			printf("删除关键字元素后二叉排序树为:\n");
//			{
//				InOrder(T);
//				printf("\n");
//				break;
//			}}
//		}
//	}
//}




//课设--------二叉树的遍历

#include <stdio.h>
#include<windows.h>
#include <malloc.h>
#define MAXSIZE 80
typedef char DataType;
#pragma warning (disable:4996)
typedef struct BiTNode                 //二叉链表存储结构
{
	DataType data;
	struct BiTNode *lchild, *rchild;
}BiTree;
typedef BiTree *ElemType;
typedef struct                       //栈中数据元素类型，栈中保存结点指针
{
	ElemType  data[MAXSIZE];
	int top;
}SeqStack;                          
typedef struct                             //栈的类型定义，顺序栈
{
	ElemType queue[MAXSIZE];
	int front, rear;
}SP;
SeqStack *initSeqStack()                 //初始化栈
{
	SeqStack *s;                    //首先建立栈空间，然后初始化栈顶指针
	s = (SeqStack*)malloc(sizeof(SeqStack));
	s->top = -1;
	return s;
}
int push(SeqStack *s, ElemType x)             //进栈
{
	if (s->top == MAXSIZE - 1) {             //栈满不能入栈
		printf("栈满");
		return 0;
	}
	s->top++;                               
	s->data[s->top] = x;
	return 1;
}
void pop(SeqStack *s)                       //出栈，假设栈不空
{
	s->top--;
}
int empty(SeqStack *s)                           //判栈空
{
	if (s->top == -1)
		return 1;
	else
		return 0;
}
ElemType Gettop(SeqStack *s)                                   //取栈顶元素
{
	if (empty(s))
		return 0;
	else
		return s->data[s->top];
}
BiTree *createBiTree()                            //二叉树建立
{
	DataType ch;
	BiTree *T;
	ch = getchar();
	if (ch == '*') 
		return NULL;
	else {
		if (!(T = (BiTree*)malloc(sizeof(BiTree)))) {
			perror("malloc\n");
		}
		T->data = ch;
		T->lchild = createBiTree();
		T->rchild = createBiTree();
	}
	return T;
}                                          
void PreOrder(BiTree *T)                      //先序遍历二叉树
{
	if (T)
	{
		printf("%c", T->data);
		PreOrder(T->lchild);
		PreOrder(T->rchild);
	}
}
void InOrder(BiTree *T)                         //中序遍历二叉树的递归算法
{
	if (T)
	{
		InOrder(T->lchild);
		printf("%c", T->data);
		InOrder(T->rchild);
	}
}                       
void LasOrder(BiTree *T)                       //后序遍历二叉树
{
	if (T) {
		LasOrder(T->lchild);
		LasOrder(T->rchild);
		printf("%c",T->data);
	}
}
int main()
{
	BiTree *bt; 
	bt = NULL;
	int n;
	while (1) {
		printf("############################################################\n");
		printf("############################################################\n");
		printf("~~~~~~~~~~~~~~~~~    1.递归-创建二叉链表    ~~~~~~~~~~~~~~~~\n");
		printf("~~~~~~~~~~~~~~~~~    2.先序遍历二叉树       ~~~~~~~~~~~~~~~~\n");
		printf("~~~~~~~~~~~~~~~~~    3.中序遍历二叉树       ~~~~~~~~~~~~~~~~\n");
		printf("~~~~~~~~~~~~~~~~~    4.后序遍历二叉树       ~~~~~~~~~~~~~~~~\n");
		printf("~~~~~~~~~~~~~~~~~    0.退出系统              ~~~~~~~~~~~~~~~\n");
		printf("############################################################\n");
		printf("############################################################\n");
		printf("please enter your select:>");
		scanf("%d", &n); 
		getchar();
		switch (n) {
		case 1:
			printf("请输入结点的先序序列创建二叉树,其中*表示空: \n");
			bt = createBiTree();
			break;
		case 2:printf("先序遍历二叉树:\n");
			PreOrder(bt);
			printf("\n"); break;
		case 3:printf("中序遍历二叉树\n");
			InOrder(bt);
			printf("\n"); break;
		case 4:printf("后序遍历二叉树\n");
			LasOrder(bt);
			printf("\n"); break;
		case 0:
			printf("即将退出系统！\n");
			printf("\n"); break;
		default:
			printf("输入错误！"); 
			printf("请重新输入0-4之间任意整数进行选择:>\n");
			printf("\n"); break;
		}
	}
	system("pause");
	return 0;
}
