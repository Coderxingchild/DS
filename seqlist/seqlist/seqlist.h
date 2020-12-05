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

void seq_init(SeqList* s1);  //初始化
void seq_pushback(SeqList* s1, SeqDataType cal);  //尾插
void seq_popback(SeqList* s1);  //尾删
int seq_size(SeqList* s1);   //元素个数
void seq_chechcapacity(SeqList* s1);  //扩容
void seq_print(SeqList* s1);
int seq_empty(SeqList* s1);   //判空
SeqDataType seq_at(SeqList* s1, int pos);   //打印任意位置

