#pragma onc
#include <iostream>
using namespace std;
#define max 2

class node
{
	bool IsLeaf;
	int* key;					//关键字
	node** ptr;					//结点
	node	*parent;	
	int size;					//结点当前大小
	friend class BTrees;		//声明友元	不然btree中的函数无法访问变量
public:
	node():key(new int[max+1]),parent(nullptr),ptr(new node*[max+1]) {}
};

class BTrees
{
	node* root = nullptr;
	void InsertInternal(int, node*, node*, node*);			//节点插入
	void Split(int, node*, node*);					//分裂节点
	int InsertVal(int, node*);						//进入结点，忽略大小限制，寻找节点的插入位置
public:
	void Insert(int x);								//寻找关键字应该插入的叶子结点位置
	void Print();									//打印结果
};
