#include<iostream>
#include<vector>

using namespace std;
////////////////////////////////  作业题  顺序表，单链表  //////////////////////


// slist.h     单链表


//typedef int SLTDateType;
//typedef struct SListNode
//{
//	SLTDateType data;
//	struct SListNode* next;
//}SListNode;
//typedef struct SList {
//	SListNode* head;
//}SList;
//
////初始化
//void SListInit(SList* plist)
//{
//	plist->head = NULL;
//}
//// 动态申请一个节点
//SListNode* BuySListNode(SLTDateType x)
//{
//	SListNode* node = (SListNode*)malloc(sizeof(SListNode));
//	node->data = x;
//	node->next = NULL;
//	return node;
//}
//// 单链表打印
//void SListPrint(SList* plist)
//{
//	if (plist == NULL || plist->head == NULL)
//		return;
//	SListNode* tail = plist->head;
//	if (tail != NULL) {
//		printf("%d ", tail->data);
//		tail = tail->next;
//	}
//}
//// 单链表尾插
//void SListPushBack(SList* pplist, SLTDateType x)
//{
//	if (pplist == NULL)
//		return;
//	SListNode* tail = pplist->head;
//	if (pplist->head == NULL)              //空链表
//		pplist->head = BuySListNode(x);
//	else{
//		while(tail->next != NULL)
//			tail = tail->next;
//		tail->next = BuySListNode(x);
//	}
//}
//// 单链表的头插
//void SListPushFront(SList* pplist, SLTDateType x)
//{
//	if (pplist == NULL)
//		return;
//	SListNode* node = BuySListNode(x);
//	if (pplist->head == NULL)
//		pplist->head = node;
//	else {
//		node->next = pplist->head;
//		pplist->head = node;
//	}
//}
//// 单链表的尾删
//void SListPopBack(SList* pplist)
//{
//	if (pplist == NULL || pplist->head == NULL)
//		return;
//	SListNode* prev = NULL;
//	SListNode* tail = pplist->head;
//	while(tail->next != NULL) {
//		prev = tail;
//		tail = tail->next;
//	}
//	free(tail);
//	if (prev == NULL) {
//		pplist->head = NULL;
//	}
//	else {
//		prev->next = NULL;
//	}
//}
//// 单链表头删
//void SListPopFront(SList* pplist)
//{
//	if (pplist == NULL || pplist->head == NULL)
//		return;
//	SListNode* next = pplist->head->next;
//	free(pplist->head);
//	pplist->head = next;
//}
//// 单链表查找
//SListNode* SListFind(SList* plist, SLTDateType x)
//{
//	if (plist == NULL || plist->head == NULL)
//		return 0;
//	SListNode* node = plist->head;
//	while (node) {
//		if (node->data != x) {
//			node = node->next;
//		}
//		else
//			return node;
//	}
//	return NULL;
//}
//// 单链表在pos位置之后插入x
//// 分析思考为什么不在pos位置之前插入？
//void SListInsertAfter(SListNode* pos, SLTDateType x)
//{
//	if (pos == NULL)
//		return;
//	SListNode* node = BuySListNode(x);
//	node->next = pos->next;
//	pos->next = node;
//}
//// 单链表删除pos位置之后的值
//// 分析思考为什么不删除pos位置？
//void SListEraseAfter(SListNode* pos)
//{
//	if (pos == NULL)
//		return;
//	if (pos->next != NULL) {
//		SListNode* node = pos->next->next;
//		free(pos->next);
//		pos->next = node;
//	}
//}
//// 单链表的销毁
//void SListDestory(SList* plist)
//{
//	if (plist == NULL || plist->head == NULL)
//		return;
//	SListNode* node = plist->head;
//	while (node) {
//		SListNode* code = node->next;
//		free(node);
//		node = code;
//	}
//	plist->head = NULL;
//}
//
//void test()
//{
//	SList lst;
//	SListInit(&lst);
//
//	SListPushBack(&lst, 1);
//	SListPushBack(&lst, 2);
//	SListPushBack(&lst, 3);
//	SListPushBack(&lst, 4);
//	SListPrint(&lst);
//
//	SListPushFront(&lst, 9);
//	SListPushFront(&lst, 8);
//	SListPushFront(&lst, 7);
//	SListPrint(&lst);
//
//	SListPopBack(&lst);
//	SListPopBack(&lst);
//	SListPopBack(&lst);
//	SListPrint(&lst);
//
//	SListPopFront(&lst);
//	SListPopFront(&lst);
//	SListPopFront(&lst);
//	SListPrint(&lst);
//
//	/*SListInsertAfter(&(lst->head)+3, 0);
//	SListPrint(&lst);
//
//	SListEraseAfter(&(lst->head) + 2);
//	SListPrint(&lst);*/
//}
//int main()
//{
//	test();
//	return 0;
//}






