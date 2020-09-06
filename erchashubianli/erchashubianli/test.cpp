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
void PreOrder(BiTree *T)                      //递归-先序遍历二叉树
{
	if (T)
	{
		printf("%c", T->data);
		PreOrder(T->lchild);
		PreOrder(T->rchild);
	}
}
void InOrder(BiTree *T)                         //递归-中序遍历二叉树
{
	if (T)
	{
		InOrder(T->lchild);
		printf("%c", T->data);
		InOrder(T->rchild);
	}
}
void LasOrder(BiTree *T)                       //递归-后序遍历二叉树
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
		if (0 == n) {
			printf("即将退出程序系统!\n");
			printf("\n");
			break;
		}
		switch (n) {
		case 1:
			printf("请输入结点的先序序列创建二叉树,其中*表示空: \n");
			bt = createBiTree();
			break;
		case 2:printf("先序遍历二叉树:\n");
			PreOrder(bt);
			printf("\n");
			break;
		case 3:printf("中序遍历二叉树\n");
			InOrder(bt);
			printf("\n"); 
			break;
		case 4:printf("后序遍历二叉树\n");
			LasOrder(bt);
			printf("\n"); 
			break;
		default:
			printf("输入错误！");
			printf("请重新输入0-4之间任意整数进行选择:>\n");
			printf("\n"); 
			break;
		}
	}
	system("pause");
	return 0;
}