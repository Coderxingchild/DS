
//������Ľ��������á����롢ɾ�����ϲ��Ȳ���

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
//void Createheadlist(Linklist &L) //����һ����ͷ���ĵ�����
//{
//	Node *p, *s;
//	ElemType x;
//	L = (Linklist)malloc(sizeof(Node));    //��̬�ռ�����
//	L->next = NULL;
//	p = L;
//	printf("�������������Ԫ��:>\n");
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
//	printf("����ͷ�ڵ�ĵ��������ɹ���\n");
//	printf("////////////////////////////////////////////////////////////////////////////////\n");
//	printf("////////////////////////////////////////////////////////////////////////////////\n");
//}
//void printlist(Linklist L)       //���������������
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
//void reverse(Linklist &L)         //���õ�����
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
//void Insertelement(Linklist &L, ElemType x)   //�ڷǵݼ����������в���һ��Ԫ��ʹ������Ȼ����
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
//void Createundecrease(Linklist &L)     //����һ���ǵݼ���������
//{
//	ElemType y;
//	L = (Linklist)malloc(sizeof(Node));
//	L->next = NULL;
//	printf("������0��������������:\n");
//	scanf("%d", &y);
//	while (y) {
//		Insertelement(L, y);
//		scanf("%d", &y);
//	}
//}
//Linklist combine(Linklist LA, Linklist LB)
////����������ĵ�����LA��LB�ϲ���һ����������ĵ�����LC
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
//	if (pa)                  //����LAδ�꣬����LA�к���Ԫ�������±�LC��β
//		r->next = pa;
//	else                     //���򽫱�LB�к���Ԫ�������±�LC��β
//		r->next = pb;
//	free(LB);
//	return(LC);
//}
//void Deletelement(Linklist &L, ElemType x)    //�ڷǵݼ�����������ɾ��ֵΪx�Ľ��
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
//	printf("################                  ������Ĳ���                ##################\n");
//	printf("################             1.������������0����            ##################\n");
//	printf("################             2.����������                     ##################\n");
//	printf("################             3.�ѵ���������Ԫ������           ##################\n");
//	printf("################             4.����һ���ǵݼ���������       ##################\n");
//	printf("################   5.���������ǵݼ���������Ȼ��ϲ���һ���ǵݼ�����   ######\n");
//	printf("################   6.�ڷǵݼ����������в���һ��Ԫ����Ȼ����  #################\n");
//	printf("################   7.�ڷǵݼ�����������ɾ��ָ����Ԫ��          #################\n");
//	printf("################             0.�˳�����                        #################\n");
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
//			printf("���������ĵ������ǣ�\n");
//			printlist(L1); 
//			printf("////////////////////////////////////////////////////////////////////////////////\n");
//			break;
//		case 3:
//			printf("���ú�ĵ�����Ϊ��\n");
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
//			printf("������ A ��Ԫ��Ϊ:\n");
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
//			printf("������ B ��Ԫ��Ϊ:\n");
//			p = L2->next;
//			while (p != NULL)
//			{
//				printf("%d", p->data);
//				p = p->next;
//			}
//			printf("\n");
//			L3 = combine(L1, L2);
//			printf("������ C ��Ԫ��Ϊ:\n");
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
//			printf("����������Ҫ�����Ԫ�� x :");
//			scanf("%d", &x);
//			Insertelement(L1, x);
//			printlist(L1); 
//			printf("////////////////////////////////////////////////////////////////////////////////\n");
//			break;
//		case 7:Createundecrease(L1);
//			printlist(L1);
//			printf("����������Ҫɾ����Ԫ�� x :");
//			scanf("%d", &x);
//			Deletelement(L1, x);
//			printlist(L1); 
//			printf("////////////////////////////////////////////////////////////////////////////////\n");
//			break;
//		case 0:
//			printf("�˳�����\n");
//			break;
//		default:printf("Select error! Please Enter your select again: >"); 
//			printf("\n");
//			break;
//		}
//	}
//}




