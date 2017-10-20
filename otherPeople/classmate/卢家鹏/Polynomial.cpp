//
// Created by niracler on 17-10-11.
//

#include<stdio.h>
#include<stdlib.h>


typedef struct term
{
	float coef;            //系数
	int expn;              //指数
	struct term *next;
}term, *LinkList;//term为一个新类型（是一个结构体），LinkList为指向这样的结构体的指针

typedef LinkList polynomial;

int cmp(LinkList qa, LinkList qb)  //比较项的指数大小
{
	if(qa->expn > qb->expn)
		return 1;
	else if(qa->expn == qb->expn)
		return 0;
	else
		return -1;
}

//若有序链表L中存在与项t的指数相等的元素，则指针q指向L中第一个指数为t->expn的节点的位置，
//否则q指向第一个指数满足与t->expn相比>0的节点的前驱位置
bool locateElem(LinkList L, LinkList t, LinkList &q){
	LinkList p1 = L->next;
	LinkList p2 = L;//p2总指向p1的前驱
	while(p1)
	{
		if(t->expn > p1->expn)
		{
			p1 = p1->next;
			p2 = p2->next;
		}
		else if(t->expn == p1->expn)
		{
			q = p1;
			return true;
		}
		else
		{//p1->expn > t->expn,因为L是有序表，所以如果程序走到了这一步，说明没找到与项t的指数相等的节点元素
			//则返回q的前驱结点
			q = p2;
			return false;
		}
	}
	if(!p1)
	{//t->expn比当前列表所有元素的指数都大，则上面的while循环会因为p2到达了尾节点，p1=NULL而跳出
		q = p2;
		return false;
	}
}
//输入m项的系数和指数，建立表示一元多项式的带有头节点的有序链表P
//利用尾插法
void createPolyn(polynomial &P, int m)
{
	//先建立一个带有头节点的空链表，即初始化
	P = (polynomial)malloc(sizeof(term));
	P->next = NULL;
	LinkList r = P;//r指针总是指向当前线性表的最后一个元素，即尾元素

	printf("输入系数,指数,如项2x^5则输入 2,5 :\n");//不必按升幂输入
	for(int i = 0; i < m; i++)
	{//依次输入m个非零项
		LinkList t = (LinkList)malloc(sizeof(term));
		t->next = NULL;
		LinkList q;
		scanf("%f,%d",&t->coef,&t->expn);
		if(!locateElem(P, t, q))
		{//当前链表中不存在该指数项，则插入，此时q为链表中第一个指数>t->expn的节点的前驱结点
			t->next = q->next;
			q->next = t;
		}
		else
		{//当前列表中已经存在有节点元素的指数与本次输入的项的指数相同，所以本次输入无效，应重新输入
			i--;
		}
	}
}
//打印多项式链表
void printPolynomial(polynomial P)
{
	LinkList q = P->next;
	printf("打印多项式的线性表：[");
	while(q)
	{
		printf("(%.1f,%d)  ",q->coef, q->expn);
		q = q->next;
	}
	printf("]\n\n");
}
//多项式加法：Pa=Pa+Pb,利用2个多项式的节点构成“和多项式”
void addPolyn(polynomial &Pa, polynomial &Pb)
{
	LinkList qa = Pa->next;
	LinkList qb = Pb->next;
	LinkList qc = Pa;//pc总是指向"和多项式链表"的最后一个节点

	float sumOfCoef;
	while(qa&&qb)
	{
		switch(cmp(qa, qb))
		{
			case 1:
				qc->next = qb;
				qc = qb;
				qb = qb->next;
				break;
			case 0://当前比较的两项的指数相同
				sumOfCoef = qa->coef + qb->coef;
				if(sumOfCoef != 0.0)
				{//系数之和不为0,则修改qa所指节点的系数，同时释放qb所指节点
					LinkList s = qb;//s即将被free掉
					qa->coef = sumOfCoef;

					qc->next = qa;
					qc = qa;
					qa = qa->next;
					qb = qb->next;

					free(s);
				}
				else
				{//系数之和为0，则从多项式链表A中删除qa所指节点，并free掉qa、qb所指节点
					LinkList s1 = qa;
					LinkList s2 = qb;

					qc->next = qa ->next;
					//qc的位置不变,qa、qb向后移动
					qa = qa->next;
					qb = qb->next;

					free(s1);
					free(s2);

				}
				break;
			case -1:
				qc->next = qa;
				qc = qa;
				qa = qa->next;
				break;
		}
	}

	qc->next = qa?qa:qb;//插入剩余段
	free(Pb);//释放Pb的头节点
}



int maintdn0()
{

	polynomial Pa;
	createPolyn(Pa, 4);//初始化并创建多项式链表Pa
	printPolynomial(Pa);

	polynomial Pb;
	createPolyn(Pb, 3);//初始化并创建多项式链表Pa
	printPolynomial(Pb);

	printf("执行多项式相加以后\n");
	addPolyn(Pa, Pb);
	printPolynomial(Pa);

	return 0;
}