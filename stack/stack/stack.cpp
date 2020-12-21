#include<stdio.h>
#include<stdlib.h>

////////////////////    Õ»      /////////////////////
//Õ»¶¥£º²åÈëÉ¾³ý

//ºóÈëÏÈ³ö

typedef int STdatatype;

typedef struct stack {
	STdatatype *_data;
	int _size;
	int _capacity;
}stack;

void stack_init(stack* st)
{
	if (st == NULL)
		return;
	st->_data = NULL;
	st->_size = st->_capacity = 0;
}
void checkcapacity(stack* st)
{
	if (st->_capacity == st->_size) {
		int newcapacity = st->_capacity == 0 ? 1 : 2 * st->_capacity;
		st->_data = (STdatatype*)realloc(st->_data, sizeof(STdatatype)*newcapacity);
		st->_capacity = newcapacity;
	}
}
void stack_push(stack* st, STdatatype val)      //½øÕ»
{
	if (st == NULL)           //¿ÕÕ»
		return;
	checkcapacity(st);
	st->_data[st->_size++] = val;
}
void stack_pop(stack* st)       //É¾³ýÕ»¶¥ÔªËØ----³öÕ»
{
	if (st == NULL || st->_size == 0)
		return;
	--st->_size;
}
int stack_size(stack * st)
{
	if (st == NULL)
		return;
	return st->_size;
}
int stack_empty(stack *st)
{
	if (st == NULL || st->_size == 0)
		return 1;
	else
		return 0;
}
STdatatype stack_top(stack*st)         //»ñÈ¡Õ»¶¥ÔªËØ
{
	return st->_data[st->_size - 1];
}
void stack_destory(stack* st)       //Ïú»Ù
{
	free(st->_data);
	st->_capacity = st->_size = 0;
}