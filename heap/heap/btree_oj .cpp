#include<stdio.h>
#include<stdlib.h>

typedef char DataType;
typedef struct BNode {
	BNode* _left;
	BNode* _right;
	DataType _data;
}Node;
typedef struct BTree {
	Node* _root;        //�������ĸ��ڵ�
}BTree;



//�������ķǵݹ��������------����ջ�ṹ
//�ȷ���ÿһ����㿪ʼ������·�������ʵ���ÿһ���������ջ������·���������֮���ȡջ��Ԫ�ط�����������Ϊ���������ṹ
//������ջΪ�� && ������Ϊ��

//����ջ�ṹ
typedef Node* STdatatype;
typedef struct stack {
	STdatatype *_data;
	int _size;
	int _capacity;
}stack;
void stack_init(stack* st)
{
	if (st == NULL)
		return;
	st->_data = NULL;
	st->_size = st->_capacity = 0;
}
void checkcapacity(stack* st)
{
	if (st->_capacity == st->_size) {
		int newcapacity = st->_capacity == 0 ? 1 : 2 * st->_capacity;
		st->_data = (STdatatype*)realloc(st->_data, sizeof(STdatatype)*newcapacity);
		st->_capacity = newcapacity;
	}
}
void stack_push(stack* st, STdatatype val)      //��ջ
{
	if (st == NULL)           //��ջ
		return;
	checkcapacity(st);
	st->_data[st->_size++] = val;
}
void stack_pop(stack* st)       //ɾ��ջ��Ԫ��----��ջ
{
	if (st == NULL || st->_size == 0)
		return;
	--st->_size;
}
int stack_size(stack * st)
{
	if (st == NULL)
		return;
	return st->_size;
}
int stack_empty(stack *st)
{
	if (st == NULL || st->_size == 0)
		return 1;
	else
		return 0;
}
STdatatype stack_top(stack*st)         //��ȡջ��Ԫ��
{
	return st->_data[st->_size - 1];
}
void stack_destory(stack* st)       //����
{
	free(st->_data);
	st->_capacity = st->_size = 0;
}
////////////////////////////////////////////////////
int getSize(Node* root)    //��ȡ�ڵ����
{
	if (root) {
		return getSize(root->_left) + getSize(root->_right) + 1;
	}
	return 0;
}
int* preOrderTraversal(Node* root, int* returnSize)
{  //�ǵݹ��������
	stack st;
	stack_init(&st);
	int sz = getSize(root);
	int idx = 0;
	int* arr = (int*)malloc(sizeof(int)*sz);
	while (root || !stack_empty(&st)) {
		//��ǰ������㲻�� �� ջ����
		//��������·��
		while (root) {
			arr[idx++] = root->_data;
			stack_push(&st, root);
			root = root->_left;
		}
		//��ȡջ��Ԫ�أ�����������
		root = stack_top(&st);
		stack_pop(&st);
		root = root->_right;
	}
	*returnSize = idx;
	return arr;          //��������������������Ľ��
}
int* inOrderTraversal(Node* root, int* returnSize)
{ //�ǵݹ��������
	stack st;
	stack_init(&st);
	int sz = getSize(root);
	int idx = 0;
	int* arr = (int*)malloc(sizeof(int)*sz);
	while (root || !stack_empty(&st)) {
		while (root) {         //��ڵ�ȫ����ջ
			stack_push(&st, root);
			root = root->_left;
		}
		//��ȡջ��Ԫ��
		root = stack_top(&st);
		arr[idx++] = root->_data;    //����ջ��Ԫ��
		stack_pop(&st);
		root = root->_right;
	}
	*returnSize = idx;
	return arr;
}
int* postorderTraversal(Node* root, int* returnSize)
{
	//�ǵݹ�������!!!!!!!!!!!!!!!!!!!!!!!!!!
	stack st;
	stack_init(&st);
	int sz = getSize(root);
	int idx = 0;
	int* arr = (int*)malloc(sizeof(int)*sz);
	Node* pre = NULL;     //��¼��һ�����ʵ��ĵĽ��
	while (root && !stack_empty(&st)) {
		while (root) {
			stack_push(&st, root);
			root = root->_left;
		}
		Node* top = stack_top(&st);  //ջ��
		//�ж�ջ��Ԫ���Ƿ���Է��ʣ� û��������/�������Ѿ����������
		if (top->_right == NULL || top->_right == pre) {
			arr[idx++] = top->_data;
			stack_pop(&st);
			pre = top;
		}
		else {
			root = top->_right;   //������δ����
		}
	}
	*returnSize = idx;
	return arr;
}


//�������Ľ��ĸ���

