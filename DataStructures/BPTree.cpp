#include<iostream>
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
		LLeaf->parent = RLeaf->parent = root = NewRoot;
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
		for(int j = max+2;j>i+1;j--)
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
			
		}
	}
}

