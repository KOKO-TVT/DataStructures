//����ջ Last in first out
#include <iostream>
using namespace std;

#define Max_Size 101
int A[Max_Size];
int top = -1;

void Push(int x)
{
	if(top == Max_Size-1)	//�ڴ��������
	{
		cout << "�������ջ���Ѿ����";
		return;
	}
	A[++top] = x;
}

//���ݵ���
void Pop()
{
	if(top == -1)
	{
		cout<<"�������ջ��Ϊ��";
		return;
	}
	top--;
}

void Print()
{
	cout << "ջΪ��";
	for (int i = 0; i <= top; i++)
		cout << A[i];
	cout << "\n";
}

int Top()
{
	return A[top];
}
int main()
{
	Push(2); Print();
	Push(3); Print();
	Push(4); Print();
	Push(5); Print();
	Pop(); Print();
	Push(6); Print();
}