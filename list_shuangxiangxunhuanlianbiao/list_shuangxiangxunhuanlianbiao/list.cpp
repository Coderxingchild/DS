#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
using namespace std;

typedef int Ldatatype;

//˫��ѭ������-��ͷ�ڵ�


typedef struct ListNode{
	Ldatatype _data;
	ListNode* _prev;      //ǰ��
	ListNode* _next;      //���
}ListNode;

typedef struct List {
	ListNode* _head;
}List;

void List_Init(List* lst)
{
	lst->_head = (ListNode*)malloc(sizeof(ListNode));
	lst->_head->_prev = lst->_head->_next = lst->_head;           //��ʼ��Ϊֻ��ͷ�ڵ�˫��ѭ������
}
ListNode* creatNode(Ldatatype val)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->_data = val;
	node->_next = node->_prev = NULL;
	return node;
}
void List_pushback(List* lst, Ldatatype val)        //β��
{
	ListNode* tail = lst->_head->_prev;
	ListNode* newnode = creatNode(val);
	tail->_next = newnode;
	newnode->_prev = tail;
	lst->_head->_prev = newnode;
	newnode->_next = lst->_head;

	//List_insert(lst->_head, val);
}
void List_pop(List* lst)                  //βɾ
{
	if (lst->_head->_prev == lst->_head)
		return;        //������
	ListNode* tail = lst->_head->_prev;
	ListNode* prev = tail->_prev;
	free(tail);
	prev->_next = lst->_head;
	lst->_head->_prev = prev;
}
void List_print(List* lst)
{
	ListNode*cur = lst->_head->_next;
	while (cur != lst->_head) {
		cout << cur->_data;
		cur = cur->_next;
	}
	cout << endl;
}
void List_pushfront(List* lst, Ldatatype val)       //ͷ��
{
	ListNode* cur = creatNode(val);
	ListNode* next = lst->_head->_next;
	lst->_head->_next = cur;
	cur->_prev = lst->_head;
	cur->_next = next;
	next->_prev = cur;

	/*List_insert(lst->_head->_next, val);*/
}
void List_popfront(List* lst)     //ͷɾ
{
	if (lst->_head->_next = lst->_head)
		return;         //������
	ListNode* next = lst->_head->_next;
	//if (next->_next = lst->_head)
		//lst->_head->_prev = lst->_head->_next = lst->_head;     //ֻ��һ���ڵ�
	
	lst->_head->_next = next->_next;   //����ֻ��һ���ڵ�ʱ��ɾ������
	next->_next->_prev = lst->_head;
	free(next);
}
void List_insert(ListNode* node, Ldatatype val)  //����λ�ò���
{
	//node�ڵ�֮ǰ�����½ڵ�
	ListNode* newnode = creatNode(val);
	ListNode* prev = node->_prev;

	newnode->_prev = prev;
	prev->_next = newnode;
	node->_prev = newnode;
	newnode->_next = node;
}
void List_erase(ListNode* node)    //����λ��ɾ��
{
	ListNode*prev = node->_prev;
	ListNode*next = node->_next;
	prev->_next = next;
	next->_prev = prev;
	free(node);
}
void List_destory(List* lst)
{
	ListNode* cur = lst->_head->_next;     //��һ����Ч�ڵ�
	while (cur != lst->_head) {
		ListNode* next = cur->_next;
		free(cur);
		cur = next;
	}
	free(lst->_head);
	lst->_head = NULL;
}