//ջ�����---------��ջ��˳��ջ�����ӡ�˳���

//#include<stdio.h>
//#include<stdlib.h>    
//#include <malloc.h>
//#include<windows.h>
//#pragma warning(disable:4996)
//#define MAXSIZE 256
//typedef int datatype; 
//typedef struct node                //������ջ
//{
//	datatype data;
//	struct node *next;
//}StackNode, QNode, *LinkStack;
//typedef struct                    //����˳��ջ
//{
//	datatype data[MAXSIZE];
//	int front, rear;
//	int num;
//	int top;
//}SeqStack, C_SeQueue;
//typedef struct                   //��������
//{
//	QNode *front, *rear;
//}LQueue;
//LinkStack Init_LinkStack()      //��ջ��ʼ������
//{
//	StackNode *L;
//	L = (StackNode*)malloc(sizeof(StackNode));
//	L->data = -32767;
//	L->next = NULL;
//	return L;
//}
//LinkStack Push_LinkStack(LinkStack top, datatype x)  //��ջ��ջ����
//{
//	StackNode *s;
//	s = (StackNode*)malloc(sizeof(StackNode));
//	s->data = x;
//	s->next = top->next;
//	top->next = s;
//	return top;
//}
//LinkStack Pop_LinkStack(LinkStack top, datatype *s)   //��ջ��ջ����
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
//SeqStack * init_SeqStack()                           //˳��ջ��ʼ������
//{
//	SeqStack *S;
//	S = (SeqStack*)malloc(sizeof(SeqStack));
//	S->top = -1;
//	return S;
//}
//int Push_SeqStack(SeqStack *S, datatype x)          //˳��ջ��ջ����
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
//int Pop_SeqStack(SeqStack *S, datatype *p)            //˳��ջ��ջ����
//{
//	{
//		*p = S->data[S->top];
//		S->top--;
//		return 1;
//	}
//}
//LQueue *Init_LQueue()                             //���ӳ�ʼ������
//{
//	LQueue *q;
//	QNode *p;
//	q = (LQueue*)malloc(sizeof(LQueue));
//	p = (QNode*)malloc(sizeof(QNode));
//	p->next = NULL;
//	q->front = q->rear = p;
//	return q;
//}
//void In_LQueue(LQueue *q, datatype x)              //������Ӻ���
//{
//	QNode *p;
//	p = (QNode*)malloc(sizeof(QNode));
//	p->data = x;
//	p->next = NULL;
//	q->rear->next = p;
//	q->rear = p;
//}
//int Out_LQueue(LQueue *q, datatype *s)              //���ӳ��Ӻ���
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
//C_SeQueue *init_SeQueue()                       //˳��ӳ�ʼ������
//{
//	C_SeQueue *q;
//	q = (C_SeQueue*)malloc(sizeof(C_SeQueue));
//	q->front = q->rear = MAXSIZE - 1;
//	q->num = 0;
//	return q;
//}
//int In_SeQueue(C_SeQueue *q, datatype x)            //˳�����Ӻ���
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
//int Out_SeQueue(C_SeQueue *q, datatype *p)                 //˳��ӳ���
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
//C_SeQueue *init_SeQueue();                            //˳��ӳ�ʼ��
//
//int In_SeQueue(C_SeQueue *q, datatype x);             //˳������
//int Out_SeQueue(C_SeQueue *q, datatype *p);          //˳��ӳ���
//int main() {
//	int n, m, t = 1;
//	while (t)
//	{
//		printf("\n");
//		printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
//		printf("###########     1.��ջ     #########\n");
//		printf("###########     2.˳��ջ   #########\n");
//		printf("###########     3.����     #########\n");
//		printf("###########     4.˳���   #########\n");
//		printf("###########     0.����     #########\n");
//		printf("###########     ��ѡ��:    #########\n");
//		printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
//		printf("Please Enter Your Select:>");
//		scanf("%d", &n);
//		switch (n)
//		{
//		case 1://ѡ����ջ��ز���
//		{
//			LinkStack  L = NULL;
//			while (t)
//			{
//				printf("\n");
//				printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
//				printf("###########     1.��ʼ��   #########\n");
//				printf("###########     2.��ջ     #########\n");
//				printf("###########     3.��ջ     #########\n");
//				printf("###########  4.������һ��  #########\n");
//				printf("###########     ��ѡ��:    #########\n");
//				printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
//				printf("Please Enter Your Select:>");
//				scanf("%d", &m);
//				if (m == 4)
//					break;
//				else
//				{
//					switch (m)
//					{
//					case 1: L = Init_LinkStack(); break;//��ջ��ʼ��
//					case 2: {LinkStack p; //��ջ��ջ
//						datatype x;
//						printf("������Ҫ��ջ��Ԫ�� x:\n");
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
//						printf("��ջ1��Ϊ��%d", x);
//						printf("\n");
//						break;
//					}
//					case 4:break;
//					}
//				}
//			}
//		}break;
//		case 2: {//ѡ��˳��ջ��ز���
//			SeqStack *S=0;
//			while (t)
//			{
//				printf("\n");
//				printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
//				printf("~~~~~~~~~~    1.��ʼ��    ~~~~~~~~~~\n");
//				printf("~~~~~~~~~~    2.��ջ1     ~~~~~~~~~~\n");
//				printf("~~~~~~~~~~    3.��ջ1     ~~~~~~~~~~\n");
//				printf("~~~~~~~~~~  4.������һ��  ~~~~~~~~~~\n");
//				printf("~~~~~~~~~~ ���������ѡ�� ~~~~~~~~~~\n");
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
//						S = init_SeqStack(); break;//˳��ջ��ʼ��
//					case 2: {//˳��ջ��ջ
//						int i, success;
//						datatype x;
//						printf("������x:\n");
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
//					case 3: {//˳��ջ��ջ
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
//							printf("��ջ1����%d", x);
//						}
//						else
//							printf("stack empty!\n");
//						printf("\n");
//					}break;
//					}
//				}
//			}
//		}
//		case 3: {//������ز���
//			LQueue *Q = NULL;
//			while (t)
//			{
//				printf("\n");
//				printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
//				printf("############   1.��ʼ��    #########\n");
//				printf("############   2.���      #########\n");
//				printf("############   3.����      #########\n");
//				printf("############  4.������һ�� #########\n");
//				printf("############    ��ѡ��:    #########\n");
//				printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
//				printf("Please Enter Your Select:>");
//				scanf("%d", &m);
//				if (m == 4)
//					break;
//				else
//				{
//					switch (m)
//					{
//					case 1:Q = Init_LQueue();//���ӳ�ʼ��
//						break;
//					case 2: {//�������
//						datatype x;
//						QNode *p;
//						printf("������x:\n");
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
//					case 3: {//���ӳ���
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
//							printf("����Ϊ��%d\n", x);
//						}
//						else
//							printf("queue empty!\n");
//					}break;
//					}
//				}
//			}
//		}
//		case 4: {//˳��ӵ���ز���
//			C_SeQueue *Q=0;
//			while (t)
//			{
//				printf("\n");
//				printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
//				printf("############   1.��ʼ��    #########\n");
//				printf("############   2.���      #########\n");
//				printf("############   3.����      #########\n");
//				printf("############  4.������һ�� #########\n");
//				printf("############    ��ѡ��:    #########\n");
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
//						break;                  //˳��ӳ�ʼ��
//					case 2: {                                      //˳������
//						int i, flag, number;
//						datatype x;
//						printf("������x:\n");
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
//							printf("����Ϊ:%d\n", x);
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




