//
// Created by niracler on 17-9-27.
//
//
//一矩形阵列由数字0到9组成，数字1到9代表细胞，细胞的定义为沿细胞数字上下左右还是相同数字则为同一细胞，如:阵列
//scholat.com
// 有5个细胞，编写程序求给定矩形阵列的细胞个数

#include <iostream>

using namespace std;

//矩阵类
class Matrix
{
private:
	int **Item;
	int m, n;
public:
	Matrix(int m, int n);
	friend istream &operator>>(istream &in, Matrix &mat);
	friend ostream &operator<<(ostream &out, Matrix &mat);
};

int main101320(void)
{
	Matrix mat(10, 10);

	cout << "bfs什么的, 去你的!!!!!!" << endl;

	return 0;
}

Matrix::Matrix(int m, int n)
{
	Item = new int *[m];

	for (int i = 0; i < m; ++i)
	{
		Item[m] = new int[n];
	}
}

//输入函数重载
istream &operator>>(istream &in, Matrix &mat)
{


	return in;
}

//输出函数重载
ostream &operator<<(ostream &out, Matrix &mat)
{


	return out;
}