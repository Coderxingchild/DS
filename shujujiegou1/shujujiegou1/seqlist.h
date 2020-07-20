#ifndef _SEQLIST_H_
#define _SEQLIAT_H_
#include "Common.h"


#define SEQLIST_DEFAULT_SIZE 8
#pragma warning(disable:4996)

typedef struct SeqList
{
	ElemType *base;
	size_t capacity;  //容量
	size_t size;      //元素个数
}SeqList;

void SeqListInit(SeqList *plist);    //初始化
void SeqListDestory(SeqList *plist);
void SeqListShow(SeqList *plist);    //显示面板
void SeqListPushBack(SeqList *plist, ElemType x);  //尾插
void SeqListPushFront(SeqList *plist, ElemType x);  //头插
size_t SeqListLength(SeqList *plist);   //求长度
size_t SeqListCapacity(SeqList *plist);  //求容量
void SeqListPopBack(SeqList *plist);  //尾删
void SeqListPopFront(SeqList *plist);  //头删
void SeqListClear(SeqList *plist);    //清空
bool SeqListInsertByPos(SeqList *plist, int pos, ElemType x);   //按位置插入
bool SeqListPopByPos(SeqList *plist, int pos);   //按位置删除
void SeqListSort(SeqList *plist);  //排序
bool SeqListInsertByVal(SeqList *plist, ElemType x);//按值插入
bool SeqListEraseByVal(SeqList *plist, ElemType x); //按值删除
int SeqListFind(SeqList *plist, ElemType key);   //查找
void SeqListReverse(SeqList *plist);   //逆置
void GetFront(SeqList *plist); //获取首元素
void GetBack(SeqList *plist); //获取尾元素
int Binary_Find(SeqList *plist, ElemType x);  //二分查找
bool Erase_All(SeqList *plist, ElemType x);  //删除所有相同的元素


bool _Inc(SeqList *plist,size_t new_capacity)  //扩容
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
	free(plist->base);              //释放旧空间
	plist->base = new_base;
	plist->capacity = new_capacity;
	return true;
}

