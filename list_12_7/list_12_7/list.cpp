#include<stdlib.h>
#include<stdio.h>

typedef int LDataType;
typedef struct ListNode {
	LDataType _data;
	ListNode* _next;             //带头结点的非循环单链表
}ListNode;


///////////////////////////////////////注意链表的反转

//判断回文结构 ------ 对称
////数组：start  end  指针，比较指针内容大小是否相同

//bool huiwen(ListNode*head)
//{
//	if (head == NULL || head->_next == NULL)
//		return;
//	ListNode*start, *middle;
//	start = middle = head;
//	while (middle && middle->_next) {
//		middle = middle->_next->_next;
//		start = start->_next;
//	}
//	//从middle位置开始反转
//	ListNode* start2, *node, *next;
//	start2 = NULL;
//	node = middle->_next;
//	next = node->_next;
//	while (node) {
//		node->_next = middle;
//		start2 = node;
//		middle = node;
//		node = next;
//	}
//	//比较start2 与 head
//	while (head&&start2) {
//		if (head->_data == start2->_data) {
//			head = head->_next;
//			start2 = start->_next;
//		}
//		return false;
//	}
//	return true;
//}








//两个有序链表合并成一个有序链表     ??????????????????????????

//ListNode* mergetwo(ListNode* l1, ListNode* l2)
//{
//	ListNode* cur1, *cur2, *newhead, *newtail;
//	cur1 = l1;
//	cur2 = l2;
//	newhead = newtail = NULL;
//	while (cur1 && cur2) {
//		if (cur1->_data <= cur2->_data) {
//			if (newhead == NULL) {
//				newhead = newtail = cur1;
//			}
//			newtail->_next = cur1;
//			cur1 = cur1->_next;
//		}
//		else {
//			if (newhead == NULL) {
//				newhead = newtail = cur2;
//			}
//			newtail->_next = cur2;
//			cur2 = cur2->_next;
//		}
//	}
//	if (cur1 != NULL)
//		newtail->_next = cur1;
//	if (cur2 != NULL)
//		newtail->_next = cur2;
//	newtail->_next = NULL;
//	return newhead;
//}




//给定一个节点值，小于该值的节点放前大于放后，且不改变节点的相对位置
//
//ListNode* sortList(ListNode* head,int val)
//{
//	if (head == NULL)
//		return;
//	ListNode* lesshead, *lesstail, *greaterhead, *greatertail;
//	ListNode* cur = head;
//	lesshead = lesstail = greaterhead = greatertail = NULL;
//	while (cur) {
//		if (cur->_data <= val) {
//			if (lesstail = NULL) {
//				lesshead = lesstail = cur;
//			}
//			else {
//				lesstail->_next = cur;
//				lesstail = cur;
//			}
//			cur = cur->_next;
//		}
//		else {
//			if (greatertail = NULL)
//				greaterhead = greatertail = cur;
//			else {
//				greatertail->_next = cur;
//				greatertail = cur;
//			}
//			cur = cur->_next;
//		}
//	}	
//	if(greatertail)
//		greatertail->_next = NULL;
//	if (lesshead == NULL)
//		return greaterhead;         //小链表为空
//	if (greaterhead == NULL) {
//		if (lesstail)
//			lesstail->_next = NULL;
//		return lesshead;
//	}
//	lesstail->_next = greaterhead->_next;       //两个链接
//	/*ListNode* node = lesshead->_next;
//	free(greaterhead);
//	free(lesshead);*/            //当有头结点时（空），需要对头节点进行释放
//	return lesshead;
//}






//给定一个链表，输出链表的倒数第K个节点

//ListNode* getlastK(ListNode* head,int k)
//{
//	//判断节点的合法性
//	ListNode* fast, *slow;
//	slow = fast = head;
//	while (k--) {
//		if (fast) {
//			fast = fast->_next;
//		}
//		else
//			return NULL;
//	}
//	while (fast) {
//		fast = fast->_next;
//		slow = slow->_next;          //循环查找
//	}
//	return slow;
//}



//返回链表的中间节点，若有两个中间节点则返回第二个中间节点

//ListNode* getmiddle(ListNode* head)
//{
//	ListNode* slow, *fast;
//	slow = fast = head;
//	           //while (!((fast == NULL) || ((fast != NULL) && (fast->_next = NULL))))
//	while (fast && (fast->_next))
//	{
//		slow = slow->_next;
//		fast = fast->_next->_next;
//	}
//	return slow;
//}




//反转一个单链表  -----------  利用头插

//ListNode* reverse(ListNode* head) 
//{
//	//code 2
//	ListNode* n1, *n2, *n3;      //修改三个指针的指向
//	n1 = NULL;
//	n2 = head;
//	n3 = n2->_next;
//	while (n2) {
//		n2->_next = n1;
//		n1 = n2;
//		n2 = n3;
//		if (n3)
//			n3 = n3->_next;
//	}
//	return head;
//
//
//	//code1
//	//ListNode* newhead, *cur, *next;
//	////*newhead 表示一个新的单链表
//	//newhead = NULL;
//	//cur = head;
//	//if (head == NULL || head->_next == NULL)
//	//	return;
//	//while (cur) {
//	//	next = cur->_next;
//	//	cur->_next = newhead;
//	//	newhead = cur;
//	//	cur = next;
//	//}
//	//return newhead;
//}





