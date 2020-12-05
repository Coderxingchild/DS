
#include "seqlist.h"

void seq_init(SeqList* s1)  //初始化
{
	s1->_data = NULL;
	s1->_capacity = s1->_size = 0;
}
void seq_pushback(SeqList* s1, SeqDataType val)  //尾插
{
	if (s1 == NULL)
		return;
	if (s1->_size == s1->_capacity) {
		seq_chechcapacity(s1);
	}
	s1->_data[s1->_size++] = val;
}
void seq_popback(SeqList* s1)   //尾删
{
	if (s1 == NULL)
		return;
	s1->_size--;
}
void seq_chechcapacity(SeqList* s1)  //扩容
{
	int newcapacity = s1->_capacity == 0 ? 1 : 2 * s1->_capacity;
	SeqDataType* tmp = (SeqDataType*)malloc(sizeof(newcapacity) * sizeof(SeqDataType));
	memcpy(tmp, s1->_data, sizeof(SeqDataType)*(s1->_size));
	free(s1->_data);
	s1->_data = tmp;
	s1->_capacity = newcapacity;
}
void seq_print(SeqList* s1)
{
	if (s1 == NULL)
		return;
	for (int i = 0; i < s1->_size; ++i)
	{
		printf("%d ", s1->_data[i]);
	}
	printf("\n");
}
int seq_empty(SeqList* s1)   //判空
{
	if (s1 == NULL || s1->_size == 0)
		return 0;
	return 1;
}
int seq_size(SeqList* s1)   //元素个数
{
	return s1->_size;
}
SeqDataType seq_at(SeqList* s1, int pos)   //打印任意位置
{
	if (pos >= 0 && pos < s1->_size) {
		printf("%d\n", s1->_data[pos]);
	}
	return s1->_data[pos];
}

void test()
{
	SeqList s1;
	seq_init(&s1);
	seq_pushback(&s1, 1);
	seq_pushback(&s1, 2);
	seq_pushback(&s1, 3);
	seq_pushback(&s1, 4);
	seq_pushback(&s1, 5);
	seq_print(&s1);

	seq_popback(&s1);
	seq_popback(&s1);
	seq_popback(&s1);
	seq_print(&s1);

	seq_pushback(&s1, 3);
	seq_pushback(&s1, 4);
	seq_pushback(&s1, 5);
	seq_at(&s1, 3);

	seq_size(&s1);
	seq_print(&s1);

}

int main()
{
	test();
	return 0;
}
