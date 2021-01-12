#include<stdio.h>
#include<stdlib.h>

//˳�������

//typedef int HDataType;
//typedef struct Heap {          //����һ���ѽṹ
//	HDataType* _data;
//	int _size;
//	int _capacity;
//}Heap;
//
//void Heap_init(Heap* hp)       //�ѳ�ʼ��
//{
//	if (hp == NULL)
//		return;
//	hp->_data = NULL;
//	hp->_size = hp->_capacity = 0;
//}
//int Heap_empty(Heap* hp)
//{
//	//�п�
//	if (hp == NULL || hp->_size == 0)
//		return 1;
//	else
//		return 0;
//}
//HDataType Heap_top(Heap* hp)        //��ȡ�Ѷ�Ԫ��
//{
//	if (hp == NULL || hp->_size == 0)
//		return 0;
//	return hp->_data[0];
//}
//
////С�ѽṹ�����ϵ���
//void shiftUp(int* arr, int n, int cur)
//{
//	int parent = (cur - 1) / 2;
//	while (cur > 0) {
//		if (arr[cur] < arr[parent]) {
//			int tmp = arr[cur];    //С�ڸ��ڵ㣬���н���
//			arr[cur] = arr[parent];
//			arr[parent] = tmp;
//			//���½ڵ�
//			cur = parent;
//			parent = (cur - 1) / 2;
//		}
//		else
//			break;              //��С�ڸ��ڵ㣬��������
//	}
//}
////���µ���
//void shiftDown(int* arr, int n, int curPos)
//{
//	int child = 2 * curPos + 1;
//	while (child < n) {
//		if (child + 1 < n && arr[child + 1] < arr[child])
//			++child;           //Ѱ�ҽ�С�ĺ��ӽڵ�
//		if (arr[child] < arr[curPos]) {
//			int tmp = arr[child];
//			arr[child] = arr[curPos];
//			arr[curPos] = tmp;
//			curPos = child;
//			child = 2 * curPos + 1;
//		}
//		else
//			break;
//	}
//}
//
//void checkCapacity(Heap* hp)
//{
//	if (hp->_size == hp->_capacity) {
//		hp->_capacity = hp->_capacity == 0 ? 1 : 2 * hp->_capacity;
//		hp->_data = (HDataType*)realloc(hp->_data,sizeof(HDataType)*hp->_size);
//	}
//}
////���в���������
//void Heap_push(Heap* hp, HDataType val)
//{
//	//�ѵĲ������
//	checkCapacity(hp);
//	hp->_data[hp->_size++] = val;
//	shiftUp(hp->_data, hp->_size, hp->_size - 1);
//}
//
////�ѵ�ɾ��-------------ɾ��ֵ�����/��С��
////�Ƚ��жѶ�Ԫ�������һ��Ҷ�ӽڵ㽻������ɾ�����һ��Ҷ�ӽڵ㣬�����е���
//
//void Swap(int* a, int* b)   //��������
//{
//	int tmp = *a;
//	*a = *b;
//	*b = tmp;
//}
//void Heap_pop(Heap* hp)
//{
//	//ɾ���Ѷ�Ԫ��
//	if (hp == NULL || hp->_size == 0)
//		return;
//	Swap(&hp->_data[0], &hp->_data[hp->_size - 1]);
//	hp->_size--;
//	shiftDown(hp->_data, hp->_size, 0);
//}







//�ѵĲ���
//������---------O(nlogn)

//void test()
//{
//	int arr[] = { 20,17,4,16,5,3 };
//	int n = sizeof(arr) / sizeof(arr[0]);
//	for (int i = (n - 2) / 1; i >= 0; --i) {
//		shiftDown(arr, n, i);
//	}
//	int end = n - 1;         //���һ���ڵ��λ��
//	while (end > 0) {
//		Swap(&arr[0], &arr[end]);    
//		shiftDown(arr, end, 0);
//		--end;
//	}
//}







//����

//void createHeap(int* arr, int n)
//{
//	//�����һ����Ҷ�ӽڵ㿪ʼ���µ���,���һ����Ҷ�ӽڵ� (n-2)/2
//	for (int i = (n - 2) / 2; i >= 0; --i) {
//		shiftDown(arr, n, i);
//	}
//}





//////���µ���-----------���С��
//void shiftDown(int* arr, int n, int curPos)
//{
//	int child = 2 * curPos + 1;
//	while (child < n) {
//		if (child + 1 < n && arr[child + 1] < arr[child])
//			++child;           //Ѱ�ҽ�С�ĺ��ӽڵ�
//		if (arr[child] < arr[curPos]) {
//			int tmp = arr[child];
//			arr[child] = arr[curPos];
//			arr[curPos] = tmp;
//			curPos = child;
//			child = 2 * curPos + 1;
//		}
//		else
//			break;
//	}
//}
//int main()
//{
//	int arr[] = { 10,5,3,8,7,6 };
//	shiftDown(arr, sizeof(arr)/ sizeof(arr[0]), 0);
//
//	return 0;
//}






//����Ϊ���

//void shiftDown(int *arr, int n, int curPos)
//{
//	int child = 2 * curPos + 1;
//	while (child < n) {
//		if (child + 1 < n && arr[child + 1] < arr[child]) {
//			++child;
//			if (arr[curPos] < arr[child]) {
//				int tmp = arr[curPos];
//				arr[curPos] = arr[child];
//				arr[child] = tmp;
//				curPos = child;
//				child = 2 * curPos + 1;
//			}
//			else
//				break;
//		}
//	}
//}


