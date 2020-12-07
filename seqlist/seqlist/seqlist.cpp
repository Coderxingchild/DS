
#include "seqlist.h"

//˳���
//1.�ռ�����
//2.֧���������
//3.β�塢βɾ  O(1)
//4.�ռ������ʸߣ���������ڴ���Ƭ
//5.����λ�ò���ɾ��  O(n)
//6.���ݵĴ��۱Ƚϴ󣺿������� memcpy
//�ʺϷ��ʡ��洢



void seq_init(SeqList* s1)  //��ʼ��
{
	s1->_data = NULL;
	s1->_capacity = s1->_size = 0;
}
void seq_pushback(SeqList* s1, SeqDataType val)  //β��
{
	if (s1 == NULL)
		return;
	if (s1->_size == s1->_capacity) {
		seq_chechcapacity(s1);
	}
	s1->_data[s1->_size++] = val;
}
void seq_popback(SeqList* s1)   //βɾ
{
	if (s1 == NULL)
		return;
	s1->_size--;
}
void seq_chechcapacity(SeqList* s1)  //����
{
	int newcapacity = s1->_capacity == 0 ? 1 : 2 * s1->_capacity;
	SeqDataType* tmp = (SeqDataType*)malloc(newcapacity * sizeof(SeqDataType));
	memcpy(tmp, s1->_data, sizeof(SeqDataType)*(s1->_size));
	free(s1->_data);         //�ͷ�ԭ�пռ�
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
int seq_empty(SeqList* s1)   //�п�
{
	if (s1 == NULL || s1->_size == 0)
		return 0;
	return 1;
}
int seq_size(SeqList* s1)   //Ԫ�ظ���
{
	return s1->_size;
}
SeqDataType seq_at(SeqList* s1, int pos)   //��ӡ����λ��
{
	if (pos >= 0 && pos < s1->_size) {
		printf("%d\n", s1->_data[pos]);
	}
	return s1->_data[pos];
}
void seq_pushfront(SeqList* s1, SeqDataType val)  //ͷ��Ԫ��
{
	if (s1 == NULL)
		return;
	//����
	seq_chechcapacity(s1);

	//�ƶ�Ԫ��
	int end = s1->_size;
	while (end > 0) {
		s1->_data[end] = s1->_data[end - 1];
		--end;
	}
	s1->_data[0] = val;
	++s1->_size;
}

void seq_popfront(SeqList* s1)                //ͷɾ
{
	if (s1 == NULL || s1->_size == 0)
		return;
	//�ƶ�Ԫ��
	int start = 1;
	while (start < s1->_size) {
		s1->_data[start - 1] = s1->_data[start];
		++start;
	}
	//�޸�size
	--s1->_size;
}
void seq_insert(SeqList* s1, int pos, SeqDataType val)        //����λ�ò�������
{
	if (s1 == NULL)
		return;
	seq_chechcapacity(s1);  //����Ԫ��-------���Ƚ�������
	//�ƶ�Ԫ��
	if (pos >= 0 && pos <= s1->_size) {      //���λ�õ���Ч��
		int end = s1->_size;
		while (end > pos) {
			s1->_data[end] = s1->_data[end - 1];
			--end;
		}
	}
	s1->_data[pos] = val;
	++s1->_size;
}
SeqDataType seq_erase(SeqList* s1, int pos)                //����λ��ɾ��
{
	if (s1 == NULL || s1->_size ==0)
		return 0;
	//����Ԫ��----------------Ԫ���ƶ�����
	if (pos >= 0 && pos < s1->_size) {     //�ж�ɾ��λ�õĺϷ���
		int start = pos + 1;
		while (start < s1->_size) {
			s1->_data[start - 1] = s1->_data[start];
			start++;
		}
	}
	//�޸�size 
	s1->_size--;
	return s1->_data[pos];
}
int seq_find(SeqList* s1, SeqDataType val)         //��������-----��������
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
void seq_destory(SeqList* s1)                //����
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
