//链表
#include <iostream>
using namespace std;
struct node
{
	int data;
	node* next;
};
node* head;	//头节点初始化

void insert(node** PointerHead,int x)	//在头部节点插入
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
void insert1(int data, int pos)		//在任意位置插入节点
{
	node* temp1 = new node();		//插入位置为1情况
	temp1->data = data;
	temp1->next = nullptr;
	if(pos==1)						//链表为空也适用
	{
		temp1->next = head;
		head = temp1;
		return;
	}

	//当插入的位置大于1时
	node* temp2 = head;			//创建得该节点为一个遍历至特定位置得媒介
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
	cout << "你所期望得链表为：\n";
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
															//对从头部开始插入函数得测试
															/*	cout << "你想要多少个数据?\n";
																int n,x;
																cin >> n;
																for(int i=0;i<n;i++)
																{
																	cout << "请输入你想要填入的信息\n";
																	cin >> x;
																	insert(&head,x);
																	print(head);

																}
															*/

	//对任意位置插入得函数进行测试
	insert1(2, 1);
	insert1(3, 2);
	insert1(4, 1);
	insert1(5, 2);
	insert1(55, 6);
	print(head);

}