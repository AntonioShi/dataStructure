//
// Created by niracler on 17-10-13.
//

//好吧, 这是我的递归的练习

#include <iostream>

using namespace std;

long long factorial(long long n);//n的阶乘
long long oneToN(long long n);//1+2+3.....+n
long long facOneToN(long long n);//1+2!+3!+4!+.....n!

int main201710132053(void)
{
	for (int i = 0; i < 10; ++i)
	{
		cout << factorial(i) << endl;
	}

	cout << endl;

	for (int i = 1; i < 10; ++i)
	{
		cout << oneToN(i) << endl;
	}

	cout << endl;

	for (int j = 1; j < 10; ++j)
	{
		cout << facOneToN(j) << endl;
	}

	return 0;
}

//用递归求阶乘的函数
long long factorial(long long n)
{
	//假如是1或0我可以搞定
	if (n == 1 || n == 0)
	{
		return 1;
	}
		//不行的话,推给n-1
	else
	{
		return factorial(n - 1) * n;
	}
}

//1+2+3.....+n
long long oneToN(long long n)
{
	if (n == 1)
	{
		return 1;
	}
	else
	{
		return oneToN(n - 1) + n;
	}
}

//1+2!+3!+4!+.....n!
long long facOneToN(long long n)
{
	if (n == 1)
	{
		return 1;
	}
	else
	{
		return facOneToN(n - 1) + factorial(n);
	}
}