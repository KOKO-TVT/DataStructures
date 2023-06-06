#include<iostream>
#include <queue>
#include"BPTree.h"

using namespace std;

int BTrees::InsertVal(int x, node* temp)
{
	int i = 0;
	while (x > temp->key[i] && i < temp->size) i++;
	for(int j = temp->size;j>i;j--)
	{
		temp->key[j] = temp->key[j - 1];
	}
	temp->key[i] = x;
	temp->size++;			//预留位置+1就是用来防备这儿的
	return i;		//返回插入的位置
}


void BTrees::Insert(int x)
{
	if(root == nullptr)		//根节点为空
	{
		root = new node();
		root->key[0] = x;
		root->IsLeaf = true;
		root->size = 1;
		root->parent = nullptr;
	}
	else
	{
		node* temp = root;
		node* parent;

		while(temp->IsLeaf == false)			//找到插入位置
		{
			parent = temp;
			for(int i = 0;i<temp->size;i++)
			{
				if(x<temp->key[i])
				{
					temp = temp->ptr[i];
					break;
				}

				if(i == temp->size-1)
				{
					temp = temp->ptr[i + 1];	//循环到最后都没有比它小的就把与最右子节点进行后续操作
					break;
				}
			}
		}
		if(temp->size<max)			//结点位置未满
		{
			InsertVal(x, temp);
			temp->parent = parent;
			temp->ptr[temp->size] = temp->ptr[temp->size - 1];
			temp->ptr[temp->size - 1] = nullptr;
		}
		else Split(x, parent, temp);	//满了就进行结点分裂
	}
}

void BTrees::Split(int x, node* parent, node* temp)
{
	node* LLeaf = new node();
	node* RLeaf = new node();
	InsertVal(x, temp);
	LLeaf->IsLeaf = RLeaf->IsLeaf = true;	//分裂出的左右叶子节点
	//分配关键字
	LLeaf->size = (max + 1) / 2;
	RLeaf->size = (max + 1) - (max + 1) / 2;

	for (int i = 0; i < max + 1; i++)		//分配链表
		LLeaf->ptr[i] = temp->ptr[i];
	LLeaf->ptr[LLeaf->size] = RLeaf;
	RLeaf->ptr[RLeaf->size] = LLeaf->ptr[max];
	LLeaf->ptr[max] = nullptr;					//叶子节点链表继承完毕

	//数据继承
	for(int i=0;i<LLeaf->size;i++)
	{
		LLeaf->key[i] = temp->key[i];
	}
	for(int i=0,j=LLeaf->size;i<RLeaf->size;i++,j++)
	{
		RLeaf->key[i] = temp->key[j];
	}

	if(temp == root)			//当插入数据的结点为根结点时，即数据中要重新推出一个结点为根结点
	{
		node* NewRoot = new node();
		NewRoot->key[0] = RLeaf->key[0];
		NewRoot->ptr[0] = LLeaf;
		NewRoot->ptr[1] = RLeaf;
		NewRoot->IsLeaf = false;
		NewRoot->size = 1;
		root = NewRoot;
		LLeaf->parent = RLeaf->parent = NewRoot;
	}

	else
	{
		InsertInternal(RLeaf->key[0], parent, LLeaf, RLeaf);	//插入关键字的结点不为根节点时
	}
}

void BTrees::InsertInternal(int x, node* temp, node* LLeaf, node* RLeaf)		//向上提的关键字结点分配
{
	if(temp->size<max)
	{
		int i = InsertVal(x, temp);
		for(int j = temp->size;j>i+1;i--)		
		{
			temp->ptr[j] = temp->ptr[j - 1];
		}
		temp->ptr[i] = LLeaf;
		temp->ptr[i + 1] = RLeaf;
	}
	else				//提上去的结点超过理论容纳，继续往上提
	{
		node* NewLchild = new node();				//父节点容量已满重新进行分裂并分配新的左右子节点
		node* NewRchild = new node();
		node* virtualPtr[max + 2];					//容量已经超了，所以肯定为4个子结点
		for(int i = 0;i<max+1;i++)
		{
			virtualPtr[i] = temp->ptr[i];
		}
		int i = InsertVal(x, temp);
		for(int j = max+1;j>i+1;j--)
		{
			virtualPtr[j] = virtualPtr[j - 1];
		}
		virtualPtr[i] = LLeaf;			//暂存数据
		virtualPtr[i + 1] = RLeaf;
		NewLchild->IsLeaf = NewRchild->IsLeaf = false;
		//处理新分配的左右结点数据
		NewLchild->size = (max + 1) / 2;
		NewRchild->size = max - (max + 1) / 2;

		for(int i = 0;i<NewLchild->size;i++)
		{
			NewLchild->key[i] = temp->key[i];
		}
		for(int i = 0,j = NewLchild->size+1;i<NewRchild->size;i++,j++)
		{
			NewRchild->key[i] = temp->key[j];
		}
		for(int i = 0;i< LLeaf->size+1;i++)
		{
			NewLchild->ptr[i] = virtualPtr[i];
		}
		for(int i=0,j =LLeaf->size+1;i<RLeaf->size+1;i++,j++)
		{
			NewRchild->ptr[i] = virtualPtr[j];
		}
		if(temp == root)				//与上面的意义相同，主要是预防会一直递归到根节点
		{
			node* NewRoot = new node;
			NewRoot->key[0] = temp->key[NewLchild->size];
			NewRoot->ptr[0] = NewLchild;
			NewRoot->ptr[1] = NewRchild;
			NewRoot->IsLeaf = false;
			NewRoot->size = 1;
			root = NewRoot;
			NewLchild->parent = NewRchild->parent = NewRoot;
		}
		else			//当提上去的结点还是达到了上限就继续来一遍
		{
			InsertInternal(temp->key[NewLchild->size],temp->parent,NewLchild,NewRchild);
		}
	}
}

bool node::Search(int x)
{
	int i = 0;
	while (i < size && x>key[i])		//过滤
		i++;
	if(key[i] == x)
	{
		cout << "查找完成";
		return true;
	}
	if(IsLeaf == true)
	{
		cout << "查找失败";
		return false;
	}
	return ptr[i]->Search(x);
}

bool BTrees::search(int x)
{
	return (root == nullptr) ? false : root->Search(x);
}


//输出插入结果
void BTrees::Print()		//队列实现
{
	queue<node*>q;
	q.push(root);
	while(!q.empty())
	{
		int size_t = q.size();
		while(size_t--)
		{
			node* t = q.front();
			for(int i=0;i<t->size+1;i++)
			{
				if(!t->IsLeaf)
				{
					q.push(t->ptr[i]);
				}
			}
			for(int i=0;i<t->size;i++)
			{
				cout << t->key[i] << ",";
			}
			cout << "\t\t";
			q.pop();
		}
		cout << endl;
	}
}


int main()
{
	BTrees BPtree;
	for(int i =0;i<100;i++)
	{
		BPtree.Insert(i);
	}
	BPtree.Print();
	BPtree.search(28);
}
