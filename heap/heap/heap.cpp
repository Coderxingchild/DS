
//�ѵĲ���










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


