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

void BTrees::Split(int, node* temp1, node* temp2)
{


}

