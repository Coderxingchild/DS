#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>



typedef struct {
	int _front;
	int _rear;    //队尾元素下一个位置
	int _k;      //元素个数
	int* _data; 
}mycirclequeue;
mycirclequeue* mycircle_queuecreat(int k)
{
	mycirclequeue* cq = (mycirclequeue*)malloc(sizeof(mycirclequeue));
	cq->_front = cq->_rear = 0;        //队头==队尾   表示空队列
	cq->_k = k;
	cq->_data = (int*)malloc(sizeof(int)*(k + 1));
	return cq;
}
bool mycircle_isfull(mycirclequeue* obj)
{
	return (obj->_rear + 1) % (obj->_k + 1) == obj->_front;
}
bool mycircle_isempty(mycirclequeue* obj)
{
	return obj->_front == obj->_rear;
}
bool mycircle_Enqueue(mycirclequeue* obj, int val)
{
	//入队
	if (mycircle_isfull(obj))
		return false;
	obj->_data[obj->_rear++] = val;
	if (obj->_rear > obj ->_k)
		obj->_rear = 0;
	return true;
}
bool mycircle_Dequeue(mycirclequeue* obj)
{
	//出队
	if (mycircle_isempty(obj))
		return false;
	obj->_front++;   //队头出队

	if (obj->_front > obj->_k)
		obj->_front = 0;
	return true;
}
int mycircle_frontqueue(mycirclequeue* obj)
{
	if (mycircle_isempty(obj))
		return -1;
	return obj->_data[obj->_front];
}
int mycircle_rearqueue(mycirclequeue* obj)
{
	if (mycircle_isempty(obj))
		return -1;
	if (obj->_rear != 0)
		return obj->_data[obj->_rear - 1];
	else
		return obj->_data[obj->_k];
}
void mycircle_freequeue(mycirclequeue* obj)
{
	free(obj->_data);
	free(obj);
}
void test()
{
	mycirclequeue cq;
	mycircle_queuecreat(4);
	mycircle_Enqueue(&cq, 1);
	mycircle_Enqueue(&cq, 2);
	mycircle_Enqueue(&cq, 3);
	printf("%d \n",mycircle_rearqueue(&cq));
	printf("%d \n", mycircle_frontqueue(&cq));
	
	mycircle_Dequeue(&cq);
	mycircle_freequeue(&cq);
}
int main()
{
	test();
	return 0;
}