//������

//#include <stdio.h>
//#include<windows.h>
//#include <malloc.h>
//#define MAXSIZE 80
//typedef char DataType;
//#pragma warning (disable:4996)
//typedef struct BiTNode           //��������洢�ṹ
//{
//	DataType data;
//	struct BiTNode *lchild, *rchild;
//}BiTree;
//typedef BiTree* ElemType;           //ջ������Ԫ�����ͣ�ջ�б�����ָ��
//typedef struct
//{
//	ElemType  data[MAXSIZE];
//	int top;
//}SeqStack;                           //ջ�����Ͷ��壬˳��ջ
//typedef struct
//{
//	ElemType queue[MAXSIZE];
//	int front, rear;
//}SP;
//SeqStack *initSeqStack()                 //��ʼ��ջ
//{
//	SeqStack *s;                 //���Ƚ���ջ�ռ䣬Ȼ���ʼ��ջ��ָ��
//	s = (SeqStack*)malloc(sizeof(SeqStack));
//	s->top = -1;
//	return s;
//}
//int push(SeqStack *s, ElemType x)
//{
//	if (s->top == MAXSIZE - 1) {         //ջ��������ջ
//		printf("ջ��");
//		return 0;
//	}
//	s->top++;
//	s->data[s->top] = x;
//	return 1;
//}
//void pop(SeqStack *s)                       //��ջ������ջ����
//{
//	s->top--;
//}
//int empty(SeqStack *s)                   //��ջ��
//{
//	if (s->top == -1) return 1;
//	else return 0;
//}
//ElemType top(SeqStack *s)                         //ȡջ��Ԫ��
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
//void InOrder(BiTree *T)                            //��������������ĵݹ��㷨
//{
//	if (T)
//	{
//		InOrder(T->lchild);
//		printf("%c", T->data);
//		InOrder(T->rchild);
//	}
//}                                                     //��������������ķǵݹ��㷨
//void InOrderFei(BiTree *p)
//{
//	SeqStack *s; s = initSeqStack();
//	while (1)
//	{
//		while (p) { push(s, p); p = p->lchild; }         //�Ƚ����ָ��ѹջ������ջʱ�ٷ���
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
//			p->queue[p->front] = T->lchild;            //���ӽ�����
//			p->front = p->front + 1;
//		}
//		if (T->rchild != NULL) {
//			p->queue[p->front] = T->rchild;           //�Һ��ӽ�����
//			p->front = p->front + 1;
//		}
//	}
//}                                                  //��������ĸ߶�
//int height(BiTree *T)
//{
//	int i, j;
//	if (!T)
//		return 0;
//	i = height(T->lchild);                        //���������ĸ߶�
//	j = height(T->rchild);                       // ���������ĸ߶�
//	return  i > j ? i + 1 : j + 1;               //�������ĸ߶�Ϊ���������нϸߵĸ߶ȼ�1
//}
//int Nodes(BiTree *T) {                              //������������н�����
//	int n1, n2;
//	if (T == NULL)
//		return 0;
//	else if (T->lchild == NULL && T->rchild == NULL)return 1;
//	else {
//		n1 = Nodes(T->lchild);
//		n2 = Nodes(T->rchild);
//		return n1 + n2 + 1;
//	}
//}                                                 //���������Ҷ�ӽ�����
//int leafs(BiTree *T)
//{
//	int num1, num2;
//	if (T == NULL) return 0;
//	else {
//		if (T->lchild == NULL && T->rchild == NULL) return 1;
//		num1 = leafs(T->lchild);                          //����������Ҷ�ӽ����
//		num2 = leafs(T->rchild);                         //����������Ҷ�ӽ����
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
//		printf("~~~~~~~~~~~~~~~~~    1.�ݹ�-������������    ~~~~~~~~~~~~~~~~\n");
//		printf("~~~~~~~~~~~~~~~~~    2.�ݹ�-�������������  ~~~~~~~~~~~~~~~~\n");
//		printf("~~~~~~~~~~~~~~~~~   3.�ǵݹ�-�������������  ~~~~~~~~~~~~~~~\n");
//		printf("~~~~~~~~~~~~~~~~~    4.���-����������       ~~~~~~~~~~~~~~~\n");
//		printf("~~~~~~~~~~~~~~~~~    5.�������ĸ߶�          ~~~~~~~~~~~~~~~\n");
//		printf("~~~~~~~~~~~~~~~~~    6.�������Ľ�����      ~~~~~~~~~~~~~~~\n");
//		printf("~~~~~~~~~~~~~~~~~    7.��������Ҷ�ӽ�����  ~~~~~~~~~~~~~~~\n");
//		printf("~~~~~~~~~~~~~~~~~ 8.������������������������ ~~~~~~~~~~~~~~~\n");
//		printf("~~~~~~~~~~~~~~~~~    0.�˳�ϵͳ              ~~~~~~~~~~~~~~~\n");
//		printf("############################################################\n");
//		printf("############################################################\n");
//		printf("please enter your select:>");
//		scanf("%d", &n); 
//		getchar();
//		switch (n) {
//		case 1:
//			printf("����������������д���������,����*��ʾ��: \n");
//			bt = createBiTree();
//			break;
//		case 2:printf("�ݹ�-�������������:\n");
//			InOrder(bt); 
//			printf("\n"); break;
//		case 3:printf("�ǵݹ�-�������������\n");
//			inorderfei(bt); 
//			printf("\n"); break;
//		case 4:printf("����α���������:");
//			levelorder(bt); 
//			printf("\n"); break;
//		case 5:printf("�������ĸ߶�Ϊ:%d\n", height(bt));
//			printf("\n"); break;
//		case 6:printf("�������Ľ����Ϊ:%d\n", nodes(bt)); 
//			printf("\n"); break;
//		case 7:printf("��������Ҷ�ӽ����Ϊ:%d\n", leafs(bt)); break;
//		case 8:printf("������������������������\n"); 
//			printf("\n");
//			exchange(bt); 
//			printf("���������������������\n");
//			inorder(bt);
//			printf("\n\n");
//			break;
//		case 0:
//			printf("�����˳�ϵͳ��\n");break;
//		default:
//			printf("�������"); break;
//		}
//	}
//	system("pause");
//	return 0;
//}






