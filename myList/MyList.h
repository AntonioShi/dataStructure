//
// Created by niracler on 17-9-17.
//

#ifndef HUD_ACM_MYLIST_H
#define HUD_ACM_MYLIST_H

typedef int DataType;//数据域的数据类型

//链表结点结构体定义
typedef struct Node
{
    DataType data;
    struct Node * next;
}SLNode;

void ListPushHead(SLNode * head, DataType data);      //在链表头插入一个结点
void ListInitiate(SLNode ** head);                    //单链表初始化函数
int ListInsert(SLNode * head, int i , DataType x);    //链表结点插入函数
void ListPrint(SLNode * head);                         //我的输出函数

#endif //HUD_ACM_MYLIST_H
