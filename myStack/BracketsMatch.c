//
// Created by niracler on 17-9-23.
//

//这是一个关于括号匹配的问题

#include <stdio.h>
#include <string.h>
#include "MyStack.h"

int ExpIsCorrect(char exp[], int n);//检验括号匹配的函数

int main092420(void)
{
    int n[4], YesOrNo[4];
    char a[] = "(())asdf{[)[[[][][090()09((]}"; //左右括号配对次序不正确
    char b[] = "(()))asdf{[]}"; //右边多于左边
    char c[] = "(()()asdf{[]}"; //左边多于右边
    char d[] = "(())asdf{[jckap[p[]]]}"; //左右匹配

    n[0] = (int) strlen(a);
    n[1] = (int) strlen(b);
    n[2] = (int) strlen(c);
    n[3] = (int) strlen(d);

    YesOrNo[0] = ExpIsCorrect(a, n[0]);
    YesOrNo[1] = ExpIsCorrect(b, n[1]);
    YesOrNo[2] = ExpIsCorrect(c, n[2]);
    YesOrNo[3] = ExpIsCorrect(d, n[3]);

    for (int i = 0; i < 4; ++i)
    {
        if (YesOrNo[i])
        {
            printf("匹配\n");
        }
        else
        {
            printf("不匹配\n");
        }
    }

    return 0;
}

//检验括号匹配的函数
//匹配返回1,不匹配返回0
int ExpIsCorrect(char exp[], int n)
{
    //定义操作用的顺序栈
    SeqStack myStack;
    StacKInitiate(&myStack);
    char GetCh;
    int i;

    //遍历所有元素
    for (i = 0; i < n; i++)
    {
        //碰到左括号，入栈
        if (exp[i] == '{' || exp[i] == '[' || exp[i] == '(')
        {
            StackPush(&myStack, exp[i]);
        }

            //碰到右括号，出栈
        else if (exp[i] == '}' || exp[i] == ']' || exp[i] == ')')
        {
            if (StackEmpty(&myStack)) return 0;//右边多于左边时
            StackPop(&myStack, &GetCh);

            if ((GetCh=='{'&&exp[i]=='}') || (GetCh=='['&&exp[i]==']') || (GetCh=='('&&exp[i]==')'))
            {
                continue;
            }
            else
            {
                return 0;
            }

        }
    }

    return StackEmpty(&myStack);
}
