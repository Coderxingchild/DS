#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
using namespace std;

typedef int Ldatatype;

//双向循环链表-带头节点


typedef struct ListNode{
	Ldatatype _data;
	ListNode* _prev;      //前驱
	ListNode* _next;      //后继
}ListNode;

typedef struct List {
	ListNode* _head;
}List;

void List_Init(List* lst)
{
	lst->_head = (ListNode*)malloc(sizeof(ListNode));
	lst->_head->_prev = lst->_head->_next = lst->_head;           //初始化为只带头节点双向循环链表
}
ListNode* creatNode(Ldatatype val)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->_data = val;
	node->_next = node->_prev = NULL;
	return node;
}
void List_pushback(List* lst, Ldatatype val)        //尾插
{
	ListNode* tail = lst->_head->_prev;
	ListNode* newnode = creatNode(val);
	tail->_next = newnode;
	newnode->_prev = tail;
	lst->_head->_prev = newnode;
	newnode->_next = lst->_head;

	//List_insert(lst->_head, val);
}
void List_pop(List* lst)                  //尾删
{
	if (lst->_head->_prev == lst->_head)
		return;        //空链表
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
void List_pushfront(List* lst, Ldatatype val)       //头插
{
	ListNode* cur = creatNode(val);
	ListNode* next = lst->_head->_next;
	lst->_head->_next = cur;
	cur->_prev = lst->_head;
	cur->_next = next;
	next->_prev = cur;

	/*List_insert(lst->_head->_next, val);*/
}
void List_popfront(List* lst)     //头删
{
	if (lst->_head->_next = lst->_head)
		return;         //空链表
	ListNode* next = lst->_head->_next;
	//if (next->_next = lst->_head)
		//lst->_head->_prev = lst->_head->_next = lst->_head;     //只有一个节点
	
	lst->_head->_next = next->_next;   //满足只有一个节点时的删除操作
	next->_next->_prev = lst->_head;
	free(next);
}
void List_insert(ListNode* node, Ldatatype val)  //任意位置插入
{
	//node节点之前插入新节点
	ListNode* newnode = creatNode(val);
	ListNode* prev = node->_prev;

	newnode->_prev = prev;
	prev->_next = newnode;
	node->_prev = newnode;
	newnode->_next = node;
}
void List_erase(ListNode* node)    //任意位置删除
{
	ListNode*prev = node->_prev;
	ListNode*next = node->_next;
	prev->_next = next;
	next->_prev = prev;
	free(node);
}
void List_destory(List* lst)
{
	ListNode* cur = lst->_head->_next;     //第一个有效节点
	while (cur != lst->_head) {
		ListNode* next = cur->_next;
		free(cur);
		cur = next;
	}
	free(lst->_head);
	lst->_head = NULL;
}
