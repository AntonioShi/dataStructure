#include "stdio.h"
#include "malloc.h"
#include "stdlib.h"

typedef struct node
{
    struct node *next;
    double xNum;
    int zNum;
} Node;

void ListInitiate(Node **head)
{
    *head = (Node *) malloc(sizeof(Node));
    (*head)->next = NULL;
}

int ListLength(Node *head)
{
    Node *p = head;
    int size = 0;
    while (p->next != NULL)
    {
        p = p->next;
        size++;
    }
    return size;
}

int ListInsert(Node *head, int i, double x, int z)
{
    Node *p, *q;
    int j;
    p = head;
    j = -1;
    while (p->next != NULL && j < i - 1)
    {
        p = p->next;
        j++;
    }
    if (j != i - 1)
    {
        printf("插入的位置参数有误!");
        return 0;
    }

    q = (Node *) malloc(sizeof(Node));
    q->xNum = x;
    q->zNum = z;
    q->next = p->next;
    p->next = q;
    return 1;
}

int ListDelete(Node *head, int i, double *x, int *z)
{
    Node *p, *s;
    int j;
    p = head;
    j = -1;
    while (p->next != NULL && p->next->next != NULL && j < i - 1)
    {
        p = p->next;
        j++;
    }
    if (j != i - 1)
    {
        printf("插入元素位置参数有误!");
        return 0;
    }

    s = p->next;
    *x = s->xNum;
    *z = s->zNum;
    p->next = p->next->next;
    free(s);
    return 1;
}

int ListGet(Node *head, int i, double *x, int *z)
{
    Node *p;
    int j;
    p = head;
    j = -1;
    while (p->next != NULL && j < i)
    {
        p = p->next;
        j++;
    }
    if (j != i)
    {
        printf("取元素位置参数有误!");
        return 0;
    }

    *x = p->xNum;
    *z = p->zNum;
    return 1;
}

void Input(Node *head)
{
    double x;
    int z, n = 1;
    while (n)
    {
        scanf("%lf%d", &x, &z);
        if (z == 0)
            n = 0;
        else
        {
            ListInsert(head, ListLength(head), x, z);
        }
    }
}

void Destory(Node **head)
{
    Node *p, *p1;
    p = *head;
    while (p != NULL)
    {
        p1 = p;
        p = p->next;
        free(p1);
    }
    *head = NULL;
}

Node *sort(Node *head)
{
    Node *p = NULL, *q = NULL, *s = NULL ,*qL = NULL ;
    for (p = head; p->next != NULL; p = p->next)
    {
        qL = p;
        for (q = p->next; q != NULL;qL = q,q = q->next)
        {
            //找到相同指数时，
            if (p->zNum == q->zNum)
            {
                p->xNum += q->xNum;//step1:系数相加
                s = q;             //step2:s指向要删除的结点
                q = q->next;       //step3:q指向下一个结点
                qL->next = q;      //step4:s的上一个的next指向q
                free(s);           //step5:删除s
                if(!q)break;
            }

        }

        if(p->next == NULL)break;
    }

    return head;
}

int mainfangrong(void)
{
    int i, z;
    double x;
    Node *head1, *head2;
    ListInitiate(&head1);
    ListInitiate(&head2);
    Input(head1);
    sort(head1);
    printf("%d\n", ListLength(head1));
    for (i = 0; i < ListLength(head1); i++)
    {
        ListGet(head1, i, &x, &z);
        printf("%lf    %d\n", x, z);
    }
    //system("pause");
    return 0;
} 