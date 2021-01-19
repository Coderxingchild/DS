#include<stdio.h>
#include<stdlib.h>

//��������ʵ�ֶ�������α���

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




//������

#include<stdio.h>
#include<stdlib.h>


//������

typedef char DataType;

typedef struct BNode {
	BNode* _left;
	BNode* _right;
	DataType _data;
}Node;

typedef struct BTree {
	Node* _root;        //�������ĸ��ڵ�
}BTree;

//void creatBinaryTree(BTree* bt)
//{
//	//����һ��������
//	bt->_root = NULL;
//}


//���������ABD##E#H##CF##G##
//�ݹ鴴��
Node* creatBinaryTree(DataType arr[], int* idx)
{
	//���ض������ĸ��ڵ�ָ��
	if (arr[*idx] == '#') {
		(*idx)++;
		return NULL;      //����
	}
	Node* root = (Node*)malloc(sizeof(Node));
	root->_data = arr[*idx];
	(*idx)++;

	root->_left = creatBinaryTree(arr, idx);
	root->_right = creatBinaryTree(arr, idx);
	return root;
}
void preOrder(Node* root)     //�������: ������
{
	if (root) {
		printf("%c ", root->_data);

		preOrder(root->_left);
		preOrder(root->_right);
	}
}
void inOrder(Node* root)   //��������� �����
{
	if (root) {
		inOrder(root->_left);
		printf("%c ", root->_data);
		inOrder(root->_right);
	}
}
void postOrder(Node* root)       //������������Ҹ�
{
	if (root) {
		postOrder(root->_left);
		postOrder(root->_right);
		printf("%c ", root->_data);
	}
}

//�������ڵ����==����������+����������+1 
int bTreeSize(Node* root)
{
	if (root == NULL)
		return 0;
	return bTreeSize(root->_left) + bTreeSize(root->_right) + 1;
}
//�������ĸ߶�:������/������ȡ��߸߶�+1
int bTreeHeight(Node* root)
{
	if (root == NULL)
		return 0;
	int left = bTreeHeight(root->_left);
	int right = bTreeHeight(root->_right);
	return left > right ? left + 1 : right + 1;
}
//������Ҷ�ӽڵ����
int bTreeLeafSize(Node* root)
{
	if (root == NULL)
		return 0;
	if (root->_left == NULL && root->_right == NULL)
		return 1;
	//��Ҷ��
	return bTreeLeafSize(root->_left) + bTreeLeafSize(root->_right);
}
//��K��ڵ����:���ڵ�ǰ�ڵ�����������ĵ�k-1��ڵ����
int bTreeKSize(Node* root, int k)
{
	if (root == NULL)
		return 0;
	if (1 == k)
		return 1;
	return bTreeKSize(root->_left, k - 1) + bTreeKSize(root->_right, k - 1);
}
//����ֵΪX�Ľڵ�
Node* bTreeFind(Node* root, char ch)
{
	if (root) {
		Node* node;
		if (root->_data == ch)    //�ж��Ƿ�Ϊ���ڵ�
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
//������������ !!!!!!!!!!!!!!!!!!!!!!!!!!!
void bTreeDestory(Node** root)
{
	if (*root) {
		bTreeDestory(&((*root)->_left));
		bTreeDestory(&((*root)->_right));
		free(*root);
		*root = NULL;
	}
}



//�������Ĳ�α���----------����˼�������

//��Ҫ���ö��д���

void bTreeLevelOder(Node* root)      //��α���
{
	Queue q;
	Queue_init(&q);
	if (root)
		Queue_push(&q, root);
	while (!Queue_empty(&q)) {
		Node* front = Queue_front(&q);
		Queue_pop(&q);        //ɾ����ͷԪ��
		printf("%c ", front->_data);
		if (front->_left)
			Queue_push(&q, front->_left);
		if (front->_right)
			Queue_push(&q, front->_right);
	}
}


//�ж϶������Ƿ�����ȫ������
//���ղ�α�����˼�룬����ж϶����н���Ƿ�����
//������-------����ȫ������
//����-------��ȫ������

int isCompleteBtree(Node* root)
{
	Queue q;
	Queue_init(&q);
	if (root)
		Queue_push(&q, root);
	while (!Queue_empty(&q)) {
		Node* front = Queue_front(&q);
		Queue_pop(&q);
		//���Һ������
		if (front) {
			Queue_push(&q, front->_left);
			Queue_push(&q, front->_right);
		}
		else
			break;
	}         //������һ��NULL �������ѭ������ʼ��������
	//�鿴������
	while (!Queue_empty(&q)) {
		Node* front = Queue_front(&q);
		Queue_pop(&q);
		if (front)
			return 0;
	}
	return 1;         //��ȫ������
}



//void test()
//{
//	char arr[] = "ABD##E#H##CF##G##";
//	int idx = 0;
//	Node* root = creatBinaryTree(arr, &idx);
//  bTreeLevelOder(root);
//}









//���������������ж��Ƿ�Ϊ��ȫ������
//����������֪�ӿ�
//void push_back(list* lst, Node* a);      //β��
//void pop_front(list* lst);            //ͷɾ
//Node* head(list* lst);             //��ȡ��ͷԪ��


//int listEmpty(Node* root)         //�п�
//{
//	list lst;
//	list_init(&lst);
//	push_back(&lst, root);   //β��
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
//	//�ж�ʣ��
//	while (!listEmpty(&lst)) {
//		Node* front = head(&lst);
//		pop_front(&lst);
//		if (front)
//			return 0;     //����ȫ
//	}
//	return 1;       //��ȫ������
//}