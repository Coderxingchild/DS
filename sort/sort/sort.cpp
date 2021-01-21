#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>


//������ȶ��ԣ�ͬһ��������ͬԪ������ǰ������λ�ò������仯���������ȶ�




//��������:ʱ�临�Ӷȣ�O(nlogn)
//���ػ���֮���׼ֵ����λ��


//��������ǰ��ָ�뷨
//pre ����һ��С�ڻ�׼ֵ��λ��     cur����һ��С�ڻ�׼ֵ��λ��
// pre �� cur �����������ڵ�ֵ�������ڻ�׼ֵ������ pre cur; ����������������к��д��ڻ�׼ֵ��λ��,���� pre�� ���������� cur 

int partion3(int* arr, int begin, int end)
{
	int mid = getMid(arr, begin, end);
	Swap(arr, begin, mid);       //����ȡ�з�

	int pre = begin;
	int cur = begin + 1;
	int key = arr[begin];       //��׼ֵ
	while(cur <= end) {
		if (arr[cur] < key && ++pre != cur) {
		//�ж��Ƿ�����,������������ pre cur ������
			Swap(arr, pre, cur);
		} 
		++cur;
	}
	Swap(arr, begin, pre);
	return pre;          //����Ϊ pre ǰ�ߺͺ��������
}







//���������ڿӷ�

int partion1(int* arr, int begin, int end)
{
	int mid = getMid(arr, begin, end);
	Swap(arr, begin, mid);       //����ȡ�з�

	int key = arr[begin];  //��׼ֵ
	int tol = begin;        //��¼��
	while (begin < end) {
		while (begin < end && arr[end] >= key) {
			--end;            //�Ӻ���ǰ��С��
		}
		arr[tol] = arr[end];
		tol = end;            //���¿�λ��
		while (begin < end && arr[begin] <= key) {
			++begin;            //��ǰ�����Ҵ��
		}
		arr[tol] = arr[begin];
		tol = begin;          //���¿�λ��
	}
	arr[begin] = key;
	return begin;
}





//��������hoare ��

int partion(int* arr, int begin, int end)   //����
{
	//ѡ���׼ֵ

	/*int mid = getMid(arr, begin, end);
	Swap(arr, begin, mid);*/             //��ȡ����ȡ�з�������׼ֵ��������ջ�������

	int key = arr[begin];       //��¼��ʼֵ
	int start = begin;            //��¼��ʼλ��
	while (begin < end) 
	{
		//�Ӻ���ǰ��С�ڻ�׼ֵ��λ��
		while (begin < end && arr[end] >= key) {
			--end;
		}
		//��ǰ����Ҵ��ڻ�׼ֵ��λ��
		while (begin < end && arr[begin] <= key) {
			++begin;
		}
		//���� ��ʼ �� ������λ��
		Swap(arr, begin, end);
	}
	//������׼ֵ������λ�õ�ֵ
	Swap(arr, start, begin);
	return begin;
}
//��������ʱ���ÿ���������ܻᵼ��ջ��� ------> ��������ʱʱ�临�Ӷ� O(n^2)
//δʹ������ȡ�з��Ż�ʱ���ᵼ��ջ���  O(n^2):��Ϊջ�ĵ��ò���---��Ԫ�صĸ���
//ʹ������ȡ���Ż��󣬻��ֽϾ���------> O(nlogn)��ջ�ĵ��ò��� ~ logn
//���ȶ��� 6 10 4 6 7 8 19   ---------  6 10 19 6 7 8 4 ------ 8 10 19 6 7 6 4 ������ 6 �����λ�÷����仯�� 
void quickSort(int* arr, int begin, int end)
{
	if (begin >= end)
		return;
	//div :һ�λ���֮�󣬻�׼ֵλ��
		int div = partion(arr, begin, end);
		//�����������ٽ��п���
		quickSort(arr, begin, div - 1);  //�ݹ����
		quickSort(arr, div + 1, end);
}

//�Ż�����
void quickSort1(int* arr, int begin, int end)
{
	if (begin >= end)
		return;
	//div :һ�λ���֮�󣬻�׼ֵλ��
	if (end - begin < 10) {
		insertSort(arr + begin, end - begin + 1);  //С�����Ż�
	}
	else {
		int div = partion(arr, begin, end);
		//�����������ٽ��п���
		quickSort(arr, begin, div - 1);  //�ݹ����
		quickSort(arr, div + 1, end);
	}
}

