//二叉搜索树
#include <iostream>
using namespace std;

struct BstNode
{
	int data;
	BstNode* left;
	BstNode* right;
};


//函数实现
BstNode* GetNewNode(int data)
{
	BstNode* NewNode = new BstNode();
	NewNode->data = data;
	NewNode->left = NewNode->right = nullptr;
	return NewNode;
}

BstNode* Insert(BstNode* root,int data)
{
	if (root == nullptr)
	{
		root = GetNewNode(data);
		return root;
	}
	else if(data <= root->data)
	{
		root->left = Insert(root->left, data);
	}
	else
	{
		root->right = Insert(root->right, data);
	}
	return root;
}

bool Search(BstNode* root,int data)
{
	if (root == nullptr) return false;
	if (root->data == data) return true;
	if (data < root->data)	return Search(root->left, data);
	else return Search(root->right, data);
}


int main()
{
	BstNode* root = nullptr;
	root = Insert(root, 15);
	root = Insert(root, 10);
	root = Insert(root, 20);
	root = Insert(root, 25);
	root = Insert(root, 8);
	root = Insert(root, 12);
	int number;
	cout << "请输入你所想要查询的数据";
	cin >> number;
	if (Search(root, number))	cout << "数据存在";
	else cout << "数据不存在";
}