bool IsFull(SeqList *plist)       //判满
{
	assert(plist!=NULL);
	return plist->size >= plist->capacity;
}
bool IsEmpty(SeqList *plist)     //判空
{
	assert(plist != NULL);
	return plist->size == 0;
}
void SeqListInit(SeqList *plist)   //初始化
{
	assert(plist != NULL);
	plist->capacity = SEQLIST_DEFAULT_SIZE;
	plist->base = (ElemType*)malloc(sizeof(ElemType));
	plist->size = 0;
}
void SeqListDestory(SeqList *plist)   //销毁 ---  释放空间
{
	assert(plist != NULL);
	free(plist->base);
	plist->base = NULL;
	plist->capacity = plist->size = 0;
}
void SeqListPushFront(SeqList *plist, ElemType x)
{  //头插
	assert(plist != NULL);
	if (IsFull(plist) && !_Inc(plist, plist->capacity * 2)) {
		printf("顺序表已满，头插 %d 不能插入.\n", x);
		return;
	}
	for (size_t i = plist->size; i > 0; i--) {
		plist->base[i] = plist->base[i - 1];
	}
	plist->base[0] = x;
	plist->size++;
}
void SeqListPushBack(SeqList *plist, ElemType x)
{     //尾插
	assert(plist != NULL);
	if (IsFull(plist) && !_Inc(plist,plist->capacity * 2)) {
		printf("顺序表已满，尾插 %d 不能插入.\n", x);
		return;
	}
	plist->base[plist->size++] = x;   //先放入数据，在进行数据个数加一
}
void SeqListShow(SeqList *plist)
{ //展示面板
	assert(plist != NULL);
	for (size_t i = 0; i < plist->size; ++i)
	{
		printf("%d ", plist->base[i]);
	}
	printf("\n");
}
size_t SeqListLength(SeqList *plist)   //长度
{
	assert(plist != NULL);
	return plist->size;
}
size_t SeqListCapacity(SeqList *plist)  //容量
{
	assert(plist != NULL);
	return plist->capacity;
}
void SeqListPopBack(SeqList *plist)   //尾删
{
	assert(plist != NULL);
	if (IsEmpty(plist)) {
		printf("顺序表是空的，不能进行尾部删除!\n");
	}
	plist->size--;
}
void SeqListPopFront(SeqList *plist)   //头删
{
	assert(plist != NULL);
	if (IsEmpty(plist)) {
		printf("顺序表是空的，不能进行头部删除!\n");
	}
	for(size_t i=0;i<plist->size;++i){
	    plist->base[i] = plist->base[i + 1];
	plist->size--;
	}
}
void SeqListClear(SeqList *plist)     //清空
{
	assert(plist != NULL);
	plist->size = 0;
}
bool SeqListInsertByPos(SeqList *plist, int pos, ElemType x)
{              //按位置插入
	assert(plist != NULL);
	if (IsFull(plist)) {
		printf("顺序表已满，%d 不能在 %d 位置进行插入\n", x, pos);
		return false;
	}
	if (pos < 0 || pos > plist->size) {
		printf("插入的位置 %d 是非法的,%d 不能插入\n", pos, x);
		return false;
	}
	for (size_t i = plist->size; i > pos; --i) {
		plist->base[i] = plist->base[i - 1];
		plist->base[pos] = x;
	}plist->size++;
	return true;
}
bool SeqListPopByPos(SeqList *plist, int pos)
{                  //按位置删除
	assert(plist != NULL);
	if (IsEmpty(plist)) {
		printf("顺序表为空，%d 位置的数据不能被删除\n", pos);
		return false;
	}
	if (pos < 0 || pos >= plist->size) {
		printf("删除的位置 %d 是非法的,数据不能被删除\n", pos);
		return false;
	}
	for (size_t i = pos; i < plist->size; ++i) {
		plist->base[i] = plist->base[i + 1];
	plist->size--;}
	return true;
}
void SeqListSort(SeqList *plist)
{               //排序
	assert(plist != NULL);
	for (size_t i = 0; i < plist->size - 1; ++i) {
		for (size_t j = 0; j < plist->size - i - 1; ++j) {
			if(plist->base[j]>plist->base[j+1])
			Swap(&plist->base[j], &plist->base[j + 1]);
		}
	}
}
bool SeqListInsertByVal(SeqList *plist, ElemType x)
{              //按值插入
	assert(plist != NULL); 
	if (IsFull(plist) && !_Inc(plist, plist->capacity * 2)) {
		printf("顺序表已满，%d 不能插入！\n",x);
	}
	/*  //code 1 :查找插入的位置并插入
	for (size_t i = 0; i < plist->size; ++i) {
		if (plist->base[i-1] <= x && x < plist->base[i]) {
			plist->base[i + 1] = plist->base[i];
			plist->base[i] = x;
		}
	}*/
	/* //code 2: 从前往后比较
	size_t pos = 0;
	while (pos < plist->size && x > plist->base[pos])
		pos++;
		for (size_t i = plist->size; i > pos; --i)
			plist->base[i] = plist->base[i - 1];
		plist->base[pos] = x;
	plist->size++;*/
	size_t end = plist->size - 1;          //从后往前比较
	while (end >=0 && x < plist->base[end]) {
		plist->base[end + 1] = plist->base[end];
		end--;
	}plist->base[end+1] = x;
	plist->size++;
	return true;
}
int SeqListFind(SeqList *plist, ElemType x)
{             //查找数据
	assert(plist != NULL);
	int pos = 0;
	while (pos < plist->size && x != plist->base[pos]) {
		pos++;
	}
	if (pos == plist->size)      //没有找到该位置
		pos = -1;
     return pos;
}
int Binary_Find(SeqList *plist, ElemType x) 
{   //二分查找
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
{             //按值删除
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
{                //删除相同元素
	assert(plist != NULL);
	int pos = SeqListFind(plist, x);
	if (pos == -1)
		return false;
	SeqListPopByPos(plist, pos);
}
void SeqListReverse(SeqList *plist)
{              //逆置
	assert(plist != NULL);
	if (plist->size == 1)
		return;
	int start = 0, end = plist->size - 1;
	while (start < end) {
		Swap(&plist->base[start], &plist->base[end]);
		start++; end--;
	}
}
void GetFront(SeqList *plist)  //获取首元素
{
	assert(plist != NULL);
	if (IsEmpty(plist)) {
		printf("顺序表为空，获取首元素失败\n");
	}
	printf("SeqList Front :%d\n", plist->base[0]);
}
void GetBack(SeqList *plist)
{      //取尾
	assert(plist != NULL);
	if (IsEmpty(plist)) {
		printf("顺序表为空，获取首元素失败\n");
	}
	printf("SeqList Front :%d\n", plist->base[plist->size-1]);
}


#endif