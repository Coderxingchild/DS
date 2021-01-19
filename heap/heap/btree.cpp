#include<stdio.h>
#include<stdlib.h>


//二叉树

typedef char DataType;

typedef struct BNode {
	BNode* _left;
	BNode* _right;
	DataType _data;
}Node;

typedef struct BTree{ 
	Node* _root;        //二叉树的根节点
}BTree;

//void creatBinaryTree(BTree* bt)
//{
//	//创建一个二叉树
//	bt->_root = NULL;
//}


//先序遍历：ABD##E#H##CF##G##
//递归创建
Node* creatBinaryTree(DataType arr[],int* idx)
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
int bTreeKSize(Node* root,int k)
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





//void test()
//{
//	char arr[] = "ABD##E#H##CF##G##";
//	int idx = 0;
//	Node* root = creatBinaryTree(arr, &idx);
//}