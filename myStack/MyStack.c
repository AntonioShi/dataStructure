//
// Created by niracler on 17-9-20.
//

#include <stdio.h>
#include "MyStack.h"

//测试用的主函数
int main0920(void)
{
    int i, getMember;
    SeqStack myStack;
    StacKInitiate(&myStack);
    printf("%d\n", StackEmpty(&myStack));

    for (i = 0; i < 10; ++i)
    {
        StackPush(&myStack, i);
    }

    printf("%d\n", StackEmpty(&myStack));

    for (i = 0; i < 100; ++i)
    {
        if (StackPop(&myStack, &getMember))
        {
            printf("%d ", getMember);
        }

        if (StackTop(&myStack, &getMember))
        {
            printf("%d\n", getMember);
        }
    }

    return 0;
}

//初始化函数
void StacKInitiate(SeqStack * pStack)
{
    //初始化顶部位置
    pStack->top = 0;
}

//判断是否为空函数
//空返回1，否则返回0
int StackEmpty(SeqStack * pStack)
{
    if(pStack->top)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

//入栈函数
void StackPush(SeqStack * pStack, DataType member)
{
    pStack->stack[pStack->top] = member;
    pStack->top++;
}

//出栈函数
//成功返回1,失败返回0
int StackPop(SeqStack * pStack, DataType * getMember)
{
    if (!StackEmpty(pStack))
    {
        pStack->top--;
        *getMember = pStack->stack[pStack->top];
        return 1;
    }
    else
    {
        return 0;
    }

}

//取栈顶元素函数
int StackTop(SeqStack * pStack, DataType * getMember)
{
    if (!StackEmpty(pStack))
    {
        *getMember = pStack->stack[pStack->top-1];
        return 1;
    }
    else
    {
        return 0;
    }
}