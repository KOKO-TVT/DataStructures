//数组栈 Last in first out
#include <iostream>
using namespace std;

#define Max_Size 101
int A[Max_Size];
int top = -1;

void Push(int x)
{
	if(top == Max_Size-1)	//内存溢出处理
	{
		cout << "程序错误：栈区已经溢出";
		return;
	}
	A[++top] = x;
}

//数据弹出
void Pop()
{
	if(top == -1)
	{
		cout<<"程序错误：栈区为空";
		return;
	}
	top--;
}

void Print()
{
	cout << "栈为：";
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