//
// Created by niracler on 17-9-27.
//
//
//一矩形阵列由数字0到9组成，数字1到9代表细胞，细胞的定义为沿细胞数字上下左右还是相同数字则为同一细胞，如:阵列
//scholat.com
// 有5个细胞，编写程序求给定矩形阵列的细胞个数

#include <iostream>

using namespace std;

//棋盘格
struct Item
{
	int num; //细胞号数
	bool flag;//是否走过,走过就插false旗
};

int main(void)
{
	Item member[11][11];

	for (int i = 1; i <= 10; ++i)
	{
		for (int j = 1; j <= 10; ++j)
		{
			cin >> member[i][j].num;
		}
	}

	for (int i = 1; i <= 10; ++i)
	{
		for (int j = 1; j <= 10; ++j)
		{
			cout << member[i][j].num << " ";
		}

		cout << endl;
	}

	cout << "bfs什么的, 去你的!!!!!!" << endl;

	return 0;
}