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

//在链表的末尾添加节点
void insert2(int data)
{
	if(!head)		//链表为空时
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

//删除链表的任意位置节点
void Delete(int n)
{
	node* temp1 = head;
	//删除位置为1时
	if (n == 1)
	{
		head = temp1->next;
		delete temp1;
		return;
	}

	//其他情况
	for(int i=0;i<n-2;i++)
	{
		temp1 = temp1->next;	//删除特定节点节点的遍历媒介，指定节点的上一节点
	}

	node* temp2 = temp1->next;		//目标节点
	temp1->next = temp2->next;
	delete temp2;
	
}

void Reverse()		//反转链表	迭代方法实现
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
	cout << "链表为：\n";
	while (head!= nullptr)
	{
		cout << head->data<<"\t";
		head = head->next;
	}
	cout << "\n";
}

void ReversePrint(node* P)		//使用递归进行反向链表遍历
{ 
	if (P == nullptr)
		return;
	ReversePrint(P->next);
	cout << P->data << "\t";
	
}

int main()
{
	head = nullptr;	//初始化链表
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


	/*//对任意位置插入得函数进行测试
	insert1(2, 1);
	insert1(3, 2);
	insert1(4, 1);
	insert1(5, 2);
	insert1(55, 6);
	print(head);
	*/


	//对尾后位置插入节点和任意位置删除节点进行测试
	insert2(2);
	insert2(4);
	insert2(6);
	insert2(8);
	cout << "根据你所输入的信息所得的反转链表为：\n";
	Reserve1(head);
	print(head);
	
	/*
	 *int pos;
	cout << "请输入你所想删除的位置节点\n";
	cin >> pos;
	Delete(pos);
	print(head);
	*/

	/*
	cout << "下面是将链表反转后的结果\n";
	Reverse();
	print(head);
	*/

}