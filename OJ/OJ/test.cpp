#include<stdio.h>
#include<windows.h>
#include<assert.h>
#include<iostream>
using namespace std;


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



//  3、8 bit 位；在指定位置数字置 0 或 1 ，true 置 1；flase 置 0


//void bit_set(unsigned char* p_data, unsigned char position, bool flag)
//{
//	//方法二
//	if (flag) {
//		*p_data |= (0x01 << (position - 1));
//	}
//	else {
//		*p_data &= ~(0x01 << (position - 1));
//	}
//
//
//	//方法一
//	//if (flag)
//	//{
//	//	switch (position){   //真 ，置 1
//	//	case 1:
//	//		*p_data |= 0x00;  //0000 0001
//	//		break;
//	//	case 2:
//	//		*p_data |= 0x02;  //0000 0010
//	//		break;
//	//	case 3:
//	//		*p_data |= 0x04;  //0000 0100
//	//		break;
//	//	case 4:
//	//		*p_data |= 0x08;  //0000 1000
//	//		break;
//	//	case 5:
//	//		*p_data |= 0x10;  //0001 0000
//	//		break;
//	//	case 6:
//	//		*p_data |= 0x20;  //0010 0000
//	//	case 7:
//	//		*p_data |= 0x40; //0100 0000
//	//		break;
//	//	case 8:
//	//		*p_data |= 0x80;  //1000 0000
//	//	}
//	//}
//	//else
//	//{
//	//	switch (position) {
//	//	case 1:
//	//		*p_data &= ~0x00;  //1111 11110
//	//		break;
//	//	case 2:
//	//		*p_data &= ~0x02;  //1111 1101
//	//		break;
//	//	case 3:
//	//		*p_data &= ~0x04;  //1111 1011
//	//		break;
//	//	case 4:
//	//		*p_data &= ~0x08;  //1111 0111
//	//		break;
//	//	case 5:
//	//		*p_data &= ~0x10;  //1110 1111
//	//		break;
//	//	case 6:
//	//		*p_data &= ~0x20;  //1101 1111
//	//	case 7:
//	//		*p_data &= ~0x40; //1011 1111
//	//		break;
//	//	case 8:
//	//		*p_data &= ~0x80;  //0111 1111
//	//	}
//	//}
//}
//void main()
//{
//	unsigned char data = 123;
//	bit_set(&data, 2, false);
//	cout << (int)data << endl;
//}


// 4、实现字符串的右移

//void RightLoopMove(char *pStr, unsigned short steps)
//{
//	assert(pStr != NULL);
//	int len = strlen(pStr);
//	char *tmp = (char*)malloc(sizeof(char)*(len+1));
//	assert(tmp != NULL);
//	memset(tmp, 0, sizeof(char)*(len + 1));
//	steps %= len;
//
//	strcpy(tmp, pStr + (len - steps));
//	strncat(tmp, pStr, len - steps);
//	strcpy(pStr, tmp);
//	free(tmp);
//	tmp = NULL;
//}
//void main()
//{
//	char str[] = "abcdefghi"; 
//	cout << str << endl;
//	RightLoopMove(str, 2);
//	cout << str << endl;
//}