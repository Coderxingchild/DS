#include<stdio.h>
#include<stdlib.h>


//������

typedef char DataType;

typedef struct BNode {
	BNode* _left;
	BNode* _right;
	DataType _data;
}Node;

typedef struct BTree{ 
	Node* _root;        //�������ĸ��ڵ�
}BTree;

//void creatBinaryTree(BTree* bt)
//{
//	//����һ��������
//	bt->_root = NULL;
//}


//���������ABD##E#H##CF##G##
//�ݹ鴴��
Node* creatBinaryTree(DataType arr[],int* idx)
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
int bTreeKSize(Node* root,int k)
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





//void test()
//{
//	char arr[] = "ABD##E#H##CF##G##";
//	int idx = 0;
//	Node* root = creatBinaryTree(arr, &idx);
//}