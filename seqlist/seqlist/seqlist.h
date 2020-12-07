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

void seq_pushfront(SeqList* s1, SeqDataType val);   //头插元素
void seq_popfront(SeqList* s1);                 //头删
void seq_insert(SeqList* s1, int pos, SeqDataType val);        //任意位置插入数据
SeqDataType seq_erase(SeqList* s1, int pos);                 //任意位置删除
int seq_find(SeqList* s1, SeqDataType val);          //查找数据-----返回索引
void seq_destory(SeqList* s1);                 //销毁




