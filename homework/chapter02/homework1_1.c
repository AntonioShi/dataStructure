//
// Created by niracler on 17-9-17.
//

/*
 * 编写一个在单链表中数据域值为a的结点之后，　插入一个新结点的算法，　
 * 如果链表中没有数据域值为a的结点，则把新结点插入到表尾
 * */

#include "../../myList/MyList.h"
#include <malloc.h>

void MyAdd(SLNode *head, DataType a, DataType newData);//在单链表中数据域值为a的结点之后，　插入一个新结点

int main201710202120(void)
{
    int i;                //控制循环
    SLNode *head = NULL;         //定义头指针
    ListInitiate(&head);   //初始化链表

    for (i = 0; i < 10; ++i)
    {
        MyAdd(head, 5, i);
    }

    ListPrint(head);

    return 0;
}

//在单链表中数据域值为a的结点之后，　插入一个新结点
void MyAdd(SLNode *head, DataType a, DataType newData)
{
    SLNode *p = head;
    SLNode *q = NULL;

    //为了找到要插入的地方,修改前
    //for (; p->next != NULL && p->data == a ; p = p->next);

    //修改后,看来，判断无法避免，
    for (; p != NULL && p->data != a; q = p,p = p->next);

    //挂上newData
    if (p != NULL)//找到
    {
        q = p->next;//记住下一个
        p->next = (SLNode *) malloc(sizeof(SLNode));//申请新空间
        p->next->data = newData;//分配值
        p->next->next = q;//
    }
    else//找不到
    {
        q->next = (SLNode *) malloc(sizeof(SLNode));
        q->next->data = newData;
        q->next->next = p;
    }
}

