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
	temp->size++;			//Ԥ��λ��+1�����������������
	return i;		//���ز����λ��
}


void BTrees::Insert(int x)
{
	if(root == nullptr)		//���ڵ�Ϊ��
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

		while(temp->IsLeaf == false)			//�ҵ�����λ��
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
					temp = temp->ptr[i + 1];	//ѭ�������û�б���С�ľͰ��������ӽڵ���к�������
					break;
				}
			}
		}
		if(temp->size<max)			//���λ��δ��
		{
			InsertVal(x, temp);
			temp->parent = parent;
			temp->ptr[temp->size] = temp->ptr[temp->size - 1];
			temp->ptr[temp->size - 1] = nullptr;
		}
		else Split(x, parent, temp);	//���˾ͽ��н�����
	}
}

void BTrees::Split(int x, node* parent, node* temp)
{
	node* LLeaf = new node();
	node* RLeaf = new node();
	InsertVal(x, temp);
	LLeaf->IsLeaf = RLeaf->IsLeaf = true;	//���ѳ�������Ҷ�ӽڵ�
	//����ؼ���
	LLeaf->size = (max + 1) / 2;
	RLeaf->size = (max + 1) - (max + 1) / 2;

	for (int i = 0; i < max + 1; i++)		//��������
		LLeaf->ptr[i] = temp->ptr[i];
	LLeaf->ptr[LLeaf->size] = RLeaf;
	RLeaf->ptr[RLeaf->size] = LLeaf->ptr[max];
	LLeaf->ptr[max] = nullptr;					//Ҷ�ӽڵ�����̳����

	//���ݼ̳�
	for(int i=0;i<LLeaf->size;i++)
	{
		LLeaf->key[i] = temp->key[i];
	}
	for(int i=0,j=LLeaf->size;i<RLeaf->size;i++,j++)
	{
		RLeaf->key[i] = temp->key[j];
	}

	if(temp == root)			//���������ݵĽ��Ϊ�����ʱ����������Ҫ�����Ƴ�һ�����Ϊ�����
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
		InsertInternal(RLeaf->key[0], parent, LLeaf, RLeaf);	//����ؼ��ֵĽ�㲻Ϊ���ڵ�ʱ
	}
}

void BTrees::InsertInternal(int x, node* temp, node* LLeaf, node* RLeaf)		//������Ĺؼ��ֽ�����
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
	else				//����ȥ�Ľ�㳬���������ɣ�����������
	{
		node* NewLchild = new node();				//���ڵ������������½��з��Ѳ������µ������ӽڵ�
		node* NewRchild = new node();
		node* virtualPtr[max + 2];					//�����Ѿ����ˣ����Կ϶�Ϊ4���ӽ��
		for(int i = 0;i<max+1;i++)
		{
			virtualPtr[i] = temp->ptr[i];
		}
		int i = InsertVal(x, temp);
		for(int j = max+1;j>i+1;j--)
		{
			virtualPtr[j] = virtualPtr[j - 1];
		}
		virtualPtr[i] = LLeaf;			//�ݴ�����
		virtualPtr[i + 1] = RLeaf;
		NewLchild->IsLeaf = NewRchild->IsLeaf = false;
		//�����·�������ҽ������
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
		if(temp == root)				//�������������ͬ����Ҫ��Ԥ����һֱ�ݹ鵽���ڵ�
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
		else			//������ȥ�Ľ�㻹�Ǵﵽ�����޾ͼ�����һ��
		{
			InsertInternal(temp->key[NewLchild->size],temp->parent,NewLchild,NewRchild);
		}
	}
}

bool node::Search(int x)
{
	int i = 0;
	while (i < size && x>key[i])		//����
		i++;
	if(key[i] == x)
	{
		cout << "�������";
		return true;
	}
	if(IsLeaf == true)
	{
		cout << "����ʧ��";
		return false;
	}
	return ptr[i]->Search(x);
}

bool BTrees::search(int x)
{
	return (root == nullptr) ? false : root->Search(x);
}


//���������
void BTrees::Print()		//����ʵ��
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
