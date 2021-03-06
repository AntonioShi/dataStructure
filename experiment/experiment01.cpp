//
// Created by niracler on 17-9-29.
//

/*
题目1：一元多项式的操作
        设有两个一元多项式：
p(x)=p0+p1x+p2x2+···+pnxn
        q(x)=q0+q1x+q2x2+···+qmxm
        :多项式项的系数为实数，指数为整数，设计实现一元多项式操作的程序：
        The coefficient is a real number and the index is an integer
① 多项式链表建立：以（系数，指数）方式输入项建立多项式，返回所建立的链表的头结点；
② 多项式排序：将所建立的多项式按指数非递减（从小到大）进行排序；
③ 多项式相加：实现两个多项式相加操作。操作生成一个新的多项式，原有的两个多项式不变，返回生成的多项式的头结点；
④  多项式的输出；
⑤ 主函数通过调用多项式链表建立函数，输入两个多项式并分别输出；输出排序后的两个多项式；分别调用多项式相加函数实现多项式相加、相减操作，分别输出操作结果。
 */

#include <iostream>

using namespace std;

typedef struct Node
{
	double coefficient;
	int index;
	struct Node *next;
} Item;

//定义多项式的对象
class Polynomial
{
private:
	Item head;//这个就作为头结点吧
	void merger();//合并同类项的函数
	Polynomial twoWayMerger(Polynomial *pol);//二路归并算法
public:
	Polynomial();

	~Polynomial();

	void sort();                                                                //② 多项式排序
	Polynomial &operator=(Polynomial &pol);                                    //赋值号重载
	Polynomial operator+(Polynomial &pol);                                     //③ 多项式相加
	Polynomial operator-(Polynomial &pol);                                     //③ 多项式相减
	friend ostream &operator<<(ostream &out, Polynomial &pol);                 //④ 多项式的输出
	friend istream &operator>>(istream &in, Polynomial &pol);                 //① 多项式链表建立
};

int main101109(void)
{
	Polynomial pol1, pol2;//定义两个多项式
	cout << "请输入第1条二项式(只写系数和指数):" << endl;
	cin >> pol1;
	cout << "请输入第2条二项式(只写系数和指数):" << endl;
	cin >> pol2;

	cout << "排序前：" << endl;
	cout << pol1;        //输出
	cout << pol2;        //输出

	pol1.sort();          //排序
	pol2.sort();          //排序

	cout << "排序后：" << endl;
	cout << pol1;        //输出
	cout << pol2;        //输出

	Polynomial pol3 = pol1 + pol2;
	cout << "相加的结果:" << endl;
	cout << pol3;


	Polynomial pol4 = pol1 - pol2;
	cout << "相减的结果:" << endl;
	cout << pol4;

	return 0;
}

//构造函数
Polynomial::Polynomial()
{
}

//析构函数
Polynomial::~Polynomial()
{

}

//合并同类项的函数
void Polynomial::merger()
{
	Item *p1 = NULL, *p2 = NULL;

	//遍历所有元素-1
	for (p1 = head.next; p1 != NULL && p1->next != NULL; p1 = p1->next)
	{
		//遍历余下相同的元素
		for (p2 = p1->next; p2 != NULL && p1->index == p2->index; p2 = p2->next)
		{
			//合并同类项
			p1->coefficient += p2->coefficient;
			p1->next = p2->next;
		}
	}
}

