//
// Created by niracler on 17-9-25.
//


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "MyStack.h"

int InfixToSuffix(char exp[], int n);//中缀表达式转化为后缀表达式的函数

int main(void)
{
    //请给我一个表达式
    char expression[500];

    //原来这个不能接收空格，，，
    scanf("%s", expression);

    //解决问题
    if (!InfixToSuffix(expression, strlen(expression)))
    {
        printf("错误，您的表达式有问题！！！");
    }

    //输出
    //printf("%s", expression);

    return 0;
}

//中缀表达式转化为后缀表达式的函数
//参数：表达式，表达式的长度
//返回值：1.成功　0.失败
int InfixToSuffix(char exp[], int n)
{
    int i, j = 0, k = 0, num[200];           //循环控制
    char str[20];
    char getch;
    SeqStack myStack;//先来一个栈吧

    StacKInitiate(&myStack);

    //遍历表达式
    for (i = 0; i < n; ++i)
    {
        //各种数字记录
        if (exp[i] >= '0' && exp[i] <= '9')
        {
            str[j] = exp[i];
            j++;

            //下一个不是，则转化为字符串
            if (exp[i + 1] < '0' || exp[i + 1] > '9')
            {
                str[j] = '\0';
                j = 0;
                num[k] = atoi(str);
                printf("%d\n", num[k]);
                k++;
            }
        }
            //各种符号进栈
        else
        {
            StackPush(&myStack, exp[i]);
        }
    }

    while (!StackEmpty(&myStack))
    {
        StackPop(&myStack, &getch);
        printf("%c ", getch);
    }

    return 1;
}
