
//堆的操作










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


