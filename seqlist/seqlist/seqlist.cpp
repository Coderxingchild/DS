
#include "seqlist.h"

//顺序表
//1.空间连续
//2.支持随机访问
//3.尾插、尾删  O(1)
//4.空间利用率高，不易造成内存碎片
//5.其他位置插入删除  O(n)
//6.增容的代价比较大：拷贝内容 memcpy
//适合访问、存储



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
	SeqDataType* tmp = (SeqDataType*)malloc(newcapacity * sizeof(SeqDataType));
	memcpy(tmp, s1->_data, sizeof(SeqDataType)*(s1->_size));
	free(s1->_data);         //释放原有空间
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
void seq_pushfront(SeqList* s1, SeqDataType val)  //头插元素
{
	if (s1 == NULL)
		return;
	//扩容
	seq_chechcapacity(s1);

	//移动元素
	int end = s1->_size;
	while (end > 0) {
		s1->_data[end] = s1->_data[end - 1];
		--end;
	}
	s1->_data[0] = val;
	++s1->_size;
}

void seq_popfront(SeqList* s1)                //头删
{
	if (s1 == NULL || s1->_size == 0)
		return;
	//移动元素
	int start = 1;
	while (start < s1->_size) {
		s1->_data[start - 1] = s1->_data[start];
		++start;
	}
	//修改size
	--s1->_size;
}
void seq_insert(SeqList* s1, int pos, SeqDataType val)        //任意位置插入数据
{
	if (s1 == NULL)
		return;
	seq_chechcapacity(s1);  //插入元素-------首先进行扩容
	//移动元素
	if (pos >= 0 && pos <= s1->_size) {      //检查位置的有效性
		int end = s1->_size;
		while (end > pos) {
			s1->_data[end] = s1->_data[end - 1];
			--end;
		}
	}
	s1->_data[pos] = val;
	++s1->_size;
}
SeqDataType seq_erase(SeqList* s1, int pos)                //任意位置删除
{
	if (s1 == NULL || s1->_size ==0)
		return 0;
	//插入元素----------------元素移动方向
	if (pos >= 0 && pos < s1->_size) {     //判断删除位置的合法性
		int start = pos + 1;
		while (start < s1->_size) {
			s1->_data[start - 1] = s1->_data[start];
			start++;
		}
	}
	//修改size 
	s1->_size--;
	return s1->_data[pos];
}
int seq_find(SeqList* s1, SeqDataType val)         //查找数据-----返回索引
{
	if (s1 == NULL || s1->_size == 0)
		return 0;
	for (int i = 0; i < s1->_size; ++i)
	{
		if (s1->_data[i] == val)
			return i;
	}
	return 0;
}
void seq_destory(SeqList* s1)                //销毁
{
	if (s1 != NULL && s1->_data != NULL) {
		free(s1->_data);
		s1->_data = NULL;
	}
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
	seq_print(&s1);
	
	seq_at(&s1, 3);
	printf("%d\n",seq_size(&s1));
	
	seq_insert(&s1, 2, 7);
	seq_print(&s1);

	seq_erase(&s1, 3);
	seq_print(&s1);
}

int main()
{
	test();
	return 0;
}
