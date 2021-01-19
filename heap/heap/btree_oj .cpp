#include<stdio.h>
#include<stdlib.h>

typedef char DataType;
typedef struct BNode {
	BNode* _left;
	BNode* _right;
	DataType _data;
}Node;
typedef struct BTree {
	Node* _root;        //二叉树的根节点
}BTree;



//二叉树的非递归先序遍历------利用栈结构
//先访问每一个结点开始的最左路径，访问到的每一个结点先入栈，最左路径访问完成之后获取栈顶元素访问其右子树为根的字数结构
//结束：栈为空 && 右子树为空

//调用栈结构
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
void stack_push(stack* st, STdatatype val)      //进栈
{
	if (st == NULL)           //空栈
		return;
	checkcapacity(st);
	st->_data[st->_size++] = val;
}
void stack_pop(stack* st)       //删除栈顶元素----出栈
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
STdatatype stack_top(stack*st)         //获取栈顶元素
{
	return st->_data[st->_size - 1];
}
void stack_destory(stack* st)       //销毁
{
	free(st->_data);
	st->_capacity = st->_size = 0;
}
////////////////////////////////////////////////////
int getSize(Node* root)    //获取节点个数
{
	if (root) {
		return getSize(root->_left) + getSize(root->_right) + 1;
	}
	return 0;
}
int* preOrderTraversal(Node* root, int* returnSize)
{  //非递归先序遍历
	stack st;
	stack_init(&st);
	int sz = getSize(root);
	int idx = 0;
	int* arr = (int*)malloc(sizeof(int)*sz);
	while (root || !stack_empty(&st)) {
		//当前遍历结点不空 或 栈不空
		//访问最左路径
		while (root) {
			arr[idx++] = root->_data;
			stack_push(&st, root);
			root = root->_left;
		}
		//获取栈顶元素，访问右子树
		root = stack_top(&st);
		stack_pop(&st);
		root = root->_right;
	}
	*returnSize = idx;
	return arr;          //数组用来保存先序遍历的结果
}
int* inOrderTraversal(Node* root, int* returnSize)
{ //非递归中序遍历
	stack st;
	stack_init(&st);
	int sz = getSize(root);
	int idx = 0;
	int* arr = (int*)malloc(sizeof(int)*sz);
	while (root || !stack_empty(&st)) {
		while (root) {         //左节点全部入栈
			stack_push(&st, root);
			root = root->_left;
		}
		//获取栈顶元素
		root = stack_top(&st);
		arr[idx++] = root->_data;    //保存栈顶元素
		stack_pop(&st);
		root = root->_right;
	}
	*returnSize = idx;
	return arr;
}
int* postorderTraversal(Node* root, int* returnSize)
{
	//非递归后序遍历!!!!!!!!!!!!!!!!!!!!!!!!!!
	stack st;
	stack_init(&st);
	int sz = getSize(root);
	int idx = 0;
	int* arr = (int*)malloc(sizeof(int)*sz);
	Node* pre = NULL;     //记录上一步访问到的的结点
	while (root && !stack_empty(&st)) {
		while (root) {
			stack_push(&st, root);
			root = root->_left;
		}
		Node* top = stack_top(&st);  //栈顶
		//判断栈顶元素是否可以访问？ 没有右子树/右子树已经被访问完成
		if (top->_right == NULL || top->_right == pre) {
			arr[idx++] = top->_data;
			stack_pop(&st);
			pre = top;
		}
		else {
			root = top->_right;   //右子树未访问
		}
	}
	*returnSize = idx;
	return arr;
}


//二叉树的结点的个数

//int getSize(Node* root)    //获取节点个数
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






//判断一颗二叉树是否是平衡二叉树：左右子树的高度差不超过 1

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




//判断二叉树是对称的:镜像对称

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




//判断一个树是否是另一个树的子树

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
//	//遍历顺序相同-----结构相同
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





//检查两棵树是否相同:值相同、结构也相同

//bool isSameTree(Node* p, Node* q)
//{
//	if (p == NULL && q == NULL)
//		return true;
//	if (q == NULL || p == NULL)
//		return false;
//
//	//遍历顺序相同-----结构相同
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




//翻转二叉树：左右子树交换，根不变
//自顶向下交换

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





//二叉树的最大深度

int maxDepth(Node* root);



//单值二叉树

//bool _isUnivalTree(Node* root ,int val)
//{
//	//遍历二叉树中所有值==根结点的值
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