// SeqList.h   顺序表

//#include <stdio.h>
//#include <assert.h>
//#include <stdlib.h>
//#include<string.h>
//
//typedef int SLDateType;
//typedef struct SeqList
//{
//	SLDateType* a;
//	int size;
//	int capacity; // unsigned int
//}SeqList;
//
//// 对数据的管理:增删查改 
//void SeqListInit(SeqList* ps)   //初始化
//{
//	if (ps == NULL)
//		return;
//	ps->a = NULL;
//	ps->capacity = ps->size = 0;
//}
//void SeqListDestory(SeqList* ps)  //销毁
//{
//	if (ps == NULL || ps->a == NULL)
//		return;
//	/*for (int i = 0; i < ps->size; i++) {
//		ps->a[i] = NULL;
//	}*/
//
//	free(ps->a);
//	ps->capacity = ps->size = 0;
//}
//
//void SeqListPrint(SeqList* ps)     //打印
//{
//	if (ps == NULL)
//		return;
//	for (int i = 0; i < ps->size; i++) {
//		printf("%d ", ps->a[i]);
//	}
//	printf("\n");
//}
//void checkcapacity(SeqList* ps)     //开辟空间
//{
//	int newcapacity = ps->capacity == 0 ? 1 : 2 * (ps->capacity);
//	SLDateType* tmp = (SLDateType*)malloc(newcapacity * sizeof(SLDateType));
//	memcpy(tmp, ps->a, sizeof(SLDateType)*(ps->size));
//	free(ps->a);
//	ps->a = tmp;
//	ps->capacity = newcapacity;
//}
//void SeqListPushBack(SeqList* ps, SLDateType x)       //尾插
//{
//	if (ps == NULL)
//		return;
//	if (ps->size == ps->capacity) {
//		//开辟空间
//		checkcapacity(ps);
//	}
//	ps->a[ps->size++] = x;
//}
//void SeqListPushFront(SeqList* ps, SLDateType x)        //头插
//{
//	if (ps == NULL)
//		return;
//	if (ps->capacity == ps->size) {
//		checkcapacity(ps);
//	}
//	SLDateType end = ps->size;
//	while(end > 0) {
//		ps->a[end] = ps->a[end - 1];
//		end--;
//	}
//	ps->a[0] = x;
//	ps->size++;
//}
//void SeqListPopFront(SeqList* ps)  //头删
//{
//	if (ps == NULL || ps->size == 0)
//		return;
//	int start = 1;
//	while (start < ps->size) {
//		ps->a[start - 1] = ps->a[start];
//		start++;
//	}
//	ps->size--;
//}
//void SeqListPopBack(SeqList* ps)       //尾删
//{
//	if (ps == NULL || ps->size == 0)
//		return;
//	ps->size--;
//}
//
//// 顺序表查找
//int SeqListFind(SeqList* ps, SLDateType x)
//{
//	if (ps == NULL || ps->size == 0)
//		return 0;
//	for (int i = 0; i < ps->size; ++i) {
//		if (ps->a[i] == x)
//			return i;
//	}
//	return -1;
//}
//// 顺序表在pos位置插入x
//void SeqListInsert(SeqList* ps, size_t pos, SLDateType x)
//{
//	if (ps == NULL)
//		return;
//	if (ps->capacity == ps->size) {
//		checkcapacity(ps);
//	}
//	int end = ps->size;
//	//判断位置合法性
//	if (pos >= 0 && pos <= ps->size) {
//		while (end > pos) {
//			ps->a[end] = ps->a[end - 1];
//			--end;
//		}
//	}
//	ps->a[pos] = x;
//	ps->size++;
//}
//// 顺序表删除pos位置的值
//void SeqListErase(SeqList* ps, size_t pos)
//{
//	if (ps == NULL || ps->size == 0)
//		return;
//	int start = pos + 1;
//	if (pos >= 0 && pos < ps->size) {
//		while (start < ps->size) {
//			ps->a[start - 1] = ps->a[start];
//			++start;
//		}
//	}
//	ps->size--;
//}
//void test()
//{
//	SeqList sq;
//	SeqListInit(&sq);
//	SeqListPushBack(&sq, 1);
//	SeqListPushBack(&sq, 2);
//	SeqListPushBack(&sq, 3);
//	SeqListPushBack(&sq, 4);
//	SeqListPushBack(&sq, 5);
//	SeqListPrint(&sq);
//
//	SeqListPopFront(&sq);
//	SeqListPrint(&sq);
//
//	SeqListPopBack(&sq);
//	SeqListPrint(&sq);
//
//	SeqListPushFront(&sq, 7);
//	SeqListPrint(&sq);
//
//	SeqListInsert(&sq, 2, 8);
//	SeqListPrint(&sq);
//
//	SeqListErase(&sq, 3);
//	SeqListPrint(&sq);
//
//	printf("%d ",SeqListFind(&sq, 7));
//
//	SeqListDestory(&sq);
//}
//int main()
//{
//	test();
//	return 0;
//}