//删除链表中给定值的所有节点

//typedef int LDataType;
//typedef struct ListNode {
//	LDataType _data;
//	ListNode* _next;             //带头结点的非循环单链表
//}ListNode;
//ListNode* remove(ListNode* head, int val) 
//{
//	ListNode*prev, *cur;
//	prev = NULL;
//	cur = head;
//	while (cur) {
//		if (cur->_data == val) {
//			if (cur == head){                //如果要删除的节点是头节点head
//				head = cur->_next;
//			}
//			prev->_next = cur->_next;
//			free(cur);
//			cur = prev->_next;
//		}
//		else {
//			prev = cur;
//			cur = cur->_next;
//		}
//	}
//}




/////////////////////////////////////单链表：带头结点的单向非循环链表/////////////
//typedef int LDataType;
//
//typedef struct ListNode {
//	LDataType _data;
//	ListNode* _next;             //带头结点的非循环单链表
//}ListNode;
//
//typedef struct list {
//	ListNode* _head;         //头节点
//}list;
//
//ListNode* creatListNode(LDataType val)        //创建节点
//{
//	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
//	node->_data = val;
//	node->_next = NULL;
//	return node;
//}
//void list_init(list* lst) //初始化
//{
//	if (lst == NULL)
//		return;
//	lst->_head = NULL;      //空链表
//}
//void list_pushback(list* lst, LDataType val)      //尾插     O(n)
//{
//	if (lst == NULL)
//		return;
//	//创建第一个节点，需要先开辟空间
//	if (lst->_head == NULL) {
//		lst->_head = creatListNode(val);
//	}
//	else {
//		//遍历找到最后一个节点
//		ListNode* tail = lst->_head;
//		while (tail->_next != NULL) {
//			tail = tail->_next;
//		}        
//		tail->_next = creatListNode(val);                  
//	}
//}
//void list_popback(list* lst)     //尾删		O(n)
//{
//	if (lst == NULL || lst->_head == NULL)
//		return;
//	ListNode* prew = NULL;
//	ListNode* tail = lst->_head;
//	while(tail->_next != NULL) {
//		prew = tail;
//		tail = tail->_next;
//	}
//	free(tail);
//	if (prew == NULL)
//		lst->_head = NULL;      //只有一个节点
//	else{
//		prew->_next = NULL;
//	}
//}
//void list_pushfront(list* lst, LDataType val)    //头插     O(1)
//{
//	if (lst == NULL)
//		return;
//	ListNode* node = creatListNode(val);
//	node->_next = lst->_head;        
//	lst->_head = node;            //更换头节点
//}
//void list_popfront(list* lst)         //头删     O(1)
//{
//	if (lst == NULL || lst->_head == NULL)
//		return;
//	ListNode* next = lst->_head->_next;
//	free(lst->_head);
//	lst->_head = next;
//}
//void list_insertafter(ListNode* node, LDataType val)    //给某一个node节点后插入
//{
//	if (node == NULL)
//		return;
//	ListNode* newnode = creatListNode(val);
//	ListNode* next = node->_next;
//	node->_next = newnode;
//	newnode->_next = next;
//}
//void list_earseafter(ListNode* node)          //删除节点的下一个节点
//{
//	if (node == NULL || node->_next == NULL)
//		return;
//	ListNode* next = node->_next;              //node 的下一个节点---------要删除的节点
//	ListNode* nextnext = next->_next;
//	free(next);
//	node->_next = nextnext;
//}
//ListNode* list_find(list* lst, LDataType val)     //查找
//{
//	if (lst == NULL || lst->_head == NULL)
//		return;
//	ListNode* cur = lst->_head;
//	while (cur)
//	{
//		if (cur->_data == val) {
//			return cur;
//		}
//		cur = cur->_next;
//	}
//	return NULL;
//}
//void list_destory(list* lst)
//{
//	//code1
//	/*if (lst == NULL)
//		return;
//	ListNode* cur = lst->_head;
//	while (cur) {
//		ListNode* next = cur->_next;
//		free(cur);
//		cur = next;
//	}
//	lst->_head = NULL;*/
//
//	//code2
//	if (lst == NULL || lst->_head == NULL)
//		return;
//	ListNode* next = lst->_head->_next;
//	ListNode* nextnext = next->_next;
//	while (next != NULL) {
//		free(next);
//		lst->_head->_next = nextnext;
//
//		next = nextnext;
//		nextnext = next->_next;
//	}
//	free(lst->_head);
//	lst->_head = NULL;
//}
//
//////////////////////////////////////////？？？？？？
//void list_earse(list* lst,ListNode* node)      //删除任意一个节点
//{
//	if (lst == NULL || node == NULL)     //要删除的当前的节点为空
//		return;
//	ListNode* start = lst->_head;
//	ListNode* cur = start->_next;
//	if (start == node)                  //只有一个头节点时---赋空
//		lst->_head = NULL;
//	if(start != node) {               //寻找要删除的节点
//		start = cur;
//		cur = cur->_next;
//	}
//	else {
//		free(start);
//		start = cur;
//	}
//}

