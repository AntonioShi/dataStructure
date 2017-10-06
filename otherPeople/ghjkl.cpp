//
// Created by niracler on 17-9-29.
//

#include <iostream>
using namespace std;

typedef double DateType1;
typedef int DateType2;
typedef struct Node
{
    DateType1 t;
    DateType2 n;
    struct Node *next;
}SLNode;

//初始化链表
void ListInitiate(SLNode **head)
{
    *head=(SLNode*)malloc(sizeof(SLNode));
    (*head)->next= NULL;
}

//添加数据
SLNode* ListInsert(SLNode *head,DateType1 a,DateType2 b)
{
    int flag=0;
    SLNode *p,*q;
    p=head;
    p=p->next;
    if(a!=0)
    {
        while(p!=NULL)
        {
            if(p->n==b)
            {
                p->t=p->t+a;
                flag=1;
                break;
            }
            p=p->next;
        }
        if(!flag)
        {
            q=(SLNode *)malloc(sizeof(SLNode));
            q->t=a;
            q->n=b;
            q->next=NULL;
            p=q;

        }
    }
    return head;
}
//显示链表信息
void ListShow(SLNode *head)
{
    SLNode *p;
    p=head;
    p=p->next;
    for(;p!=NULL;p=p->next)
    {
        cout<<p->t<<"X"<<p->n;
    }
    cout<<endl;
}
int main34567()
{
    DateType1 a;
    DateType2 b;
    SLNode *head;
    ListInitiate(&head);
    for(int i=0;i<3;i++)
    {
        cout<<"输入系数和指数：";
        cin>>a>>b;
        ListInsert(head,a,b);
    }
    ListShow(head);
    system("pause");
    return 0;
}