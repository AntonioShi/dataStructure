//
// Created by niracler on 17-9-17.
//

/*
 * 编写一个在单链表中数据域值为a的结点之后，　插入一个新结点的算法，　
 * 如果链表中没有数据域值为a的结点，则把新结点插入到表尾
 * */

#include "MyList.h"
#include <malloc.h>

void MyAdd(SLNode * head, DataType a , DataType newData);//在单链表中数据域值为a的结点之后，　插入一个新结点

int main0918(void)
{
    int i;                //控制循环
    SLNode * head = NULL;         //定义头指针
    ListInitiate(&head);   //初始化链表

    for (i = 0; i < 10; ++i)
    {
        MyAdd(head, 1, i);
    }

    ListPrint(head);

    return 0;
}

//在单链表中数据域值为a的结点之后，　插入一个新结点
void MyAdd(SLNode * head, DataType a , DataType newData)
{
    SLNode * p = head;
    SLNode * q = NULL;

    //为了找到要插入的地方,我的天，这里已经是ｎｕｌｌ
    for (; p->next != NULL && p->data == a ; p = p->next);

    //挂上newData
    q = p;
    p = p->next;
    q->next = (SLNode *)malloc(sizeof(SLNode));
    q->next->data = newData;
    q->next->next = p;
}

