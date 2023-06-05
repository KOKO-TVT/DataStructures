#include <iostream>
using namespace std;

struct Stack
{
	int data;

	struct Stack* link;		//next node
};

Stack* top = nullptr;		//stack top node

void push(int data)
{
	Stack* temp = new Stack({data,nullptr});
	temp->link = top;
	top = temp;
}

void pop ()
{
	if(top == nullptr)
	{
		cout << "Õ»Îª¿Õ";
		return;
	}
	Stack* temp = top;
	top = top->link;
	delete temp;
}

void Reverse(char c,int n)
{
	
}

int main()
{


}