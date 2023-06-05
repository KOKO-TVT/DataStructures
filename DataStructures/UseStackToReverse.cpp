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
		c[i] = S.top();		//重写
		S.pop();
	}
}


int main()
{
	char c[51];
	cout << "输入字符串";
	gets_s(c);		//获得字符串方法
	Reverse(c, strlen(c));
	cout << c;
}