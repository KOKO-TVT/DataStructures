//˫������
#include <iostream>
using namespace std;

struct  node
{
	int data;
	node* next;
	node* prev;
};

node* head;

node* GetNewNode(int x)
{
	node* temp = new node();
	temp->data = x;
	temp->next = nullptr;
	temp->prev = nullptr;
	return temp;
}

void InsertAtHead(int x)
{
	node* temp = GetNewNode(x);
	if(head == nullptr)
	{
		head = temp;
		return;
	}

	head->prev = temp;
	temp->next = head;
	head = temp;
	
}

void InsertAtTail(int x)		//β�����
{
	node* temp = GetNewNode(x);
	if (head == nullptr)
	{
		head = temp;
		return;
	}
	node* temp1 = head;
	while(temp1->next != nullptr)
	{
		temp1 = temp1->next;
	}
	temp1->next = temp;
	temp->prev = temp1;

}

void Print()
{
	node* temp = head;
	cout << "��ֵΪ��";
	while(temp != nullptr)
	{
		cout << temp->data;
		temp = temp->next;
	}
	cout << "\n";
}

void ReversePrint()
{
	node* temp = head;
	if (temp == nullptr)
		return;
	while (temp->next != nullptr)		//��ֹ�����whileѭ���жϵ�һ���Ϳ�ס������ֻ��鵽���һ��ֹͣ
		temp = temp->next;
	cout << "���������ı�Ϊ��";
	while (temp != nullptr)
	{
		cout << temp->data;
		temp = temp->prev;
	}
	cout << "\n";

}

int main()
{
	head = nullptr;
	InsertAtHead(2); Print(); ReversePrint();
	InsertAtHead(5); Print(); ReversePrint();
	InsertAtHead(3); Print(); ReversePrint();
	InsertAtHead(4); Print(); ReversePrint();
	InsertAtTail(6); Print(); ReversePrint();

}