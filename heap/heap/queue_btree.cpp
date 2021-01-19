#include<stdio.h>
#include<stdlib.h>

//借助队列实现二叉树层次遍历

typedef Node* Qdatatype;
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
QNode* creatNode(Qdatatype val)              //创建新节点
{
	QNode* node = (QNode*)malloc(sizeof(QNode));
	node->_data = val;
	node->_next = NULL;
}
void Queue_push(Queue* q, Qdatatype val)     //插入------队尾
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
void Queue_pop(Queue* q)                 //删除------队头
{
	if (q == NULL || q->_head == NULL)
		return;
	QNode* next = q->_head->_next;
	free(q->_head);
	q->_head = next;

	//如果队列中只有一个数据
	if (q->_head == NULL)
		q->_tail = NULL;
	--q->_size;
}
int Queue_empty(Queue* q)                //判空
{
	/*if (q == NULL || q->_head == NULL)
		return 1;
	return 0;*/
	return q->_head == NULL;
}
Qdatatype Queue_front(Queue* q)      //取队头
{
	/*if (q == NULL || q->_head == NULL)
		return;*/
	return q->_head->_data;
}
Qdatatype Queue_back(Queue* q)      //取队尾
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




//二叉树

#include<stdio.h>
#include<stdlib.h>


//二叉树

typedef char DataType;

typedef struct BNode {
	BNode* _left;
	BNode* _right;
	DataType _data;
}Node;

typedef struct BTree {
	Node* _root;        //二叉树的根节点
}BTree;

//void creatBinaryTree(BTree* bt)
//{
//	//创建一个二叉树
//	bt->_root = NULL;
//}


//先序遍历：ABD##E#H##CF##G##
//递归创建
Node* creatBinaryTree(DataType arr[], int* idx)
{
	//返回二叉树的根节点指针
	if (arr[*idx] == '#') {
		(*idx)++;
		return NULL;      //空树
	}
	Node* root = (Node*)malloc(sizeof(Node));
	root->_data = arr[*idx];
	(*idx)++;

	root->_left = creatBinaryTree(arr, idx);
	root->_right = creatBinaryTree(arr, idx);
	return root;
}
void preOrder(Node* root)     //先序遍历: 根左右
{
	if (root) {
		printf("%c ", root->_data);

		preOrder(root->_left);
		preOrder(root->_right);
	}
}
void inOrder(Node* root)   //中序遍历： 左根右
{
	if (root) {
		inOrder(root->_left);
		printf("%c ", root->_data);
		inOrder(root->_right);
	}
}
void postOrder(Node* root)       //后序遍历：左右根
{
	if (root) {
		postOrder(root->_left);
		postOrder(root->_right);
		printf("%c ", root->_data);
	}
}

//二叉树节点个数==左子树个数+右子树个数+1 
int bTreeSize(Node* root)
{
	if (root == NULL)
		return 0;
	return bTreeSize(root->_left) + bTreeSize(root->_right) + 1;
}
//二叉树的高度:左子树/右子树取最高高度+1
int bTreeHeight(Node* root)
{
	if (root == NULL)
		return 0;
	int left = bTreeHeight(root->_left);
	int right = bTreeHeight(root->_right);
	return left > right ? left + 1 : right + 1;
}
//二叉树叶子节点个数
int bTreeLeafSize(Node* root)
{
	if (root == NULL)
		return 0;
	if (root->_left == NULL && root->_right == NULL)
		return 1;
	//非叶子
	return bTreeLeafSize(root->_left) + bTreeLeafSize(root->_right);
}
//第K层节点个数:等于当前节点的左右子树的第k-1层节点个数
int bTreeKSize(Node* root, int k)
{
	if (root == NULL)
		return 0;
	if (1 == k)
		return 1;
	return bTreeKSize(root->_left, k - 1) + bTreeKSize(root->_right, k - 1);
}
//查找值为X的节点
Node* bTreeFind(Node* root, char ch)
{
	if (root) {
		Node* node;
		if (root->_data == ch)    //判断是否为根节点
			return root;
		node = bTreeFind(root->_left, ch);
		if (node)
			return node;
		else
			return bTreeFind(root->_right, ch);
	}
	else
		return NULL;
}
//二叉树的销毁 !!!!!!!!!!!!!!!!!!!!!!!!!!!
void bTreeDestory(Node** root)
{
	if (*root) {
		bTreeDestory(&((*root)->_left));
		bTreeDestory(&((*root)->_right));
		free(*root);
		*root = NULL;
	}
}



//二叉树的层次遍历----------队列思想来完成

//需要附用队列代码

void bTreeLevelOder(Node* root)      //层次遍历
{
	Queue q;
	Queue_init(&q);
	if (root)
		Queue_push(&q, root);
	while (!Queue_empty(&q)) {
		Node* front = Queue_front(&q);
		Queue_pop(&q);        //删除队头元素
		printf("%c ", front->_data);
		if (front->_left)
			Queue_push(&q, front->_left);
		if (front->_right)
			Queue_push(&q, front->_right);
	}
}


//判断二叉树是否是完全二叉树
//按照层次遍历的思想，入队判断队列中结点是否连续
//不连续-------不完全二叉树
//连续-------完全二叉树

int isCompleteBtree(Node* root)
{
	Queue q;
	Queue_init(&q);
	if (root)
		Queue_push(&q, root);
	while (!Queue_empty(&q)) {
		Node* front = Queue_front(&q);
		Queue_pop(&q);
		//左右孩子入队
		if (front) {
			Queue_push(&q, front->_left);
			Queue_push(&q, front->_right);
		}
		else
			break;
	}         //遇到第一个NULL 结点跳出循环，开始后续遍历
	//查看结点情况
	while (!Queue_empty(&q)) {
		Node* front = Queue_front(&q);
		Queue_pop(&q);
		if (front)
			return 0;
	}
	return 1;         //完全二叉树
}



//void test()
//{
//	char arr[] = "ABD##E#H##CF##G##";
//	int idx = 0;
//	Node* root = creatBinaryTree(arr, &idx);
//  bTreeLevelOder(root);
//}









//假设利用链表来判断是否为完全二叉树
//给出如下已知接口
//void push_back(list* lst, Node* a);      //尾插
//void pop_front(list* lst);            //头删
//Node* head(list* lst);             //获取队头元素


//int listEmpty(Node* root)         //判空
//{
//	list lst;
//	list_init(&lst);
//	push_back(&lst, root);   //尾插
//	while (!listEmpty(&lst)) {
//		Node* front = head(&lst);
//		pop_front(&lst);
//		if (front) {
//			push_back(&lst, front->_left);
//			push_back(&lst, front->_right);
//		}
//		else
//			break;
//	}
//	//判断剩余
//	while (!listEmpty(&lst)) {
//		Node* front = head(&lst);
//		pop_front(&lst);
//		if (front)
//			return 0;     //非完全
//	}
//	return 1;       //完全二叉树
//}