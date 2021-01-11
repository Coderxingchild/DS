#include<stdio.h>
#include<stdlib.h>

//////////////////////////////    ��ͷ    /////////////////////////////
//��ͷ��ɾ��     ��β������      
//�Ƚ��ȳ�


//��βָ��ĵ�����

typedef int Qdatatype;
typedef struct QNode {
	Qdatatype _data;
	struct QNode* _next;
}QNode;
typedef struct Queue {
	QNode* _head;
	QNode* _tail;
	int _size;
}Queue;
void Queue_init(Queue * q)
{
	if (q == NULL)
		return;
	q->_head = q->_tail = NULL;
	q->_size = 0;
}
QNode* creatNode(Qdatatype val)              //�����½ڵ�
{
	QNode* node = (QNode*)malloc(sizeof(QNode));
	node->_data = val;
	node->_next = NULL;
}
void Queue_push(Queue* q, Qdatatype val)     //����------��β
{
	QNode* node = creatNode(val);
	if (q->_head == NULL)
		q->_head = q->_tail = node;
	else {
		q->_tail->_next = node;
		q->_tail = node;
	}
	++q->_size;
} 
void Queue_pop(Queue* q)                 //ɾ��------��ͷ
{
	if (q == NULL || q->_head == NULL) 
		return;
	QNode* next = q->_head->_next;
	free(q->_head);
	q->_head = next;
	
	//���������ֻ��һ������
	if (q->_head == NULL)
		q->_tail = NULL;
	--q->_size;
}
int Queue_empty(Queue* q)                //�п�
{
	/*if (q == NULL || q->_head == NULL)
		return 1;
	return 0;*/
	return q->_head == NULL;
}
Qdatatype Queue_front(Queue* q)      //ȡ��ͷ
{
	/*if (q == NULL || q->_head == NULL)
		return;*/
	return q->_head->_data;
}
Qdatatype Queue_back(Queue* q)      //ȡ��β
{
	return q->_tail->_data;
}
int	Queue_size(Queue* q)
{
	if (q == NULL)
		return 0;
	return q->_size;
}
void Queue_destory(Queue* q)
{
	QNode* cur = q->_head;
	while (cur) {
		QNode* next = cur->_next;
		free(cur);
		cur = next;
	}
	q->_head = q->_tail = NULL;
}