//����

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
//	printf("####    1.���۰���ҷ�����һ����֪�ؼ���    ####\n");
//	printf("####  2.�������һ��ؼ��֣���������������  ####\n");
//	printf("####    3.ɾ��ָ���ؼ���Ԫ��                ####\n");
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
//			printf("\t�ؼ��ֳ���m=");
//			scanf("%d", &(tbl->length));
//			tbl->data = (datatype *)calloc(tbl->length, sizeof(datatype));
//			printf("\t����Ԫ��:");
//			for (i = 1; i <= tbl->length; i++)
//			{
//				scanf("%d", &((tbl->data[i]).num));
//			}
//			printf("\t����Ҫ���ҵ���:");
//			scanf("%d", &kx);
//			flag = Binary_Search(tbl, kx);
//			if (flag == 0)
//			{
//				printf("\t���Ҵ���\n");
//			}
//			else
//			{
//				printf("\t�ùؼ������Ϊ%6d\n", flag);
//			}break;
//		}
//		case 2: /*���벢����������*/
//		{
//			int flag;
//			int kx;
//			printf("\t������һ������(��000��β):");
//			scanf("%d", &kx);
//			while (kx != 000) {
//				flag = InsertNode(&T, kx);
//				if (flag == 0)
//				{
//					printf("����ʧ��\n");
//					break;
//				}
//				scanf("%d", &kx);
//			}
//			printf("����������Ϊ:\n");
//			{
//				InOrder(T);
//				printf("\n");
//				break;
//			}
//		}
//		case 3:
//		{ /*ɾ���������ϵĽ��*/
//			int flag;
//			int kx;
//			printf("\t����Ҫɾ���Ĺؼ���Ԫ��:");
//			scanf("%d", &kx);
//			flag = DeleteNode(&T, kx);
//			if (flag == 0)
//			{
//				printf("\tɾ��ʧ��\n");
//			}
//			else
//			{
//				printf("\tɾ���ɹ�\n");
//			}
//			printf("ɾ���ؼ���Ԫ�غ����������Ϊ:\n");
//			{
//				InOrder(T);
//				printf("\n");
//				break;
//			}}
//		}
//	}
//}




