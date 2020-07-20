#ifndef _SEQLIST_H_
#define _SEQLIAT_H_
#include "Common.h"


#define SEQLIST_DEFAULT_SIZE 8
#pragma warning(disable:4996)

typedef struct SeqList
{
	ElemType *base;
	size_t capacity;  //����
	size_t size;      //Ԫ�ظ���
}SeqList;

void SeqListInit(SeqList *plist);    //��ʼ��
void SeqListDestory(SeqList *plist);
void SeqListShow(SeqList *plist);    //��ʾ���
void SeqListPushBack(SeqList *plist, ElemType x);  //β��
void SeqListPushFront(SeqList *plist, ElemType x);  //ͷ��
size_t SeqListLength(SeqList *plist);   //�󳤶�
size_t SeqListCapacity(SeqList *plist);  //������
void SeqListPopBack(SeqList *plist);  //βɾ
void SeqListPopFront(SeqList *plist);  //ͷɾ
void SeqListClear(SeqList *plist);    //���
bool SeqListInsertByPos(SeqList *plist, int pos, ElemType x);   //��λ�ò���
bool SeqListPopByPos(SeqList *plist, int pos);   //��λ��ɾ��
void SeqListSort(SeqList *plist);  //����
bool SeqListInsertByVal(SeqList *plist, ElemType x);//��ֵ����
bool SeqListEraseByVal(SeqList *plist, ElemType x); //��ֵɾ��
int SeqListFind(SeqList *plist, ElemType key);   //����
void SeqListReverse(SeqList *plist);   //����
void GetFront(SeqList *plist); //��ȡ��Ԫ��
void GetBack(SeqList *plist); //��ȡβԪ��
int Binary_Find(SeqList *plist, ElemType x);  //���ֲ���
bool Erase_All(SeqList *plist, ElemType x);  //ɾ��������ͬ��Ԫ��


bool _Inc(SeqList *plist,size_t new_capacity)  //����
{
	//code  1
	/*assert(plist != NULL && new_capacity > plist->capacity);
	ElemType *new_base = (ElemType*)realloc(plist->base, sizeof(ElemType)* new_capacity);
	if (new_base == NULL) {
		return false;
	}
	plist->base = new_base;
	plist->capacity = new_capacity;
	return true;*/
	assert(plist != NULL && new_capacity > plist->capacity);
	ElemType *new_base = (ElemType*)malloc(sizeof(ElemType)*new_capacity);
	if (new_base == NULL) {
		return false;
	}
	memcpy(new_base, plist->base, sizeof(ElemType)*(plist->capacity));
	free(plist->base);              //�ͷžɿռ�
	plist->base = new_base;
	plist->capacity = new_capacity;
	return true;
}

