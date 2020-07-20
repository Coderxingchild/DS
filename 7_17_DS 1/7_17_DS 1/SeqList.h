//��ҵ 2020_7_16

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

// �����ݵĹ���:��ɾ��� 
void SeqListInit(SeqList* ps);   //��ʼ��
void SeqListDestory(SeqList* ps); // ����

void SeqListPrint(SeqList* ps);  //��ʾ��ӡ
void SeqListPushBack(SeqList* ps, SLDateType x);  //ͷ��
void SeqListPushFront(SeqList* ps, SLDateType x); //β��
void SeqListPopFront(SeqList* ps);  //ͷɾ
void SeqListPopBack(SeqList* ps);  //βɾ

// ˳������
int SeqListFind(SeqList* ps, SLDateType x);
// ˳�����posλ�ò���x
void SeqListInsert(SeqList* ps, size_t pos, SLDateType x);
// ˳���ɾ��posλ�õ�ֵ
void SeqListErase(SeqList* ps, size_t pos);



void SeqListInit(SeqList* ps)   //��ʼ��
{
	assert(ps != NULL);
	ps->capacity = MAX_SIZE;
	ps->size = 0;
	ps->a = (SLDateType*)malloc(sizeof(SLDateType));
}
void SeqListDestory(SeqList* ps)  //����
{
	assert(ps != NULL);
	free(ps->a);
	ps->a = NULL;
	ps->size = ps->capacity = 0;
}
void SeqListPrint(SeqList* ps)  //��ʾ��ӡ����
{
	assert(ps != NULL);
	for (size_t i = 0; i < ps->size; ++i) {
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}
int IsFull(SeqList* ps)   //����
{
	assert(ps != NULL);
	return ps->size >= ps->capacity;
}
int IsEmpty(SeqList* ps)   //�п�
{
	assert(ps != NULL);
	return ps->size < ps->capacity;
}
void SeqListPushFront(SeqList* ps, SLDateType x)  //ͷ��
{
	assert(ps != NULL);
	if (IsFull(ps)) {
		printf("�����������ܽ���ͷ�������\n");
	}
	for (size_t i = ps->size; i > 0; --i) {
		ps->a[i] = ps->a[i - 1];
	}
	ps->a[0] = x;
	ps->size++;
}
void SeqListPushBack(SeqList* ps, SLDateType x)  //β��
{
	assert(ps != NULL);
	if (IsFull(ps))
	{
		printf("�����������ܽ���β�����룡\n");
	}
	ps->a[ps->size++] = x;
}
void SeqListPopFront(SeqList* ps)  //ͷɾ
{
	assert(ps != NULL);
	/*if (IsEmpty(ps)) {
		printf("��Ϊ�գ����ܽ���ͷɾ������\n");
	}*/
	for (size_t i = 0; i < ps->size; ++i)
	{
		ps->a[i] = ps->a[i + 1];
	}ps->size--;
}
void SeqListPopBack(SeqList* ps)  //βɾ
{
	assert(ps != NULL);
	/*if (IsEmpty(ps)) {
		printf("��Ϊ�գ����ܽ���βɾ������\n");
	}*/
	ps->size--;
} 
int SeqListFind(SeqList* ps, SLDateType x)  //����
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
void SeqListInsert(SeqList* ps, size_t pos, SLDateType x)  //��λ�ò���
{
	assert(ps != NULL);
	if (IsFull(ps)) {
		printf("������������ʧ�ܣ�\n");
	}
	if (pos<0 || pos>ps->size) {
		printf("�����λ�÷Ƿ���\n");
	}
	for (size_t i = ps->size; i >= pos; --i) {
		ps->a[i] = ps->a[i - 1];
		ps->a[pos] = x;
	}
	ps->size++;
}

void SeqListErase(SeqList* ps, size_t pos)  //��λ��ɾ��
{
	assert(ps != NULL);
	if (IsEmpty(ps)) {
		printf("��Ϊ�գ����ܽ���ɾ��������\n");
	}
	if (pos<0 || pos>ps->size) {
		printf("ɾ����λ�÷Ƿ���\n");
	}
	for (size_t i = pos; i < ps->size; ++i) {
		ps->a[i] = ps->a[i + 1];
	}
	ps->size--;
}


#endif