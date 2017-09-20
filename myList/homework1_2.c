//
// Created by niracler on 17-9-19.
//

/*
 * 题目：设AB是两个按元素值递增的有序的单链表，　
 * 写一个算法将Ａ和Ｂ归并为按元素值递减的有序单链表Ｃ，　
 * 试分析算法的时间复杂度
 * */

#include <malloc.h>
#include "MyList.h"

void MyTwoWayMergeAlgorithm(SLNode * head1, SLNode * head2, SLNode * head3);//关于我的二路归并算法的函数

int main0919(void)
{
    int i;
    SLNode * head1, * head2, * head3;

    //初始化
    ListInitiate(&head1);
    ListInitiate(&head2);
    ListInitiate(&head3);

    //为1链表赋值
    for (i = 100; i > 80; i -= 2)
    {
        ListPushHead(head1, i);
    }

    //为2链表赋值
    for (i = 109; i > 70; i -= 2)
    {
        ListPushHead(head2, i);
    }

    ListPrint(head1);
    ListPrint(head2);

    MyTwoWayMergeAlgorithm(head1, head2, head3);

    ListPrint(head3);

    return 0;
}

//关于我的二路归并算法的函数
void MyTwoWayMergeAlgorithm(SLNode * head1, SLNode * head2, SLNode * head3)
{
    SLNode * p1 = head1;//1链的处理点
    SLNode * p2 = head2;//2链的处理点
    SLNode * p = NULL;

    for (; p1->next != NULL && p2->next != NULL ; )
    {
        p1 = p1->next, p2 = p2->next;

        if (p1->data < p2->data)
        {
            ListPushHead(head3, p1->data);
        }
        else
        {
            ListPushHead(head3, p2->data);
        }
    }

    if(p1->next != NULL)
    {
        p = p1;
    }
    else
    {
        p = p2;
    }

    while (p->next != NULL)
    {
        p = p->next;
        ListPushHead(head3, p->data);
    }
}