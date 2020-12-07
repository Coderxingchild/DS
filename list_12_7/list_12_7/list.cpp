#include<stdlib.h>
#include<stdio.h>

typedef int LDataType;

typedef struct ListNode {
	LDataType _data;
	ListNode* _next;             //带头结点的非循环单链表
}ListNode;

typedef struct list {
	ListNode* _head;         //头节点
}list;

ListNode* creatListNode(LDataType val)        //创建节点
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->_data = val;
	node->_next = NULL;
	return node;
}
void list_init(list* lst) //初始化
{
	if (lst == NULL)
		return;
	lst->_head = NULL;      //空链表
}
void list_pushback(list* lst, LDataType val)      //尾插     O(n)
{
	if (lst == NULL)
		return;
	//创建第一个节点，需要先开辟空间
	if (lst->_head == NULL) {
		lst->_head = creatListNode(val);
	}
	else {
		//遍历找到最后一个节点
		ListNode* tail = lst->_head;
		while (tail->_next != NULL) {
			tail = tail->_next;
		}        
		tail->_next = creatListNode(val);                  
	}
}
void list_popback(list* lst)     //尾删		O(n)
{
	if (lst == NULL || lst->_head == NULL)
		return;
	ListNode* prew = NULL;
	ListNode* tail = lst->_head;
	while(tail->_next != NULL) {
		prew = tail;
		tail = tail->_next;
	}
	free(tail);
	if (prew == NULL)
		lst->_head = NULL;      //只有一个节点
	else{
		prew->_next = NULL;
	}
}
void list_pushfront(list* lst, LDataType val)    //头插     O(1)
{
	if (lst == NULL)
		return;
	ListNode* node = creatListNode(val);
	node->_next = lst->_head;        
	lst->_head = node;            //更换头节点
}
void list_popfront(list* lst)         //头删     O(1)
{
	if (lst == NULL || lst->_head == NULL)
		return;
	ListNode* next = lst->_head->_next;
	free(lst->_head);
	lst->_head = next;
}
void list_insertafter(ListNode* node, LDataType val)    //给某一个node节点后插入
{
	if (node == NULL)
		return;
	ListNode* newnode = creatListNode(val);
	ListNode* next = node->_next;
	node->_next = newnode;
	newnode->_next = next;
}
void list_earseafter(ListNode* node)          //删除节点的下一个节点
{
	if (node == NULL || node->_next == NULL)
		return;
	ListNode* next = node->_next;              //node 的下一个节点---------要删除的节点
	ListNode* nextnext = next->_next;
	free(next);
	node->_next = nextnext;
}
ListNode* list_find(list* lst, LDataType val)     //查找
{
	if (lst == NULL || lst->_head == NULL)
		return;
	ListNode* cur = lst->_head;
	while (cur)
	{
		if (cur->_data == val) {
			return cur;
		}
		cur = cur->_next;
	}
	return NULL;
}
void list_destory(list* lst)
{
	//code1
	/*if (lst == NULL)
		return;
	ListNode* cur = lst->_head;
	while (cur) {
		ListNode* next = cur->_next;
		free(cur);
		cur = next;
	}
	lst->_head = NULL;*/

	//code2
	if (lst == NULL || lst->_head == NULL)
		return;
	ListNode* next = lst->_head->_next;
	ListNode* nextnext = next->_next;
	while (next != NULL) {
		free(next);
		lst->_head->_next = nextnext;

		next = nextnext;
		nextnext = next->_next;
	}
	free(lst->_head);
	lst->_head = NULL;
}

////////////////////////////////////////？？？？？？
void list_earse(list* lst,ListNode* node)      //删除任意一个节点
{
	if (node == NULL)     //要删除的当前的节点为空
		return;
	ListNode* start = lst->_head;
	ListNode* cur = start->_next;
	while (start != node) {
		
		start = start->_next;
	}
	if (start == node) {
		free(start);
		start = cur;
	}
}




