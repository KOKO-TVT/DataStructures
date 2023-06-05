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

void BTrees::Split(int, node* temp1, node* temp2)
{


}

