//
// Created by niracler on 17-9-20.
//

#ifndef DATASTRUCTURE_MYSTACK_H
#define DATASTRUCTURE_MYSTACK_H

#define MaxStackSize 100
typedef char DataType;//栈中元素数据

//栈的结构体
typedef struct
{
    DataType stack[MaxStackSize];
    int top;
}SeqStack;

void StacKInitiate(SeqStack * pStack);//初始化

int StackEmpty(SeqStack * pStack);//判断是否为空

void StackPush(SeqStack * pStack, DataType member);//入栈

int StackPop(SeqStack * pStack, DataType * getMember);//出栈

int StackTop(SeqStack * pStack, DataType * getMember);//取栈顶函数

#endif //DATASTRUCTURE_MYSTACK_H
