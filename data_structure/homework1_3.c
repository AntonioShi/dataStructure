//
// Created by niracler on 17-9-19.
//

/*
 * 题目：某企业有20000名员工，
 * 其计算薪水的公式为50n+k^3+2k^2+1000k+400，　
 * 其中ｎ为工作的月数[1, 36]，　
 * ｋ为员工等级[1,3]，n, k,均为整数，　
 * 试设计一种算法尽可能地缩短全部员工的工资计算时间　
 * */

#include <stdio.h>

int main091902(void)
{
    int i, j;
    int n, k;//工作月数，员工等级
    int ans[36][3];//穷举出所有可能。

    //计算所有可能
    for (i = 1; i <= 36; ++i)
    {
        for (j = 1; j <= 3; ++j)
        {
            ans[i-1][j-1] = 50*i + j*j*j + 2*j*j + 1000*j + 400;
        }
    }

    while (scanf("%d%d", &n, &k) != EOF)
    {
        printf("%d", ans[n-1][k-1]);
    }

    return  0;
}