//�ǵݹ���� !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//������ջ�������
/////�ǵݹ����------˳��� ʵ��
void quickSort2(int* arr, int n)
{
	//����˳�����������������䣨�ԣ�
	seqlist sq;
	seqlist_init(&sq);
	//���ȱ����������䣬�ȱ��������䣬�ڴ��������
	seqlist_pushback(&sq, n - 1);
	seqlist_pushback(&sq, 0);
	while (!seqlist_empty(&sq)) {
		//ȡ��һ������
		int left = seqlist_Back(&sq); //ȡβ��Ԫ��
		seqlist_popback(&sq);
		int right = seqlist_Back(&sq);
		seqlist_popback(&sq);

		//��������:�����������ٰ�������ֵʱ�������䱣�棬���ֻ��һ��ֵ���ǻ�׼ֵ�򲻱���
		int div = partion(arr, left, right);
		//���������������
		if (left < div - 1) {
			//��ʾ����������ֵ
			seqlist_pushback(&sq, div - 1);
			seqliat_pushback(&sq, left);
		}
		if (div + 1 < right) {
			seqlist_pushback(&sq, right);
			seqliat_pushback(&sq, div + 1);
		}
	}
}
/////�ǵݹ����------ջ ʵ��
void quickSort3(int* arr, int n)
{
	stack st;       //����ջ�ṹ
	stack_init(&st);
	stack_push(&st, n - 1);    //�Ҷ˵���ջ
	stack_push(&st, 0);    //��˵���ջ
	while (!stack_empty(&st)) {
		int left = stack_top(&st); //��ȡջ��Ԫ��
		stack_pop(&st);         //��ջ
		int right = stack_top(&st);
		stack_pop(&st);

		//��������:�ȴ���Ҷ˵㣬������˵�
		int div = partion(arr, left, right);
		if (left < div - 1) {
			stack_push(&st, div - 1);
			stack_push(&st, left);
		}
		if (div + 1 < right) {
			stack_push(&st, right);
			stack_push(&st, div + 1);
		}
	}
}
///////�ǵݹ����-------���� ʵ��
void quickSort4(int* arr, int n)
{
	queue q;
	queue_init(&q);
	queue_push(&q, 0);    //�ȴ����˵�
	queue_push(&q, n - 1);      //����Ҷ˵�
	while (!queue_empty(&q)) {
		int left = queue_front(&q);
		queue_pop(&q);      //��ͷ����
		int right = queue_front(&q);
		queue_pop(&q);
		//��������
		int div = partion(arr, left, right);
		//��������������������
		if (left < div - 1) {
			queue_push(&q, left);
			queue_push(&q, div - 1);
		}
		if (div + 1 < right) {
			queue_push(&q, div + 1);
			queue_push(&q, right);
		}
	}
}


//��ȡ��׼ֵ������ȡ�з�
int getMid(int* arr, int begin, int end)
{
	int mid = begin + (end - begin) / 2;
	if (arr[begin] > arr[mid]) {
		if (arr[mid] > arr[end])
			return mid;
		else if (arr[begin] > arr[end])     //begin > end && begin > mid
			return end;
		else              //end > begin > mid
			return begin;
	}
	else {
		if (arr[mid] < arr[end])     //begin < mid < end
			return mid;
		else if (arr[begin] < arr[end])     //begin < mid && begin <end && mid >= end
			return end;
		else
			return begin;            //end < begin < mid
	}
}









//ð����������Ԫ�ؽ��бȽ�
//ʱ�临�Ӷȣ�O(n^2) --------- �����£�����
//            O(n)   --------- ����������ʱ
//�ȶ�����
                                                                                 
void Swap(int* arr, int pos1, int pos2)
{
	int tmp = arr[pos1];
	arr[pos1] = arr[pos2];
	arr[pos2] = tmp;
}
void bubbleSort(int* arr, int n)
{
	int end = n;
	while (end > 1) {
		int flag = 0;        //���λ
		//for (int i = 0; i < end - 1; ++i) {
		for (int i = 1; i < end; ++i) {
			if (arr[i - 1] > arr[i]) {
				Swap(arr, i - 1, i);
				flag = 1;         //ʵ�ֽ�������־λ�� 1 
			}
		}
		if (!flag)
			break;
		--end;           //�����γɵ�������
	}
}





//������O(nlogn)

void shiftDown(int* arr, int n, int parent)
{
	int child = 2 * parent + 1;
	while (child < n) {
		if (child + 1 < n && arr[child + 1] > arr[child])
			++child;
		if (arr[child] > arr[parent]) {
			Swap(arr, child, parent);
			child = 2 * parent + 1;
		}
		else
			break;
	}
}
void heapSort(int* arr, int n)
{
	for (int i = (n - 2) / 2; i >= 0; --i) {
		shiftDown(arr, n, i);    //���������
	}
	int end = n - 1;
	while (end > 0) {          
		Swap(arr, end, 0);
		shiftDown(arr, end, 0);
		--end;
	}
}



//ѡ������---------���ȶ�����
//ʱ�临�Ӷȣ�O(n^2)

void Swap(int* arr, int pos1, int pos2)
{
	int tmp = arr[pos1];
	arr[pos1] = arr[pos2];
	arr[pos2] = tmp;
}
void selectSort(int* arr, int n)    //ÿ��Ѱ����С��ֵ���н���
{
	//��δ���������������ֵ���ŵ�δ�������ʼλ��
	int start = 0;
	int end = n - 1;
	while (start < end) {
		int minIdx = start;
		int i ;
		for (i = start + 1; i <= end; ++i) {
			if (arr[i] < arr[minIdx])     //���ȶ����� 4 3 4 1 
				minIdx = i;
		}
		//����Сֵ�ŵ���ʼ��λ��
		Swap(arr, start, minIdx);
		++start;
	}
}
void selectSort(int* arr, int n)        //ÿ��Ѱ��һ����Сֵ �� һ�����ֵ
{
	int start = 0;
	int end = n - 1;
	//ÿ��Ѱ�������С����ֵ
	//��С��ͷ��������β��
	while (start < end) {
		int min = start;
		int max = end;
		for (int j = start + 1; j < end; ++j) {
			if (arr[j] < arr[min])
				min = j;
			if (arr[j] > max)
				max = j;
		}
		Swap(arr, start, min);   //��Сֵ��ͷ��
		if (max == start)      //�ж����ֵ��ʼʱ���Ƿ���ͷ��
			max = min;
		Swap(arr, end, max);    //���ֵ��β��
		++start;
		--end;
	}
}





//ϣ������
//ʱ�临�Ӷȣ�O(n) ~ O(n^2)

void shellSort(int* arr, int n)
{
	//һ��ϣ������:gap �����ļ��
	int gap = n;
	while (gap > 1) {
		gap = gap / 3 + 1;
		for (int i = gap; i < n; ++i) {
			int end = i - gap;
			int data = arr[i];
			while (end >= 0 && arr[end] > data) {
				arr[end + gap] = arr[end];
				end -= gap;
			}
			arr[end + gap] = data;
		}
	}
}






//��������
//ʱ�临�Ӷȣ�O��n^2�� ---------  �����£�����
//��������ʱ��ʱ�临�Ӷ�Ϊ O(n) -------- ����Ҫ����

void insertSort(int* arr, int n)
{
	for (int i = 1; i < n; ++i) {
		int end = i - 1;
		int data = arr[i];
		while (end >= 0 && arr[end] >= data) {
			arr[end + 1] = arr[end];
			--end;
		}
		arr[end + 1] = data;
	}

//code 
	//if (n <= 1)
	//	return;
	//for (int i = 1; i < n; ++i) {
	//	int tem = 0;
	//	int j = i - 1;       //��¼���һ������λ��
	//	while (j >= 0 && arr[j] > arr[i]) {
	//		tem = arr[i];         //���������Ԫ��
	//		arr[j + 1] = arr[j];         //�ƶ�����Ԫ��
	//		j--;
	//	}
	//	//�ҵ���һ��С�ڴ��������ݵ�Ԫ�ؽ��в���
	//	arr[j + 1] = tem;
	//}
}
void printArr(int* arr, int n) 
{
	for (int i = 0; i < n; ++i)
		printf("%d ", arr[i]);
	printf("\n");
}




void test()
{
	/*int arr[] = { 7,9,0,6,8,5,2,1,4,3 };*/
	int *arr;
	int n;
	srand(time(NULL));          
	printf("������������ ");
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		arr[i] = rand();      //�����
	}

	//int begin = clock();
	//bubbleSort(arr,n);
	//int end = clock();       //��¼����ʱ��
	//printf("bubbleSort: %d \n",end - begin);            //colck() ������¼ʱ��
}







