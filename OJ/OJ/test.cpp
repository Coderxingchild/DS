#include<stdio.h>
#include<windows.h>


//1.将两个升序链表合并成为一个升序链表

//Definition for singly-linked list.
//struct ListNode {
//	int val;
//	ListNode*next;
//	ListNode() :val(0), next(nullptr) {}
//	ListNode(int x) :val(x), next(nullptr) {}
//	ListNode(int x, ListNode*next) :val(x), next(next) {}
//};
//
//class Solution {
//public:
//	ListNode* mergeTwoLists(ListNode*l1, ListNode*l2) {
//		if (l1 == NULL)
//			return l2;
//		else if (l2 == NULL)
//			return l1;
//		struct ListNode*head;
//		if (l1->val <= l2->val) {
//			head = l1;
//			l1 = l1->next;
//		}
//		else {
//			head = l2;
//			l2 = l2->next;
//		}
//		struct ListNode*tail = head;
//		while (l1 != NULL && l2 != NULL) {
//			if (l1->val <= l2->val) {
//				tail->next = l1; 
//				l1 = l1->next;
//			}
//			else {
//				tail->next = l2;
//				l2 = l2->next;
//			}
//			tail = tail->next;
//		}
//		if (l1 != NULL)              //最后比较 l2 中元素为空，剩 l1 中有元素
//			tail->next = l1;
//		if (l2 != NULL)               //l2 中还有剩余元素
//			tail->next = l2;
//		return head;
//	}
//};



// 2.给定 X 值将链表分割成两部分，所有小于x的节点排在大于或等于x 结点之前

//struct ListNode {
//	int val;
//	struct ListNode*next;
//	ListNode(int x) :val(x), next(NULL) {}
//};
//class Partition {
//public:
//	ListNode*partition(ListNode*pHead, int x) {
//		if (pHead == NULL)
//			return NULL;
//		ListNode*pLessHead, *pLessTail;    //指定一个大于、小于的两个带头尾节点的链表
//		ListNode*pGreatHead, *pGreatTail;
//		pLessHead = pLessTail = (ListNode*)malloc(sizeof(ListNode));
//		pGreatHead = pGreatTail = (ListNode*)malloc(sizeof(ListNode));
//		while (pHead != NULL) {
//			if (pHead->val < x) {
//				pLessTail->next = pHead;
//				pLessTail = pHead;
//			}
//			else {
//				pGreatTail->next = pHead;
//				pGreatTail= pHead;
//			}
//			pHead = pHead->next;
//		}
//		pLessTail->next = pGreatHead->next;
//		pGreatTail->next = NULL;
//		pHead = pLessHead->next;
//		free(pLessHead);
//		free(pGreatHead);
//		return pHead;
//	}
//};



