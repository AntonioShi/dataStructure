//
// Created by niracler on 17-10-13.
//

#include <iostream>

using namespace std;

void output(int array[], int n);

int main201710132130(void)
{
	int array[] = {1,2,3,4,5,5,6,7,8,9,0,2,3,4,6,3,5,6,6,7};

	output(array, 20);

	return 0;
}

void output(int array[], int n)
{
	if(n == 1)
	{
		cout << array[0];
	}
	else
	{
		output(array, n-1);
		cout << array[n-1];
	}
}