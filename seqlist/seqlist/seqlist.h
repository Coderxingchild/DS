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

