#include<iostream>
#include<vector>

using namespace std;
////////////////////////////////  ��ҵ��  ˳���������  //////////////////////


// slist.h     ������


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
////��ʼ��
//void SListInit(SList* plist)
//{
//	plist->head = NULL;
//}
//// ��̬����һ���ڵ�
//SListNode* BuySListNode(SLTDateType x)
//{
//	SListNode* node = (SListNode*)malloc(sizeof(SListNode));
//	node->data = x;
//	node->next = NULL;
//	return node;
//}
//// �������ӡ
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
//// ������β��
//void SListPushBack(SList* pplist, SLTDateType x)
//{
//	if (pplist == NULL)
//		return;
//	SListNode* tail = pplist->head;
//	if (pplist->head == NULL)              //������
//		pplist->head = BuySListNode(x);
//	else{
//		while(tail->next != NULL)
//			tail = tail->next;
//		tail->next = BuySListNode(x);
//	}
//}
//// �������ͷ��
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
//// �������βɾ
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
//// ������ͷɾ
//void SListPopFront(SList* pplist)
//{
//	if (pplist == NULL || pplist->head == NULL)
//		return;
//	SListNode* next = pplist->head->next;
//	free(pplist->head);
//	pplist->head = next;
//}
//// ���������
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
//// ��������posλ��֮�����x
//// ����˼��Ϊʲô����posλ��֮ǰ���룿
//void SListInsertAfter(SListNode* pos, SLTDateType x)
//{
//	if (pos == NULL)
//		return;
//	SListNode* node = BuySListNode(x);
//	node->next = pos->next;
//	pos->next = node;
//}
//// ������ɾ��posλ��֮���ֵ
//// ����˼��Ϊʲô��ɾ��posλ�ã�
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
//// �����������
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






// SeqList.h   ˳���

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
//// �����ݵĹ���:��ɾ��� 
//void SeqListInit(SeqList* ps)   //��ʼ��
//{
//	if (ps == NULL)
//		return;
//	ps->a = NULL;
//	ps->capacity = ps->size = 0;
//}
//void SeqListDestory(SeqList* ps)  //����
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
//void SeqListPrint(SeqList* ps)     //��ӡ
//{
//	if (ps == NULL)
//		return;
//	for (int i = 0; i < ps->size; i++) {
//		printf("%d ", ps->a[i]);
//	}
//	printf("\n");
//}
//void checkcapacity(SeqList* ps)     //���ٿռ�
//{
//	int newcapacity = ps->capacity == 0 ? 1 : 2 * (ps->capacity);
//	SLDateType* tmp = (SLDateType*)malloc(newcapacity * sizeof(SLDateType));
//	memcpy(tmp, ps->a, sizeof(SLDateType)*(ps->size));
//	free(ps->a);
//	ps->a = tmp;
//	ps->capacity = newcapacity;
//}
//void SeqListPushBack(SeqList* ps, SLDateType x)       //β��
//{
//	if (ps == NULL)
//		return;
//	if (ps->size == ps->capacity) {
//		//���ٿռ�
//		checkcapacity(ps);
//	}
//	ps->a[ps->size++] = x;
//}
//void SeqListPushFront(SeqList* ps, SLDateType x)        //ͷ��
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
//void SeqListPopFront(SeqList* ps)  //ͷɾ
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
//void SeqListPopBack(SeqList* ps)       //βɾ
//{
//	if (ps == NULL || ps->size == 0)
//		return;
//	ps->size--;
//}
//
//// ˳������
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
//// ˳�����posλ�ò���x
//void SeqListInsert(SeqList* ps, size_t pos, SLDateType x)
//{
//	if (ps == NULL)
//		return;
//	if (ps->capacity == ps->size) {
//		checkcapacity(ps);
//	}
//	int end = ps->size;
//	//�ж�λ�úϷ���
//	if (pos >= 0 && pos <= ps->size) {
//		while (end > pos) {
//			ps->a[end] = ps->a[end - 1];
//			--end;
//		}
//	}
//	ps->a[pos] = x;
//	ps->size++;
//}
//// ˳���ɾ��posλ�õ�ֵ
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





//�ַ��������һ������------------�������ͼӷ�

//int* add(int* A, int Asize, int k, int* returnSize)
//{
//	int len = 0;
//	int num = k;     //�������
//	int idx = 0;
//	while (num) {      //�����������
//		len++;
//		num /= 10;
//	}
//	int arrlen = len > Asize ? len + 1 : Asize + 1;      //���ٽ�����ݿռ�
//	int *arr = (int*)malloc(sizeof(int)*arrlen);
//
//	int step = 0;
//	int end = Asize - 1;             //�ӵ�λ��ʼ��Ӧλ���
//	while (end >= 0 || k > 0)
//	{
//		int curSum = step;
//		if (end >= 0) {
//			curSum += A[end];
//			if (k > 0) {
//				curSum += k % 10;        //��������ĸ�λ����
//				if (curSum > 9) {
//					step = 1;           //��λ�ź�
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
//	//�ж����λ��λ
//	if (step == 1)
//		arr[idx++] = 1;            //������
//	//��ת
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





//��ת����-----------��������Ԫ�������ƶ� k λ

//void reverse(int* nums, int start, int end)
//{
//	//���鷴ת
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
//////// 1��2��3��4��5��6      k=3----------�� 4��5��6��1��2��3
//void rotate(int* nums, int numsSize, int k)
//{
//	//code1 : ͷ��
//	
//	//code2 : ���߷�ת k-1 ��
//	if (k <= 1)
//		return;
//	//���η�ת���ȷ�תǰ k ��Ԫ�أ�֮��ת numsSize-k ��Ԫ�أ�������巴ת
//	k %= numsSize;
//	reverse(nums, 0, numsSize - k - 1);
//	reverse(nums, numsSize - k, numsSize - 1);
//	reverse(nums, 0, numsSize - 1);
//}


//�ϲ�������������
//void merge(int* nums1,int nums1Size,int m, int* nums2,  int nums2Size, int n)
//{                          //m,n�ֱ�������������ЧԪ�ظ���
//	//code2 :�Ӻ���ǰ�Ƚ�����ֵ����nums1�н��бȽϲ���
//	int i = m - 1, j = n - 1, idx = m + n - 1;
//	while (i >= 0 && j >= 0) {
//		if (nums1[i] >= nums2[j])
//			nums1[idx--] = nums1[i--];
//		else {
//			nums1[idx--] = nums2[j--];
//		}
//	}
//	//��nums2 ��ʣ��
//	if (j >= 0) {
//		memcpy(nums1, nums2, sizeof(int)*(j + 1));
//	}
//
//
//	//code1���������������飬�Ƚϴ�С֮�󰴴�С���뵽nums3 
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



//ɾ���ظ����ֵ�Ԫ��
//int easer(int *nums, int numsSize)
//{
//	if (numsSize <= 1)         //ֻ��һ��Ԫ��ʱ������ɾ������
//		return numsSize;
//	int i = 0, j = 1,idx = 0;           //����ָ�� i,j ����ȷ����ͬ���ݵ�����
//	while (j < numsSize) {
//		nums[idx++] = nums[i];
//		if (nums[i] == nums[j]) {
//			while (j < numsSize && nums[i] == nums[j])
//				++j;
//			i = j;   //����
// 			++j;
//		}
//		else {
//			++i; ++j;
//		}
//	}
//	if (i <= numsSize) {
//		nums[idx++] = nums[i];          //�������һ��Ԫ��
//	}
//	return idx;         //����Ԫ�ظ���
//}



//�Ƴ�Ԫ��
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
//		////�ƶ�Ԫ��
//		for (; i < numsSize; ++i)       //ֻ������valֵ����ͬ������
//		{
//			if(nums[i]!=val)
//				nums[idx++] = nums[i];
//		}
//	}
//	return idx;
//
//	//code 1
//	//int *newArr = (int*)malloc(sizeof(int)*numsSize);     //�¿�һ�����ֿռ�
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




////��ȱʧ���ĸ�����0~n֮��
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



//����������
//class Solution {
//public:
//	vector<int> singleNumbers(vector<int>& nums) {
//		int sum = 0;
//		for (int i = 0; i < nums.size(); ++i) {
//			sum ^= nums[i];     //�����������---------����Ϊ1
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
