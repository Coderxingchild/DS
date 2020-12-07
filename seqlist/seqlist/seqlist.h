#pragma once
#include<stdio.h>
#include<string>
#include<stdlib.h>

typedef int SeqDataType;

typedef struct SeqList {
	SeqDataType* _data;
	int _size;
	int _capacity;
}SepList;

void seq_init(SeqList* s1);  //��ʼ��
void seq_pushback(SeqList* s1, SeqDataType cal);  //β��
void seq_popback(SeqList* s1);  //βɾ
int seq_size(SeqList* s1);   //Ԫ�ظ���
void seq_chechcapacity(SeqList* s1);  //����
void seq_print(SeqList* s1);
int seq_empty(SeqList* s1);   //�п�
SeqDataType seq_at(SeqList* s1, int pos);   //��ӡ����λ��

void seq_pushfront(SeqList* s1, SeqDataType val);   //ͷ��Ԫ��
void seq_popfront(SeqList* s1);                 //ͷɾ
void seq_insert(SeqList* s1, int pos, SeqDataType val);        //����λ�ò�������
SeqDataType seq_erase(SeqList* s1, int pos);                 //����λ��ɾ��
int seq_find(SeqList* s1, SeqDataType val);          //��������-----��������
void seq_destory(SeqList* s1);                 //����




