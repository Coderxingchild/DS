#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>


//排序的稳定性：同一序列中相同元素排序前后的相对位置不发生变化则该排序较稳定




//快速排序:时间复杂度：O(nlogn)
//返回划分之后基准值所在位置


//快速排序：前后指针法
//pre ：上一个小于基准值的位置     cur：下一个小于基准值的位置
// pre 与 cur 连续：区间内的值都不大于基准值，更新 pre cur; 不连续，则该区间中含有大于基准值的位置,更新 pre， 交换，更新 cur 

int partion3(int* arr, int begin, int end)
{
	int mid = getMid(arr, begin, end);
	Swap(arr, begin, mid);       //三数取中法

	int pre = begin;
	int cur = begin + 1;
	int key = arr[begin];       //基准值
	while(cur <= end) {
		if (arr[cur] < key && ++pre != cur) {
		//判断是否连续,不连续，交换 pre cur 中数据
			Swap(arr, pre, cur);
		} 
		++cur;
	}
	Swap(arr, begin, pre);
	return pre;          //划分为 pre 前边和后边两部分
}







//快速排序：挖坑法

int partion1(int* arr, int begin, int end)
{
	int mid = getMid(arr, begin, end);
	Swap(arr, begin, mid);       //三数取中法

	int key = arr[begin];  //基准值
	int tol = begin;        //记录坑
	while (begin < end) {
		while (begin < end && arr[end] >= key) {
			--end;            //从后向前找小的
		}
		arr[tol] = arr[end];
		tol = end;            //更新坑位置
		while (begin < end && arr[begin] <= key) {
			++begin;            //从前往后找大的
		}
		arr[tol] = arr[begin];
		tol = begin;          //更新坑位置
	}
	arr[begin] = key;
	return begin;
}





//快速排序：hoare 法

int partion(int* arr, int begin, int end)   //划分
{
	//选择基准值

	/*int mid = getMid(arr, begin, end);
	Swap(arr, begin, mid);*/             //采取三数取中法决定基准值：避免了栈溢出问题

	int key = arr[begin];       //记录起始值
	int start = begin;            //记录起始位置
	while (begin < end) 
	{
		//从后向前找小于基准值的位置
		while (begin < end && arr[end] >= key) {
			--end;
		}
		//从前向后找大于基准值的位置
		while (begin < end && arr[begin] <= key) {
			++begin;
		}
		//交换 起始 与 结束的位置
		Swap(arr, begin, end);
	}
	//交换基准值和相遇位置的值
	Swap(arr, start, begin);
	return begin;
}
//数据有序时调用快速排序可能会导致栈溢出 ------> 数据有序时时间复杂度 O(n^2)
//未使用三数取中法优化时，会导致栈溢出  O(n^2):因为栈的调用层数---》元素的个数
//使用三数取中优化后，划分较均衡------> O(nlogn)：栈的调用层数 ~ logn
//不稳定： 6 10 4 6 7 8 19   ---------  6 10 19 6 7 8 4 ------ 8 10 19 6 7 6 4 （两个 6 的相对位置发生变化） 
void quickSort(int* arr, int begin, int end)
{
	if (begin >= end)
		return;
	//div :一次划分之后，基准值位置
		int div = partion(arr, begin, end);
		//左右两部分再进行快排
		quickSort(arr, begin, div - 1);  //递归调用
		quickSort(arr, div + 1, end);
}

//优化快排
void quickSort1(int* arr, int begin, int end)
{
	if (begin >= end)
		return;
	//div :一次划分之后，基准值位置
	if (end - begin < 10) {
		insertSort(arr + begin, end - begin + 1);  //小区间优化
	}
	else {
		int div = partion(arr, begin, end);
		//左右两部分再进行快排
		quickSort(arr, begin, div - 1);  //递归调用
		quickSort(arr, div + 1, end);
	}
}

//非递归快排 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//不会有栈溢出风险
/////非递归快排------顺序表 实现
void quickSort2(int* arr, int n)
{
	//调用顺序表来保存待排序区间（略）
	seqlist sq;
	seqlist_init(&sq);
	//首先保存整个区间，先保存右区间，在存放左区间
	seqlist_pushback(&sq, n - 1);
	seqlist_pushback(&sq, 0);
	while (!seqlist_empty(&sq)) {
		//取出一个区间
		int left = seqlist_Back(&sq); //取尾部元素
		seqlist_popback(&sq);
		int right = seqlist_Back(&sq);
		seqlist_popback(&sq);

		//划分区间:当区间中至少包含两个值时进行区间保存，如果只有一个值或是基准值则不保存
		int div = partion(arr, left, right);
		//保存产生的新区间
		if (left < div - 1) {
			//表示至少有两个值
			seqlist_pushback(&sq, div - 1);
			seqliat_pushback(&sq, left);
		}
		if (div + 1 < right) {
			seqlist_pushback(&sq, right);
			seqliat_pushback(&sq, div + 1);
		}
	}
}
/////非递归快排------栈 实现
void quickSort3(int* arr, int n)
{
	stack st;       //调用栈结构
	stack_init(&st);
	stack_push(&st, n - 1);    //右端点入栈
	stack_push(&st, 0);    //左端点入栈
	while (!stack_empty(&st)) {
		int left = stack_top(&st); //获取栈顶元素
		stack_pop(&st);         //出栈
		int right = stack_top(&st);
		stack_pop(&st);

		//划分区间:先存放右端点，后存放左端点
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
///////非递归快排-------队列 实现
void quickSort4(int* arr, int n)
{
	queue q;
	queue_init(&q);
	queue_push(&q, 0);    //先存放左端点
	queue_push(&q, n - 1);      //存放右端点
	while (!queue_empty(&q)) {
		int left = queue_front(&q);
		queue_pop(&q);      //队头出队
		int right = queue_front(&q);
		queue_pop(&q);
		//划分区间
		int div = partion(arr, left, right);
		//分析产生的两个新区间
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


//获取基准值：三数取中法
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









//冒泡排序：相邻元素进行比较
//时间复杂度：O(n^2) --------- 最坏情况下，逆序
//            O(n)   --------- 当数据有序时
//稳定排序
                                                                                 
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
		int flag = 0;        //标记位
		//for (int i = 0; i < end - 1; ++i) {
		for (int i = 1; i < end; ++i) {
			if (arr[i - 1] > arr[i]) {
				Swap(arr, i - 1, i);
				flag = 1;         //实现交换，标志位置 1 
			}
		}
		if (!flag)
			break;
		--end;           //最终形成递增序列
	}
}





//堆排序：O(nlogn)

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
		shiftDown(arr, n, i);    //创建大根堆
	}
	int end = n - 1;
	while (end > 0) {          
		Swap(arr, end, 0);
		shiftDown(arr, end, 0);
		--end;
	}
}



//选择排序---------不稳定排序
//时间复杂度：O(n^2)

void Swap(int* arr, int pos1, int pos2)
{
	int tmp = arr[pos1];
	arr[pos1] = arr[pos2];
	arr[pos2] = tmp;
}
void selectSort(int* arr, int n)    //每次寻找最小的值进行交换
{
	//从未排序的序列中找最值，放到未排序的起始位置
	int start = 0;
	int end = n - 1;
	while (start < end) {
		int minIdx = start;
		int i ;
		for (i = start + 1; i <= end; ++i) {
			if (arr[i] < arr[minIdx])     //不稳定排序 4 3 4 1 
				minIdx = i;
		}
		//把最小值放到开始的位置
		Swap(arr, start, minIdx);
		++start;
	}
}
void selectSort(int* arr, int n)        //每次寻找一个最小值 与 一个最大值
{
	int start = 0;
	int end = n - 1;
	//每次寻找最大、最小两个值
	//最小放头部，最大放尾部
	while (start < end) {
		int min = start;
		int max = end;
		for (int j = start + 1; j < end; ++j) {
			if (arr[j] < arr[min])
				min = j;
			if (arr[j] > max)
				max = j;
		}
		Swap(arr, start, min);   //最小值放头部
		if (max == start)      //判断最大值开始时候是否在头部
			max = min;
		Swap(arr, end, max);    //最大值放尾部
		++start;
		--end;
	}
}





//希尔排序
//时间复杂度：O(n) ~ O(n^2)

void shellSort(int* arr, int n)
{
	//一趟希尔排序:gap 交换的间隔
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






//插入排序
//时间复杂度：O（n^2） ---------  最坏情况下（逆序）
//数据有序时，时间复杂度为 O(n) -------- 不需要排序

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
	//	int j = i - 1;       //记录最后一个有序位置
	//	while (j >= 0 && arr[j] > arr[i]) {
	//		tem = arr[i];         //保存待排序元素
	//		arr[j + 1] = arr[j];         //移动有序元素
	//		j--;
	//	}
	//	//找到第一个小于待排序数据的元素进行插入
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
	printf("输入数据量： ");
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		arr[i] = rand();      //随机数
	}

	//int begin = clock();
	//bubbleSort(arr,n);
	//int end = clock();       //记录运行时间
	//printf("bubbleSort: %d \n",end - begin);            //colck() 用来记录时间
}







