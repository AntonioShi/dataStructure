//
// Created by niracler on 17-9-23.
//

#include <stdio.h>
#include <malloc.h>

typedef int DataType;
typedef struct Node
{
    DataType data;
    struct Node *next;
    struct Node *prior;
} DLNode;

void DLNodeInitiate(DLNode **head)
{
    *head = (DLNode *) malloc(sizeof(DLNode));
    (*head)->next = *head;
    (*head)->prior = *head;

}

int DLNodeInsert(DLNode *head, int i, DataType s)
{
    DLNode *p, *q;
    int j = 0;
    //p = head ;,error!!
    p = head->next;
    while (p != head && j < i)
    {
        p = p->next;
        j++;
    }

    if (j != i)
    {
        printf("参数错误4\n");
        return 0;
    }

    q = (DLNode *) malloc(sizeof(DLNode));
    q->data = s;

    //插入默认是插在目前元素的后面，课本上是在前面。
//    q->next = p->next ;
//    p->next->prior = q ;
//    p->next = q ;
//    q->prior = p ;

    //课本上的
    q->prior = p->prior;
    p->prior->next = q;


    q->next = p;
    p->prior = q;

    return 1;
}


/*
 * 1.一般除循环外，不要用ｉｊｋｌ
 * 2.定义指针时要同时赋初值，起码是NULL，决不允许有野指针
 * 3.
 * */
int DLNodeDelete(DLNode *head, int n, DataType *s)
{
    DLNode *p = head->next;//指向当前处理结点
    DLNode *q = head;      //指向当前处理指针的上一个结点

    int i;

    //遍历找要处理的结点
    for (i = 0; p != NULL && i < n; i++)
    {
        q = p;
        p = p->next;
    }

    //找不到的情况
    if (i != n)
    {
        printf("error!!!\n");
        return 0;
    }

    //找到的情况
    q->next = p->next;
    free(p);

    return 1;
}

int DLNodeLength(DLNode *head)
{
    DLNode *p = head;
    int size = 0;

    while (p->next != head)
    {//**
        p = p->next;
        size++;
    }

    return size;
}

void Destroy(DLNode **head)
{
    DLNode *p, *q;
    p = *head;
    int i, n = DLNodeLength(*head);
    //for (i = 0; i < n; ++i) {!!
    for (i = 0; i <= n; ++i)
    {
        q = p;
        p = p->next;
        free(q);
    }

    *head = NULL;

//    while(p != NULL){//!!
//        q = p ;
//        p = p->next ;
//        free(q) ;
//    }

}

int DLNodeGet(DLNode *head, int i, DataType *s)
{
    DLNode *p = head->next;
    int j = 0;

    while (p != head && j < i)
    {
        p = p->next;
        j++;
    }

    if (j != i)
    {
        printf("参数错误2\n");
        return 0;
    }

    *s = p->data;
    return 1;
}

int main()
{
    //定义并初始化双向链表
    DLNode *head;
    DLNodeInitiate(&head);

    //为链表赋值
    int i, s;
    for (i = 0; i < 10; ++i)
    {
        DLNodeInsert(head, i, (i + 1));
    }

    int n = DLNodeLength(head);
    printf("n = %4d\n", n);

    //输出链表
    for (i = 0; i < DLNodeLength(head); ++i)
    {
        DLNodeGet(head, i, &s);
        printf("%d ", s);
    }
    printf("\n");

    DLNodeDelete(head, 4, &s);
    n = DLNodeLength(head);
    printf("n = %4d\n", n);

    for (i = 0; i < DLNodeLength(head); ++i)
    {
        DLNodeGet(head, i, &s);
        printf("%d ", s);
    }
    printf("\n");

    return 0;
}