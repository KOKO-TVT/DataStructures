#pragma onc
#include <iostream>
using namespace std;
#define max 2

class node
{
	bool IsLeaf;
	int* key;					//�ؼ���
	node** ptr;					//���
	node	*parent;	
	int size;					//��㵱ǰ��С
	friend class BTrees;		//������Ԫ	��Ȼbtree�еĺ����޷����ʱ���
public:
	node():key(new int[max+1]),parent(nullptr),ptr(new node*[max+1]) {}
};

class BTrees
{
	node* root = nullptr;
	void InsertInternal(int, node*, node*, node*);			//�ڵ����
	void Split(int, node*, node*);					//���ѽڵ�
	int InsertVal(int, node*);						//�����㣬���Դ�С���ƣ�Ѱ�ҽڵ�Ĳ���λ��
public:
	void Insert(int x);								//Ѱ�ҹؼ���Ӧ�ò����Ҷ�ӽ��λ��
	void Print();									//��ӡ���
};
