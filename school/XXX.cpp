//
// Created by niracler on 17-9-4.
//

/*
 * 这个是关于矩阵转置的题目
 * */

#include <iostream>

using namespace std;

int main9(void)
{
    int n;

    cin >> n;

    int ** b = new int * [n];

    for (int i = 0; i < n; ++i)
    {
        int * a = new int[n];
        b[i] = a;
    }

    for (int j = 0; j < n; ++j)
    {
        for (int i = 0; i < n; ++i)
        {
            cin >> b[j][i];
        }
    }

    for (int j = 0; j < n; j++)
    {
        if (j != 0) cout << endl;
        for (int i = 0; i < n; i++)
        {
            if(i != 0) cout << " ";
            cout <<  b[i][j];
        }

    }

    return 0;
}