//二路归并算法
Polynomial Polynomial::twoWayMerger(Polynomial *pol)
{
	Polynomial sumPol;//结果
	Item *pItem = &sumPol.head;//指向结果的正在处理的结点
	Item *p1 = &this->head;//1链的处理点
	Item *p2 = &pol->head;//2链的处理点
	Item *p = NULL;

	//二路归并算法
	while (p1->next != NULL && p2->next != NULL)
	{
		if (p1->next->index < p2->next->index)        //小的放在前
		{
			p1 = p1->next;
			p = p1;
		} else//大的放在后
		{
			p2 = p2->next;
			p = p2;
		}

		//拷贝一个结点p, 并挂到新链表上
		Item *newItem = new Item();
		newItem->coefficient = p->coefficient;
		newItem->index = p->index;
		newItem->next = NULL;
		pItem->next = newItem;
		pItem = newItem;
	}

	if (p1->next != NULL)
	{
		p = p1;
	} else
	{
		p = p2;
	}

	while (p->next != NULL)
	{
		p = p->next;
		Item *newItem = new Item();//定义新结点
		newItem->coefficient = p->coefficient;//输入系数
		newItem->index = p->index;      //输入指数
		newItem->next = NULL;      //收尾
		pItem->next = newItem;     //上家指下家
		pItem = newItem;           //当前指当前
	}

	return sumPol;
}

//① 多项式链表建立：以（系数，指数）方式输入项建立多项式，返回所建立的链表的头结点；
istream &operator>>(istream &in, Polynomial &pol)
{
	Item *pItem = &pol.head;

	while (in.peek() != '\n')
	{
		Item *newItem = new Item();//定义新结点
		in >> newItem->coefficient;//输入系数
		in >> newItem->index;      //输入指数
		newItem->next = NULL;      //收尾
		pItem->next = newItem;     //上家指下家
		pItem = newItem;           //当前指当前
	}
	getchar();

	return in;
}

//② 多项式排序：将所建立的多项式按指数非递减（从小到大）进行排序；
void Polynomial::sort()
{
	//遍历所有结点
	for (Item *p1 = head.next; p1 != NULL; p1 = p1->next)
	{
		//遍历p1后所有结点
		for (Item *p2 = p1->next; p2 != NULL; p2 = p2->next)
		{
			if (p1->index > p2->index)
			{
				//直接换数据就好？
				double t1 = p1->coefficient;
				int t2 = p1->index;
				p1->coefficient = p2->coefficient;
				p1->index = p2->index;
				p2->coefficient = t1;
				p2->index = t2;
			}
		}
	}
}

//③ 多项式相加：实现两个多项式相加操作。操作生成一个新的多项式，原有的两个多项式不变，返回生成的多项式的头结点；
Polynomial Polynomial::operator+(Polynomial &pol)
{
	Polynomial sumPol = twoWayMerger(&pol);//结果
	return sumPol;
}

//多项式相减
Polynomial Polynomial::operator-(Polynomial &pol)
{
	Item *pItem = pol.head.next;

	//将pol变为负的
	while (pItem != NULL)
	{
		pItem->coefficient = 0 - pItem->coefficient;
		pItem = pItem->next;
	}
	Polynomial sumPol = twoWayMerger(&pol);//结果

	return sumPol;
}

//④  多项式的输出；
ostream &operator<<(ostream &out, Polynomial &pol)
{
	pol.merger();

	for (Item *pItem = pol.head.next; pItem != NULL; pItem = pItem->next)
	{
		if (pItem->coefficient > 0)
		{
			out << pItem->coefficient;
		} else if (pItem->coefficient < 0)
		{
			out << "(" << pItem->coefficient << ")";
		} else
		{
			continue;
		}

		out << "*X^";//输出系数
		out << pItem->index;//输出指数

		if (pItem->next != NULL)
		{
			out << " + ";
		}
	}

	out << endl;

	return out;
}

//赋值号重载
Polynomial &Polynomial::operator=(Polynomial &pol)
{
	Item *p1 = &this->head;//指向当前要处理的结点
	Item *p2 = pol.head.next;//指向当前要处理的结点

	//遍历链2
	while (p2 != NULL)
	{
		//新建结点
		p1->next = new Item();
		p1 = p1->next;
		p1->coefficient = p2->coefficient;//输入系数
		p1->index = p2->index;      //输入指数
		p1->next = NULL;      //收尾
	}

	return *this;
}