bool IsFull(SeqList *plist)       //����
{
	assert(plist!=NULL);
	return plist->size >= plist->capacity;
}
bool IsEmpty(SeqList *plist)     //�п�
{
	assert(plist != NULL);
	return plist->size == 0;
}
void SeqListInit(SeqList *plist)   //��ʼ��
{
	assert(plist != NULL);
	plist->capacity = SEQLIST_DEFAULT_SIZE;
	plist->base = (ElemType*)malloc(sizeof(ElemType));
	plist->size = 0;
}
void SeqListDestory(SeqList *plist)   //���� ---  �ͷſռ�
{
	assert(plist != NULL);
	free(plist->base);
	plist->base = NULL;
	plist->capacity = plist->size = 0;
}
void SeqListPushFront(SeqList *plist, ElemType x)
{  //ͷ��
	assert(plist != NULL);
	if (IsFull(plist) && !_Inc(plist, plist->capacity * 2)) {
		printf("˳���������ͷ�� %d ���ܲ���.\n", x);
		return;
	}
	for (size_t i = plist->size; i > 0; i--) {
		plist->base[i] = plist->base[i - 1];
	}
	plist->base[0] = x;
	plist->size++;
}
void SeqListPushBack(SeqList *plist, ElemType x)
{     //β��
	assert(plist != NULL);
	if (IsFull(plist) && !_Inc(plist,plist->capacity * 2)) {
		printf("˳���������β�� %d ���ܲ���.\n", x);
		return;
	}
	plist->base[plist->size++] = x;   //�ȷ������ݣ��ڽ������ݸ�����һ
}
void SeqListShow(SeqList *plist)
{ //չʾ���
	assert(plist != NULL);
	for (size_t i = 0; i < plist->size; ++i)
	{
		printf("%d ", plist->base[i]);
	}
	printf("\n");
}
size_t SeqListLength(SeqList *plist)   //����
{
	assert(plist != NULL);
	return plist->size;
}
size_t SeqListCapacity(SeqList *plist)  //����
{
	assert(plist != NULL);
	return plist->capacity;
}
void SeqListPopBack(SeqList *plist)   //βɾ
{
	assert(plist != NULL);
	if (IsEmpty(plist)) {
		printf("˳����ǿյģ����ܽ���β��ɾ��!\n");
	}
	plist->size--;
}
void SeqListPopFront(SeqList *plist)   //ͷɾ
{
	assert(plist != NULL);
	if (IsEmpty(plist)) {
		printf("˳����ǿյģ����ܽ���ͷ��ɾ��!\n");
	}
	for(size_t i=0;i<plist->size;++i){
	    plist->base[i] = plist->base[i + 1];
	plist->size--;
	}
}
void SeqListClear(SeqList *plist)     //���
{
	assert(plist != NULL);
	plist->size = 0;
}
bool SeqListInsertByPos(SeqList *plist, int pos, ElemType x)
{              //��λ�ò���
	assert(plist != NULL);
	if (IsFull(plist)) {
		printf("˳���������%d ������ %d λ�ý��в���\n", x, pos);
		return false;
	}
	if (pos < 0 || pos > plist->size) {
		printf("�����λ�� %d �ǷǷ���,%d ���ܲ���\n", pos, x);
		return false;
	}
	for (size_t i = plist->size; i > pos; --i) {
		plist->base[i] = plist->base[i - 1];
		plist->base[pos] = x;
	}plist->size++;
	return true;
}
bool SeqListPopByPos(SeqList *plist, int pos)
{                  //��λ��ɾ��
	assert(plist != NULL);
	if (IsEmpty(plist)) {
		printf("˳���Ϊ�գ�%d λ�õ����ݲ��ܱ�ɾ��\n", pos);
		return false;
	}
	if (pos < 0 || pos >= plist->size) {
		printf("ɾ����λ�� %d �ǷǷ���,���ݲ��ܱ�ɾ��\n", pos);
		return false;
	}
	for (size_t i = pos; i < plist->size; ++i) {
		plist->base[i] = plist->base[i + 1];
	plist->size--;}
	return true;
}
void SeqListSort(SeqList *plist)
{               //����
	assert(plist != NULL);
	for (size_t i = 0; i < plist->size - 1; ++i) {
		for (size_t j = 0; j < plist->size - i - 1; ++j) {
			if(plist->base[j]>plist->base[j+1])
			Swap(&plist->base[j], &plist->base[j + 1]);
		}
	}
}
bool SeqListInsertByVal(SeqList *plist, ElemType x)
{              //��ֵ����
	assert(plist != NULL); 
	if (IsFull(plist) && !_Inc(plist, plist->capacity * 2)) {
		printf("˳���������%d ���ܲ��룡\n",x);
	}
	/*  //code 1 :���Ҳ����λ�ò�����
	for (size_t i = 0; i < plist->size; ++i) {
		if (plist->base[i-1] <= x && x < plist->base[i]) {
			plist->base[i + 1] = plist->base[i];
			plist->base[i] = x;
		}
	}*/
	/* //code 2: ��ǰ����Ƚ�
	size_t pos = 0;
	while (pos < plist->size && x > plist->base[pos])
		pos++;
		for (size_t i = plist->size; i > pos; --i)
			plist->base[i] = plist->base[i - 1];
		plist->base[pos] = x;
	plist->size++;*/
	size_t end = plist->size - 1;          //�Ӻ���ǰ�Ƚ�
	while (end >=0 && x < plist->base[end]) {
		plist->base[end + 1] = plist->base[end];
		end--;
	}plist->base[end+1] = x;
	plist->size++;
	return true;
}
int SeqListFind(SeqList *plist, ElemType x)
{             //��������
	assert(plist != NULL);
	int pos = 0;
	while (pos < plist->size && x != plist->base[pos]) {
		pos++;
	}
	if (pos == plist->size)      //û���ҵ���λ��
		pos = -1;
     return pos;
}
int Binary_Find(SeqList *plist, ElemType x) 
{   //���ֲ���
	assert(plist != NULL);
	int start = 0;
	int end = plist->size - 1;
	int mid = (1 + plist->size) / 2;
	while (start < end) {
		if (x < plist->base[mid]) {
			end = mid;
			mid = (end + start) / 2;
		}
		else if (x > plist->base[mid]) {
			start = mid;
			mid = (end + start) / 2;
		}
		else
			return mid;
	}
	return -1;
}  
bool SeqListEraseByVal(SeqList *plist, ElemType x)
{             //��ֵɾ��
	assert(plist != NULL);
	/*for (size_t i = 0; i < plist->size; ++i) {
		if (plist->base[i] == x) {
			for (; i < plist->size; ++i)
			plist->base[i] = plist->base[i + 1];
		plist->size--;
		}
	}*/
	int pos = SeqListFind(plist, x);
	if (pos == -1)
		return false;
	SeqListPopByPos(plist, pos);
}
bool Erase_All(SeqList *plist, ElemType x)
{                //ɾ����ͬԪ��
	assert(plist != NULL);
	int pos = SeqListFind(plist, x);
	if (pos == -1)
		return false;
	SeqListPopByPos(plist, pos);
}
void SeqListReverse(SeqList *plist)
{              //����
	assert(plist != NULL);
	if (plist->size == 1)
		return;
	int start = 0, end = plist->size - 1;
	while (start < end) {
		Swap(&plist->base[start], &plist->base[end]);
		start++; end--;
	}
}
void GetFront(SeqList *plist)  //��ȡ��Ԫ��
{
	assert(plist != NULL);
	if (IsEmpty(plist)) {
		printf("˳���Ϊ�գ���ȡ��Ԫ��ʧ��\n");
	}
	printf("SeqList Front :%d\n", plist->base[0]);
}
void GetBack(SeqList *plist)
{      //ȡβ
	assert(plist != NULL);
	if (IsEmpty(plist)) {
		printf("˳���Ϊ�գ���ȡ��Ԫ��ʧ��\n");
	}
	printf("SeqList Front :%d\n", plist->base[plist->size-1]);
}


#endif