//字符数组加上一个常数------------数组整型加法

//int* add(int* A, int Asize, int k, int* returnSize)
//{
//	int len = 0;
//	int num = k;     //保存加数
//	int idx = 0;
//	while (num) {      //计算加数长度
//		len++;
//		num /= 10;
//	}
//	int arrlen = len > Asize ? len + 1 : Asize + 1;      //开辟结果数据空间
//	int *arr = (int*)malloc(sizeof(int)*arrlen);
//
//	int step = 0;
//	int end = Asize - 1;             //从低位开始对应位相加
//	while (end >= 0 || k > 0)
//	{
//		int curSum = step;
//		if (end >= 0) {
//			curSum += A[end];
//			if (k > 0) {
//				curSum += k % 10;        //计算加数的各位数字
//				if (curSum > 9) {
//					step = 1;           //进位信号
//					curSum -= 10;
//				}
//				else {
//					step = 0;
//				}
//				arr[idx++] = curSum;
//				end--;
//				k /= 10;
//			}
//		}
//	}
//	//判断最高位进位
//	if (step == 1)
//		arr[idx++] = 1;            //逆序存放
//	//逆转
//	int start = 0;
//	end = idx - 1;
//	while (start > end) {
//		int tmp = arr[start];
//		arr[start] = arr[end];
//		arr[end] = tmp;
//		start++; end--;
//	}
//	*returnSize = idx;
//	return returnSize;
//}





//反转数组-----------将数组中元素向右移动 k 位

//void reverse(int* nums, int start, int end)
//{
//	//数组反转
//	if (start < end) {
//		/*int tmp = nums[start];
//		nums[start] = nums[end];
//		nums[end] = tmp;
//		start++, end--;*/
//
//		nums[start] = nums[start] ^ nums[end];
//		nums[end] = nums[start] ^ nums[end];
//		nums[start] = nums[start] ^ nums[end];
//		start++, end--;
//	}
//}
//////// 1，2，3，4，5，6      k=3----------》 4，5，6，1，2，3
//void rotate(int* nums, int numsSize, int k)
//{
//	//code1 : 头插
//	
//	//code2 : 或者反转 k-1 次
//	if (k <= 1)
//		return;
//	//三次反转：先反转前 k 个元素，之后反转 numsSize-k 个元素，最后整体反转
//	k %= numsSize;
//	reverse(nums, 0, numsSize - k - 1);
//	reverse(nums, numsSize - k, numsSize - 1);
//	reverse(nums, 0, numsSize - 1);
//}


