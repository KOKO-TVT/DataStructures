//双向链表
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

void InsertAtTail(int x)		//尾后插入
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
	cout << "数值为：";
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
	while (temp->next != nullptr)		//防止下面的while循环判断第一步就卡住，所以只检查到最后一步停止
		temp = temp->next;
	cout << "逆向遍历后的表为：";
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