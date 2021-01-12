#include<stdio.h>
#include<stdlib.h>

//顺序二叉树

//typedef int HDataType;
//typedef struct Heap {          //定义一个堆结构
//	HDataType* _data;
//	int _size;
//	int _capacity;
//}Heap;
//
//void Heap_init(Heap* hp)       //堆初始化
//{
//	if (hp == NULL)
//		return;
//	hp->_data = NULL;
//	hp->_size = hp->_capacity = 0;
//}
//int Heap_empty(Heap* hp)
//{
//	//判空
//	if (hp == NULL || hp->_size == 0)
//		return 1;
//	else
//		return 0;
//}
//HDataType Heap_top(Heap* hp)        //获取堆顶元素
//{
//	if (hp == NULL || hp->_size == 0)
//		return 0;
//	return hp->_data[0];
//}
//
////小堆结构：向上调整
//void shiftUp(int* arr, int n, int cur)
//{
//	int parent = (cur - 1) / 2;
//	while (cur > 0) {
//		if (arr[cur] < arr[parent]) {
//			int tmp = arr[cur];    //小于父节点，进行交换
//			arr[cur] = arr[parent];
//			arr[parent] = tmp;
//			//更新节点
//			cur = parent;
//			parent = (cur - 1) / 2;
//		}
//		else
//			break;              //不小于父节点，结束调整
//	}
//}
////向下调整
//void shiftDown(int* arr, int n, int curPos)
//{
//	int child = 2 * curPos + 1;
//	while (child < n) {
//		if (child + 1 < n && arr[child + 1] < arr[child])
//			++child;           //寻找较小的孩子节点
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
////堆中插入新数据
//void Heap_push(Heap* hp, HDataType val)
//{
//	//堆的插入操作
//	checkCapacity(hp);
//	hp->_data[hp->_size++] = val;
//	shiftUp(hp->_data, hp->_size, hp->_size - 1);
//}
//
////堆的删除-------------删最值（最大/最小）
////先进行堆顶元素与最后一个叶子节点交换，在删除最后一个叶子节点，最后进行调整
//
//void Swap(int* a, int* b)   //交换函数
//{
//	int tmp = *a;
//	*a = *b;
//	*b = tmp;
//}
//void Heap_pop(Heap* hp)
//{
//	//删除堆顶元素
//	if (hp == NULL || hp->_size == 0)
//		return;
//	Swap(&hp->_data[0], &hp->_data[hp->_size - 1]);
//	hp->_size--;
//	shiftDown(hp->_data, hp->_size, 0);
//}







//堆的操作
//堆排序---------O(nlogn)

//void test()
//{
//	int arr[] = { 20,17,4,16,5,3 };
//	int n = sizeof(arr) / sizeof(arr[0]);
//	for (int i = (n - 2) / 1; i >= 0; --i) {
//		shiftDown(arr, n, i);
//	}
//	int end = n - 1;         //最后一个节点的位置
//	while (end > 0) {
//		Swap(&arr[0], &arr[end]);    
//		shiftDown(arr, end, 0);
//		--end;
//	}
//}







//建堆

//void createHeap(int* arr, int n)
//{
//	//从最后一个非叶子节点开始向下调整,最后一个非叶子节点 (n-2)/2
//	for (int i = (n - 2) / 2; i >= 0; --i) {
//		shiftDown(arr, n, i);
//	}
//}





//////向下调整-----------变成小堆
//void shiftDown(int* arr, int n, int curPos)
//{
//	int child = 2 * curPos + 1;
//	while (child < n) {
//		if (child + 1 < n && arr[child + 1] < arr[child])
//			++child;           //寻找较小的孩子节点
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






//调整为大堆

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


