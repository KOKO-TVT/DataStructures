//����
#include <iostream>
using namespace std;
struct node
{
	int data;
	node* next;
};
node* head;	//ͷ�ڵ��ʼ��

void insert(int x)	//�ڵ����
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
	cout << "����Ҫ���ٸ�����?\n";
	int n;
	cin >> n;
	for(int i:n)
	{
		cout << "����������Ҫ�������Ϣ\n";
		int x;
		cin >> x;
		insert(x);
		print();

	}
}