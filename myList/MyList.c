//
// Created by niracler on 17-9-17.
//

#include "MyList.h"

#include <stdio.h>
#include <malloc.h>

int main091710(void)
{
    SLNode * head;         //定义头指针
    ListInitiate(&head);   //初始化链表
    printf("%d", ListInsert(head, 1, 12));

    return 0;
}

//单链表的初始化,这里要改变头指针的指向，所以要用二重指针
void ListInitiate(SLNode **head)
{
    (*head) = (SLNode *)malloc(sizeof(SLNode));//申请头结点
    (*head)->next = NULL;                    //置结束标记
}

//链表结点插入函数
//在带有头结点的单链表head的第i个结点前插入一个存放数据元素的结点
//成功返回一,失败返回零
int ListInsert(SLNode * head , int i , DataType x)
{
    int j;
    SLNode * p = head->next;//正在处理的结点
    SLNode * q = head;      //上一个

    //遍历所有结点找出i
    for (j = 0; j < i-1 && p != NULL; ++j)
    {
        q = p;
        p = p->next;
    }

    //找不到就失败
    if (i-1 != j)return 0;

    //找到就工作
    q->next = (SLNode *)malloc(sizeof(SLNode));
    q->data = x;
    q->next->next = p;

    return 1;
}

//在链表头插入一个结点
void ListPushHead(SLNode * head, DataType data)
{
    SLNode * pNew = (SLNode *)malloc(sizeof(SLNode));

    pNew->data = data;
    pNew->next = head->next;
    head->next = pNew;
}

//输出函数
void ListPrint(SLNode * head)
{
    SLNode * p = head->next;

    for ( ; p != NULL ; p = p->next)
    {
        printf("%d\n", p->data);
    }
}