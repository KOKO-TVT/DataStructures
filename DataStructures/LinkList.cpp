//链表
#include <iostream>
using namespace std;
struct node
{
	int data;
	node* next;
};
node* head;	//头节点初始化

void insert(int x)	//节点插入
{
	node* temp = new node();
	temp->data = x;
		temp->next = head;
		head = temp;
		
	}

void print()
{
	
}

int main()
{
	head = nullptr;
	cout << "你想要多少个数据?\n";
	int n;
	cin >> n;
	for(int i:n)
	{
		cout << "请输入你想要填入的信息\n";
		int x;
		cin >> x;
		insert(x);
		print();

	}
}