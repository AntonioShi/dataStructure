//
// Created by niracler on 17-10-13.
//

#include <iostream>

using namespace std;

long long ansOfFib(long long n);//费波拉契数列

int main201710132121(void)
{
	for (int i = 1; i < 10; ++i)
	{
		cout << ansOfFib(i) << endl;
	}

	return 0;
}

//费波拉契数列
long long ansOfFib(long long n)
{
	if (n == 1 || n == 2)
	{
		return 1;
	}
	else
	{
		return ansOfFib(n - 1) + ansOfFib(n - 2);
	}
}
