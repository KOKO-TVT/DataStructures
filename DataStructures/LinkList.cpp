//����
#include <iostream>
using namespace std;
struct node
{
	int data;
	node* next;
};
node* head;	//ͷ�ڵ��ʼ��

void insert(node** PointerHead,int x)	//��ͷ���ڵ����
{
	node* temp = new node();
	temp->data = x;
	temp->next = nullptr;
	if(*PointerHead != nullptr)
	{
		temp->next = *PointerHead;
	}
	head = temp;

}
void insert1(int data, int pos)		//������λ�ò���ڵ�
{
	node* temp1 = new node();		//����λ��Ϊ1���
	temp1->data = data;
	temp1->next = nullptr;
	if(pos==1)						//����Ϊ��Ҳ����
	{
		temp1->next = head;
		head = temp1;
		return;
	}

	//�������λ�ô���1ʱ
	node* temp2 = head;			//�����øýڵ�Ϊһ���������ض�λ�õ�ý��
	for(int i=0;i<pos-2;i++)
	{
		temp2 = temp2->next;
	}
	if(temp2=nullptr)
	temp1->next = temp2->next;
	temp2->next = temp1;
}

//�������ĩβ��ӽڵ�
void insert2(int data)
{
	if(!head)		//����Ϊ��ʱ
	{
		node* temp2 = new node();
		temp2->next = nullptr;
		temp2->data = data; 
		head = temp2;
		return;
	}
	node* temp = head;
	while (temp->next != nullptr)
	{
		temp = temp->next;
	}
	node* temp1 = new node();
	temp->next = temp1;
	temp1->data = data;
	
}

//ɾ�����������λ�ýڵ�
void Delete(int n)
{
	node* temp1 = head;
	//ɾ��λ��Ϊ1ʱ
	if (n == 1)
	{
		head = temp1->next;
		delete temp1;
		return;
	}

	//�������
	for(int i=0;i<n-2;i++)
	{
		temp1 = temp1->next;	//ɾ���ض��ڵ�ڵ�ı���ý�飬ָ���ڵ����һ�ڵ�
	}

	node* temp2 = temp1->next;		//Ŀ��ڵ�
	temp1->next = temp2->next;
	delete temp2;
	
}

void Reverse()		//��ת����	��������ʵ��
{
	node* current, *prev, *next;
	prev = nullptr;
	current = head;
	while (current != nullptr)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	head = prev;

}

void Reserve1(node* p)
{
	if(p->next==nullptr)
	{
		head = p;
		return;
	}
	Reserve1(p->next);
	node* q = p->next;
	q->next = p;			//p->next->next = p;
	p->next = nullptr;
}

void print(node* head)
{
	cout << "����Ϊ��\n";
	while (head!= nullptr)
	{
		cout << head->data<<"\t";
		head = head->next;
	}
	cout << "\n";
}

void ReversePrint(node* P)		//ʹ�õݹ���з����������
{ 
	if (P == nullptr)
		return;
	ReversePrint(P->next);
	cout << P->data << "\t";
	
}

int main()
{
	head = nullptr;	//��ʼ������
	//�Դ�ͷ����ʼ���뺯���ò���
	/*	cout << "����Ҫ���ٸ�����?\n";
	int n,x;
	cin >> n;
	for(int i=0;i<n;i++)
	{
		cout << "����������Ҫ�������Ϣ\n";
		cin >> x;
		insert(&head,x);
		print(head);
		
	}
	*/


	/*//������λ�ò���ú������в���
	insert1(2, 1);
	insert1(3, 2);
	insert1(4, 1);
	insert1(5, 2);
	insert1(55, 6);
	print(head);
	*/


	//��β��λ�ò���ڵ������λ��ɾ���ڵ���в���
	insert2(2);
	insert2(4);
	insert2(6);
	insert2(8);
	cout << "���������������Ϣ���õķ�ת����Ϊ��\n";
	Reserve1(head);
	print(head);
	
	/*
	 *int pos;
	cout << "������������ɾ����λ�ýڵ�\n";
	cin >> pos;
	Delete(pos);
	print(head);
	*/

	/*
	cout << "�����ǽ�����ת��Ľ��\n";
	Reverse();
	print(head);
	*/

}