#include <iostream>
#include<stack>
using namespace std;

void Reverse(char *c,int n)
{
	stack<char> S;
	for(int i = 0;i<n-1;i++)
	{
		S.push(c[i]);
	}

	for(int i = 0;i<n+1;i++)
	{
		c[i] = S.top();		//��д
		S.pop();
	}
}


int main()
{
	char c[51];
	cout << "�����ַ���";
	gets_s(c);		//����ַ�������
	Reverse(c, strlen(c));
	cout << c;
}