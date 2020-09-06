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
void PreOrder(BiTree *T)                      //�ݹ�-�������������
{
	if (T)
	{
		printf("%c", T->data);
		PreOrder(T->lchild);
		PreOrder(T->rchild);
	}
}
void InOrder(BiTree *T)                         //�ݹ�-�������������
{
	if (T)
	{
		InOrder(T->lchild);
		printf("%c", T->data);
		InOrder(T->rchild);
	}
}
void LasOrder(BiTree *T)                       //�ݹ�-�������������
{
	if (T) {
		LasOrder(T->lchild);
		LasOrder(T->rchild);
		printf("%c", T->data);
	}
}
int main()
{
	BiTree *bt;
	bt = NULL;
	int n = 1;
	while (n) {
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
		if (0 == n) {
			printf("�����˳�����ϵͳ!\n");
			printf("\n");
			break;
		}
		switch (n) {
		case 1:
			printf("����������������д���������,����*��ʾ��: \n");
			bt = createBiTree();
			break;
		case 2:printf("�������������:\n");
			PreOrder(bt);
			printf("\n");
			break;
		case 3:printf("�������������\n");
			InOrder(bt);
			printf("\n"); 
			break;
		case 4:printf("�������������\n");
			LasOrder(bt);
			printf("\n"); 
			break;
		default:
			printf("�������");
			printf("����������0-4֮��������������ѡ��:>\n");
			printf("\n"); 
			break;
		}
	}
	system("pause");
	return 0;
}