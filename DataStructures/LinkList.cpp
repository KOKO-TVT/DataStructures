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
void print(node* head)
{
	cout << "��������������Ϊ��\n";
	while (head!= nullptr)
	{
		cout << head->data<<"\t";
		head = head->next;
	}
	cout << "\n";
}

int main()
{
	head = nullptr;
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

	//������λ�ò���ú������в���
	insert1(2, 1);
	insert1(3, 2);
	insert1(4, 1);
	insert1(5, 2);
	insert1(55, 6);
	print(head);

}