#include<stdio.h>
#include<stdlib.h>

////////////////////    栈      /////////////////////
//栈顶：插入删除     

//后入先出
//顺序表来实现

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
void stack_push(stack* st, STdatatype val)      //进栈
{
	if (st == NULL)           //空栈
		return;
	checkcapacity(st);
	st->_data[st->_size++] = val;
}
void stack_pop(stack* st)       //删除栈顶元素----出栈
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
STdatatype stack_top(stack*st)         //获取栈顶元素
{
	return st->_data[st->_size - 1];
}
void stack_destory(stack* st)       //销毁
{
	free(st->_data);
	st->_capacity = st->_size = 0;
}