//����--------�������ı���

#include <stdio.h>
#include<windows.h>
#include <malloc.h>
#define MAXSIZE 80
typedef char DataType;
#pragma warning (disable:4996)
typedef struct BiTNode                 //��������洢�ṹ
{
	DataType data;
	struct BiTNode *lchild, *rchild;
}BiTree;
typedef BiTree *ElemType;
typedef struct                       //ջ������Ԫ�����ͣ�ջ�б�����ָ��
{
	ElemType  data[MAXSIZE];
	int top;
}SeqStack;                          
typedef struct                             //ջ�����Ͷ��壬˳��ջ
{
	ElemType queue[MAXSIZE];
	int front, rear;
}SP;
SeqStack *initSeqStack()                 //��ʼ��ջ
{
	SeqStack *s;                    //���Ƚ���ջ�ռ䣬Ȼ���ʼ��ջ��ָ��
	s = (SeqStack*)malloc(sizeof(SeqStack));
	s->top = -1;
	return s;
}
int push(SeqStack *s, ElemType x)             //��ջ
{
	if (s->top == MAXSIZE - 1) {             //ջ��������ջ
		printf("ջ��");
		return 0;
	}
	s->top++;                               
	s->data[s->top] = x;
	return 1;
}
void pop(SeqStack *s)                       //��ջ������ջ����
{
	s->top--;
}
int empty(SeqStack *s)                           //��ջ��
{
	if (s->top == -1)
		return 1;
	else
		return 0;
}
ElemType Gettop(SeqStack *s)                                   //ȡջ��Ԫ��
{
	if (empty(s))
		return 0;
	else
		return s->data[s->top];
}
BiTree *createBiTree()                            //����������
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
void PreOrder(BiTree *T)                      //�������������
{
	if (T)
	{
		printf("%c", T->data);
		PreOrder(T->lchild);
		PreOrder(T->rchild);
	}
}
void InOrder(BiTree *T)                         //��������������ĵݹ��㷨
{
	if (T)
	{
		InOrder(T->lchild);
		printf("%c", T->data);
		InOrder(T->rchild);
	}
}                       
void LasOrder(BiTree *T)                       //�������������
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
		printf("~~~~~~~~~~~~~~~~~    1.�ݹ�-������������    ~~~~~~~~~~~~~~~~\n");
		printf("~~~~~~~~~~~~~~~~~    2.�������������       ~~~~~~~~~~~~~~~~\n");
		printf("~~~~~~~~~~~~~~~~~    3.�������������       ~~~~~~~~~~~~~~~~\n");
		printf("~~~~~~~~~~~~~~~~~    4.�������������       ~~~~~~~~~~~~~~~~\n");
		printf("~~~~~~~~~~~~~~~~~    0.�˳�ϵͳ              ~~~~~~~~~~~~~~~\n");
		printf("############################################################\n");
		printf("############################################################\n");
		printf("please enter your select:>");
		scanf("%d", &n); 
		getchar();
		switch (n) {
		case 1:
			printf("����������������д���������,����*��ʾ��: \n");
			bt = createBiTree();
			break;
		case 2:printf("�������������:\n");
			PreOrder(bt);
			printf("\n"); break;
		case 3:printf("�������������\n");
			InOrder(bt);
			printf("\n"); break;
		case 4:printf("�������������\n");
			LasOrder(bt);
			printf("\n"); break;
		case 0:
			printf("�����˳�ϵͳ��\n");
			printf("\n"); break;
		default:
			printf("�������"); 
			printf("����������0-4֮��������������ѡ��:>\n");
			printf("\n"); break;
		}
	}
	system("pause");
	return 0;
}
