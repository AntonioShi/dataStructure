//
// Created by niracler on 17-10-11.
//

#include<stdio.h>
#include<stdlib.h>

//二项式的结构体
typedef struct PolyNode
{
	float coef;   //系数
	int expn;     //指数
	struct PolyNode *next;
} PolyNode, *polynomial;

//函数功能:构造二项式,该二项式没有头结点
polynomial CreatPolyn()
{
	int n = 0;
	polynomial head, p, q;
	p = q = (polynomial) malloc(sizeof(struct PolyNode));//分配首结点
	scanf("%f %d", &p->coef, &p->expn);
	head = NULL;

	//循环接收二项式
	while (p->coef != 0)
	{
		n = n + 1;
		if (n == 1)
		{
			head = p;
		}
		else
		{
			q->next = p;
			q = p;
			p = (polynomial) malloc(sizeof(struct PolyNode));
			scanf("%f %d", &p->coef, &p->expn);
		}
	}
	q->next = NULL;
	return (head);
}

//函数功能:对二项式进行排序
void TopPolyn(polynomial L)   //排序
{
	polynomial a, b;
	float temp_co;
	int temp_ex;
	a = L;
	for (a; a != NULL; a = a->next)
	{
		b = L;
		for (b; b->next != NULL; b = b->next)
		{
			if (b->expn > b->next->expn)
			{
				temp_co = b->coef;
				temp_ex = b->expn;
				b->coef = b->next->coef;
				b->expn = b->next->expn;
				b->next->coef = temp_co;
				b->next->expn = temp_ex;
			}
		}
	}
	return;
}

//函数功能:输出二项式
void PrintPolyn(polynomial head)
{
	polynomial p;
	printf("该多项式按升序输出为:");
	p = head;
	if (head != NULL)
	{
		do
		{
			printf("%.2fx^%d ", p->coef, p->expn);
			p = p->next;
		} while (p != NULL);
	}
}

int main101118(void)
{
	polynomial A, B, Ans;
	printf("请输入多项式A的系数和指数，输入格式为“coefficient，expn”，中间以逗号隔开\n");
	A = CreatPolyn();
	TopPolyn(A);
	PrintPolyn(A);
	printf("\n\n请输入多项式B的系数和指数，输入格式为“coefficient，expn”，中间以逗号隔开\n");
	B = CreatPolyn();
	TopPolyn(B);
	PrintPolyn(B);

	return 0;
}