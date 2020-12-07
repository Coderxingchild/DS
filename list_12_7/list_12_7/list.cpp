#include<stdlib.h>
#include<stdio.h>

typedef int LDataType;

typedef struct ListNode {
	LDataType _data;
	ListNode* _next;             //��ͷ���ķ�ѭ��������
}ListNode;

typedef struct list {
	ListNode* _head;         //ͷ�ڵ�
}list;

ListNode* creatListNode(LDataType val)        //�����ڵ�
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->_data = val;
	node->_next = NULL;
	return node;
}
void list_init(list* lst) //��ʼ��
{
	if (lst == NULL)
		return;
	lst->_head = NULL;      //������
}
void list_pushback(list* lst, LDataType val)      //β��     O(n)
{
	if (lst == NULL)
		return;
	//������һ���ڵ㣬��Ҫ�ȿ��ٿռ�
	if (lst->_head == NULL) {
		lst->_head = creatListNode(val);
	}
	else {
		//�����ҵ����һ���ڵ�
		ListNode* tail = lst->_head;
		while (tail->_next != NULL) {
			tail = tail->_next;
		}        
		tail->_next = creatListNode(val);                  
	}
}
void list_popback(list* lst)     //βɾ		O(n)
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
		lst->_head = NULL;      //ֻ��һ���ڵ�
	else{
		prew->_next = NULL;
	}
}
void list_pushfront(list* lst, LDataType val)    //ͷ��     O(1)
{
	if (lst == NULL)
		return;
	ListNode* node = creatListNode(val);
	node->_next = lst->_head;        
	lst->_head = node;            //����ͷ�ڵ�
}
void list_popfront(list* lst)         //ͷɾ     O(1)
{
	if (lst == NULL || lst->_head == NULL)
		return;
	ListNode* next = lst->_head->_next;
	free(lst->_head);
	lst->_head = next;
}
void list_insertafter(ListNode* node, LDataType val)    //��ĳһ��node�ڵ�����
{
	if (node == NULL)
		return;
	ListNode* newnode = creatListNode(val);
	ListNode* next = node->_next;
	node->_next = newnode;
	newnode->_next = next;
}
void list_earseafter(ListNode* node)          //ɾ���ڵ����һ���ڵ�
{
	if (node == NULL || node->_next == NULL)
		return;
	ListNode* next = node->_next;              //node ����һ���ڵ�---------Ҫɾ���Ľڵ�
	ListNode* nextnext = next->_next;
	free(next);
	node->_next = nextnext;
}
ListNode* list_find(list* lst, LDataType val)     //����
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

////////////////////////////////////////������������
void list_earse(list* lst,ListNode* node)      //ɾ������һ���ڵ�
{
	if (node == NULL)     //Ҫɾ���ĵ�ǰ�Ľڵ�Ϊ��
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




