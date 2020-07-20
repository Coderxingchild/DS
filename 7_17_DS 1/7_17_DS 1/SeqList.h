//作业 2020_7_16

#ifndef _SEQLIST_H_
#define _SEQLIST_H_

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

#pragma warning(disable:4996)

#define MAX_SIZE 16

#define SLDateType int

typedef struct SeqList
{
	SLDateType* a;
	size_t size;
	size_t capacity; // unsigned int
}SeqList;

// 对数据的管理:增删查改 
void SeqListInit(SeqList* ps);   //初始化
void SeqListDestory(SeqList* ps); // 销毁

void SeqListPrint(SeqList* ps);  //显示打印
void SeqListPushBack(SeqList* ps, SLDateType x);  //头插
void SeqListPushFront(SeqList* ps, SLDateType x); //尾插
void SeqListPopFront(SeqList* ps);  //头删
void SeqListPopBack(SeqList* ps);  //尾删

// 顺序表查找
int SeqListFind(SeqList* ps, SLDateType x);
// 顺序表在pos位置插入x
void SeqListInsert(SeqList* ps, size_t pos, SLDateType x);
// 顺序表删除pos位置的值
void SeqListErase(SeqList* ps, size_t pos);



void SeqListInit(SeqList* ps)   //初始化
{
	assert(ps != NULL);
	ps->capacity = MAX_SIZE;
	ps->size = 0;
	ps->a = (SLDateType*)malloc(sizeof(SLDateType));
}
void SeqListDestory(SeqList* ps)  //销毁
{
	assert(ps != NULL);
	free(ps->a);
	ps->a = NULL;
	ps->size = ps->capacity = 0;
}
void SeqListPrint(SeqList* ps)  //显示打印数据
{
	assert(ps != NULL);
	for (size_t i = 0; i < ps->size; ++i) {
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}
int IsFull(SeqList* ps)   //判满
{
	assert(ps != NULL);
	return ps->size >= ps->capacity;
}
int IsEmpty(SeqList* ps)   //判空
{
	assert(ps != NULL);
	return ps->size < ps->capacity;
}
void SeqListPushFront(SeqList* ps, SLDateType x)  //头插
{
	assert(ps != NULL);
	if (IsFull(ps)) {
		printf("表已满，不能进行头插操作！\n");
	}
	for (size_t i = ps->size; i > 0; --i) {
		ps->a[i] = ps->a[i - 1];
	}
	ps->a[0] = x;
	ps->size++;
}
void SeqListPushBack(SeqList* ps, SLDateType x)  //尾插
{
	assert(ps != NULL);
	if (IsFull(ps))
	{
		printf("表已满，不能进行尾部插入！\n");
	}
	ps->a[ps->size++] = x;
}
void SeqListPopFront(SeqList* ps)  //头删
{
	assert(ps != NULL);
	/*if (IsEmpty(ps)) {
		printf("表为空，不能进行头删操作！\n");
	}*/
	for (size_t i = 0; i < ps->size; ++i)
	{
		ps->a[i] = ps->a[i + 1];
	}ps->size--;
}
void SeqListPopBack(SeqList* ps)  //尾删
{
	assert(ps != NULL);
	/*if (IsEmpty(ps)) {
		printf("表为空，不能进行尾删操作！\n");
	}*/
	ps->size--;
} 
int SeqListFind(SeqList* ps, SLDateType x)  //查找
{
	assert(ps != NULL);
	int pos = 0;
	while (pos < ps->size && x != ps->a[pos]) {
		pos++;
	}
	if (pos == ps->size)
		pos = -1;
	return pos;
}
void SeqListInsert(SeqList* ps, size_t pos, SLDateType x)  //按位置插入
{
	assert(ps != NULL);
	if (IsFull(ps)) {
		printf("表已满，插入失败！\n");
	}
	if (pos<0 || pos>ps->size) {
		printf("插入的位置非法！\n");
	}
	for (size_t i = ps->size; i >= pos; --i) {
		ps->a[i] = ps->a[i - 1];
		ps->a[pos] = x;
	}
	ps->size++;
}

void SeqListErase(SeqList* ps, size_t pos)  //按位置删除
{
	assert(ps != NULL);
	if (IsEmpty(ps)) {
		printf("表为空，不能进行删除操作！\n");
	}
	if (pos<0 || pos>ps->size) {
		printf("删除的位置非法！\n");
	}
	for (size_t i = pos; i < ps->size; ++i) {
		ps->a[i] = ps->a[i + 1];
	}
	ps->size--;
}


#endif