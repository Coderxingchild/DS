#ifndef _COMMON_H_
#define _COMMON_H_

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>
#include<memory.h>
//#include<vld.h>     //�����ڴ�й©���

#define ElemType int

void Swap(ElemType *a, ElemType *b)
{
	ElemType temp = *a;
	*a = *b;
	*b = temp;
}

#endif