//合并两个有序数组
//void merge(int* nums1,int nums1Size,int m, int* nums2,  int nums2Size, int n)
//{                          //m,n分别是两个数组有效元素个数
//	//code2 :从后向前比较两个值，在nums1中进行比较插入
//	int i = m - 1, j = n - 1, idx = m + n - 1;
//	while (i >= 0 && j >= 0) {
//		if (nums1[i] >= nums2[j])
//			nums1[idx--] = nums1[i--];
//		else {
//			nums1[idx--] = nums2[j--];
//		}
//	}
//	//若nums2 有剩余
//	if (j >= 0) {
//		memcpy(nums1, nums2, sizeof(int)*(j + 1));
//	}
//
//
//	//code1：借助第三个数组，比较大小之后按大小插入到nums3 
//	/*int *nums3 = (int*)malloc(sizeof(int)*(m + n));
//	int i = 0, j = 0, idx = 0;
//	while (i < m && j < n) {
//		if (nums1[i] <= nums2[j])
//		{
//			nums3[idx++] = nums1[i++];
//		}
//		else {
//			nums3[idx++] = nums2[j++];
//		}
//	}
//	if (i < m) {
//		memcpy(nums3 + idx, nums1 + i, sizeof(int)*(m - i));
//	}
//	if (j < n) {
//		memcpy(nums3 + idx, nums2 + j, sizeof(int)*(n - j));
//	}
//	memcpy(nums1, nums3, sizeof(int)*(m + n));
//	free(nums3);  */
//}



//删除重复出现的元素
//int easer(int *nums, int numsSize)
//{
//	if (numsSize <= 1)         //只有一个元素时不进行删除操作
//		return numsSize;
//	int i = 0, j = 1,idx = 0;           //两个指针 i,j 用来确定相同数据的区间
//	while (j < numsSize) {
//		nums[idx++] = nums[i];
//		if (nums[i] == nums[j]) {
//			while (j < numsSize && nums[i] == nums[j])
//				++j;
//			i = j;   //更新
// 			++j;
//		}
//		else {
//			++i; ++j;
//		}
//	}
//	if (i <= numsSize) {
//		nums[idx++] = nums[i];          //保存最后一个元素
//	}
//	return idx;         //返回元素个数
//}



//移除元素
//int removeElement(int *nums, int numsSize,int val)
//{ 
//	//code2
//	int idx = 0;
//	for (int i = 0; i < numsSize; ++i) {
//		/*if(nums[i] != val) {
//			++i, ++idx;
//		}
//		++i;*/   //error
//
//		////移动元素
//		for (; i < numsSize; ++i)       //只保存与val值不相同的数据
//		{
//			if(nums[i]!=val)
//				nums[idx++] = nums[i];
//		}
//	}
//	return idx;
//
//	//code 1
//	//int *newArr = (int*)malloc(sizeof(int)*numsSize);     //新开一个数字空间
//	//int idx = 0;
//	//for (int i = 0; i < numsSize; ++i) {
//	//	if (nums[i] != val)
//	//	{
//	//		newArr[idx++] = nums[i];
//	//	}
//	//}
//	//memcpy(nums, newArr, sizeof(int) * idx);
//	//free(newArr);
//	//return idx;
//}




////找缺失的哪个数，0~n之间
////int missingNumber(vector<int>& nums)
////{
////	int sum = 0;
////	for (int i = 0; i < nums.size(); i++)
////	{
////		sum ^= i;
////		sum ^= nums[i];
////	}
////	sum ^= nums.size();
////	return sum;
////}



//找两个单身狗
//class Solution {
//public:
//	vector<int> singleNumbers(vector<int>& nums) {
//		int sum = 0;
//		for (int i = 0; i < nums.size(); ++i) {
//			sum ^= nums[i];     //两个数的异或---------相异为1
//		}
//		int m = 1;
//		while ((m&sum) == 0) {
//			m = m << 1;
//		}
//		int a = 0; int b = 0;
//		for (int i = 0; i < nums.size(); ++i) {
//			if ((nums[i] & m) == 0) {
//				a ^= nums[i];
//			}
//			else {
//				b ^= nums[i];
//			}
//		}
//		return vector<int> {a, b};
//	}
//};
