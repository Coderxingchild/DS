#include<stdlib.h>
#include<stdio.h>

typedef int LDataType;
typedef struct ListNode {
	LDataType _data;
	ListNode* _next;             //��ͷ���ķ�ѭ��������
}ListNode;


///////////////////////////////////////ע������ķ�ת

//�жϻ��Ľṹ ------ �Գ�
////���飺start  end  ָ�룬�Ƚ�ָ�����ݴ�С�Ƿ���ͬ

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
//	//��middleλ�ÿ�ʼ��ת
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
//	//�Ƚ�start2 �� head
//	while (head&&start2) {
//		if (head->_data == start2->_data) {
//			head = head->_next;
//			start2 = start->_next;
//		}
//		return false;
//	}
//	return true;
//}








//������������ϲ���һ����������     ??????????????????????????

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




//����һ���ڵ�ֵ��С�ڸ�ֵ�Ľڵ��ǰ���ڷź��Ҳ��ı�ڵ�����λ��
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
//		return greaterhead;         //С����Ϊ��
//	if (greaterhead == NULL) {
//		if (lesstail)
//			lesstail->_next = NULL;
//		return lesshead;
//	}
//	lesstail->_next = greaterhead->_next;       //��������
//	/*ListNode* node = lesshead->_next;
//	free(greaterhead);
//	free(lesshead);*/            //����ͷ���ʱ���գ�����Ҫ��ͷ�ڵ�����ͷ�
//	return lesshead;
//}






//����һ�������������ĵ�����K���ڵ�

//ListNode* getlastK(ListNode* head,int k)
//{
//	//�жϽڵ�ĺϷ���
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
//		slow = slow->_next;          //ѭ������
//	}
//	return slow;
//}



//����������м�ڵ㣬���������м�ڵ��򷵻صڶ����м�ڵ�

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




//��תһ��������  -----------  ����ͷ��

//ListNode* reverse(ListNode* head) 
//{
//	//code 2
//	ListNode* n1, *n2, *n3;      //�޸�����ָ���ָ��
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
//	////*newhead ��ʾһ���µĵ�����
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





//ɾ�������и���ֵ�����нڵ�

//typedef int LDataType;
//typedef struct ListNode {
//	LDataType _data;
//	ListNode* _next;             //��ͷ���ķ�ѭ��������
//}ListNode;
//ListNode* remove(ListNode* head, int val) 
//{
//	ListNode*prev, *cur;
//	prev = NULL;
//	cur = head;
//	while (cur) {
//		if (cur->_data == val) {
//			if (cur == head){                //���Ҫɾ���Ľڵ���ͷ�ڵ�head
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




/////////////////////////////////////��������ͷ���ĵ����ѭ������/////////////
//typedef int LDataType;
//
//typedef struct ListNode {
//	LDataType _data;
//	ListNode* _next;             //��ͷ���ķ�ѭ��������
//}ListNode;
//
//typedef struct list {
//	ListNode* _head;         //ͷ�ڵ�
//}list;
//
//ListNode* creatListNode(LDataType val)        //�����ڵ�
//{
//	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
//	node->_data = val;
//	node->_next = NULL;
//	return node;
//}
//void list_init(list* lst) //��ʼ��
//{
//	if (lst == NULL)
//		return;
//	lst->_head = NULL;      //������
//}
//void list_pushback(list* lst, LDataType val)      //β��     O(n)
//{
//	if (lst == NULL)
//		return;
//	//������һ���ڵ㣬��Ҫ�ȿ��ٿռ�
//	if (lst->_head == NULL) {
//		lst->_head = creatListNode(val);
//	}
//	else {
//		//�����ҵ����һ���ڵ�
//		ListNode* tail = lst->_head;
//		while (tail->_next != NULL) {
//			tail = tail->_next;
//		}        
//		tail->_next = creatListNode(val);                  
//	}
//}
//void list_popback(list* lst)     //βɾ		O(n)
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
//		lst->_head = NULL;      //ֻ��һ���ڵ�
//	else{
//		prew->_next = NULL;
//	}
//}
//void list_pushfront(list* lst, LDataType val)    //ͷ��     O(1)
//{
//	if (lst == NULL)
//		return;
//	ListNode* node = creatListNode(val);
//	node->_next = lst->_head;        
//	lst->_head = node;            //����ͷ�ڵ�
//}
//void list_popfront(list* lst)         //ͷɾ     O(1)
//{
//	if (lst == NULL || lst->_head == NULL)
//		return;
//	ListNode* next = lst->_head->_next;
//	free(lst->_head);
//	lst->_head = next;
//}
//void list_insertafter(ListNode* node, LDataType val)    //��ĳһ��node�ڵ�����
//{
//	if (node == NULL)
//		return;
//	ListNode* newnode = creatListNode(val);
//	ListNode* next = node->_next;
//	node->_next = newnode;
//	newnode->_next = next;
//}
//void list_earseafter(ListNode* node)          //ɾ���ڵ����һ���ڵ�
//{
//	if (node == NULL || node->_next == NULL)
//		return;
//	ListNode* next = node->_next;              //node ����һ���ڵ�---------Ҫɾ���Ľڵ�
//	ListNode* nextnext = next->_next;
//	free(next);
//	node->_next = nextnext;
//}
//ListNode* list_find(list* lst, LDataType val)     //����
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
//////////////////////////////////////////������������
//void list_earse(list* lst,ListNode* node)      //ɾ������һ���ڵ�
//{
//	if (lst == NULL || node == NULL)     //Ҫɾ���ĵ�ǰ�Ľڵ�Ϊ��
//		return;
//	ListNode* start = lst->_head;
//	ListNode* cur = start->_next;
//	if (start == node)                  //ֻ��һ��ͷ�ڵ�ʱ---����
//		lst->_head = NULL;
//	if(start != node) {               //Ѱ��Ҫɾ���Ľڵ�
//		start = cur;
//		cur = cur->_next;
//	}
//	else {
//		free(start);
//		start = cur;
//	}
//}