//int getSize(Node* root)    //��ȡ�ڵ����
//{
//	if (root) {
//		return getSize(root->_left) + getSize(root->_right) + 1;
//	}
//	return 0;
//}
//void preOrder(Node* root, int* arr, int* idx)
//{
//	if (root) {
//		arr[*idx] = root->_data;
//		(*idx)++;
//		preOrder(root->_left, arr, idx);
//		preOrder(root->_right, arr, idx);
//	}
//}
//int* preOrderTraversal(Node* root, int* returnSize)
//{
//	int sz = getSize(root);
//	int *arr = (int*)malloc(sizeof(int)*sz);
//	int idx = 0;
//	preOrder(root, arr, &idx);
//	*returnSize = idx;
//	return arr;
//}






//�ж�һ�Ŷ������Ƿ���ƽ������������������ĸ߶Ȳ���� 1

//int getHeight(Node* root)
//{
//	if (root) {
//		int left = getHeight(root->_left);
//		int right = getHeight(root->_right);
//		return left > right ? left + 1 : right + 1;
//	}
//	return 0;
//}
//bool isBalanced(Node* root)
//{
//	if (root == NULL)
//		return true;
//	int left = getHeight(root->_left);
//	int right = getHeight(root->_right);
//	return abs(left - right) < 2
//		&& isBalanced(root->_left) && isBalanced(root->_right);
//}




//�ж϶������ǶԳƵ�:����Գ�

//bool _isSym(Node* left, Node* right)
//{
//	if (left == NULL && right == NULL)
//		return true;
//	if (left == NULL || right == NULL)
//		return false;
//	return left->_data == right->_data
//		&&_isSym(left->_left, right->_right)
//		&& _isSym(left->_right, right->_left);
//}
//bool isSymmetric(Node* root)
//{
//	if (root == NULL)
//		return true;
//	return _isSym(root->_left, root->_right);
//}




//�ж�һ�����Ƿ�����һ����������

//bool isChildTree(Node* p, Node* q)
//{
//	if (q == NULL && p == NULL)
//		return true;
//	if (p == NULL || q == NULL)
//		return false;
//	while (p->_data != q->_data) {
//		if (p->_left)
//			p = p->_left;
//		if (p->_right)
//			p = p->_right;
//	}
//	if (isChildTree(p->_left, q->_left) && isChildTree(p->_right, q->_right))
//		return true;
//	else
//		return false;
//}

//code 2

//bool isSameTree(Node* p, Node* q)
//{
//	if (p == NULL && q == NULL)
//		return true;
//	if (q == NULL || p == NULL)
//		return false;
//
//	//����˳����ͬ-----�ṹ��ͬ
//	p->_data == q->_data
//		&& isSameTree(p->_left, q->_left)
//		&& isSameTree(q->_right, p->_right);
//		return true;
//}
//bool isSubtree(Node* s, Node* t)
//{
//	if (t == NULL)
//		return true;
//	if (s == NULL)
//		return false;
//	return isSameTree(s, t) || isSubtree(s->_left, t) || isSubtree(s->_right, t);
//}





//����������Ƿ���ͬ:ֵ��ͬ���ṹҲ��ͬ

//bool isSameTree(Node* p, Node* q)
//{
//	if (p == NULL && q == NULL)
//		return true;
//	if (q == NULL || p == NULL)
//		return false;
//
//	//����˳����ͬ-----�ṹ��ͬ
//	p->_data == q->_data
//		&& isSameTree(p->_left, q->_left)
//		&& isSameTree(q->_right, p->_right);
//		return true;
//
//	/*if (p->_data == q->_data) {
//		if( isSameTree(q->_left, p->_left) && isSameTree(q->_right, p->_right))
//			return true;
//		return false;
//	}
//	else
//		return false;*/
//}




//��ת����������������������������
//�Զ����½���

//Node* inverTree(Node* root)
//{
//	if (root == NULL)
//		return;
//	Node* left = root->_left , *node= root->_left;
//	Node* right = root->_right;
//
//	left = right;
//	right = node;
//
//	inverTree(root->_left);
//	inverTree(root->_right);
//	return root;
//}





//��������������

int maxDepth(Node* root);



//��ֵ������

//bool _isUnivalTree(Node* root ,int val)
//{
//	//����������������ֵ==������ֵ
//	if (root) {
//		root->_data == val 
//			&& _isUnivalTree(root->_left, val) 
//			&& _isUnivalTree(root->_right, val);
//	}
//	return true;
//}
//bool isUnivalTree(Node* root) {
//	if (root == NULL)
//		return;
//	return _isUnivalTree(root, 1);
//}