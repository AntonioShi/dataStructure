//
// Created by niracler on 17-10-6.
//
/*

题目2：顺序循环队列的基本操作
        设队列的元素类型为char，实现顺序循环队列的各种基本操作的程序：
① 初始化队列Q；
② 判断队列Q是否为空；
③ 入队操作。循环调用入队操作，将若干元素（不少于10个）入队；
④ 出队操作，出队一个元素，并输出该元素；
⑤ 输出队列元素个数；
⑥ 调用入队操作，依次入队4个元素；
⑦ 输出队列序列；
⑧ 主函数通过函数调用实现以上各项操作。
 */
#include <iostream>

using namespace std;

//关于这个循环队列装什么
typedef char DataType;

//关于我的循环队列的定义
class MyQueue
{
private:
	int front;      //头元素的下标
	int rear;       //尾元素的下标
	int size;       //有效元素的个数
	int capacity;   //该循环队列的最大长度
	DataType *array;//所分配的空间
public:
	MyQueue(int capacity);             //构造函数,
	~MyQueue();                        //析构函数
	bool isFull();                     //判断队列是否为满的函数
	bool isEmpty();                    //判断队列是否为空的函数
	void push(const DataType &val);    //入队的函数
	void pop();                        //出队函数
	DataType &getFront();              //返回队列首个元素的函数
	int getSize();                     //获取长度的函数
};

int main201710092031(void)
{
	MyQueue queue(10);//初始化一个大小为十的队列

	//同学入队
	for (int i = 1; !queue.isFull(); ++i)
	{
		queue.push((char)i);
	}

	cout << "这个队伍的长度是：" << queue.getSize() << endl;

	//同学出队
	for (int j = 1; !queue.isEmpty(); ++j)
	{
		cout << "同学" << j << "：我叫谢锐伟" << (int)queue.getFront() << endl;
		queue.pop();
	}

	return 0;
}

//构造函数，
//函数功能：初始化队列，初始长度为0
//参数：队列的最大长度
MyQueue::MyQueue(int capacity)
{
	this->array = new DataType[capacity];//分配空间
	this->capacity = capacity;
	this->front = 0;
	this->size = 0;
	this->rear = capacity - 1;// This is important, see the enqueue????
}

//析构函数
//函数功能：对之前分配的空间释放
MyQueue::~MyQueue()
{
	delete array;
}

//函数功能：判断队列是否为满
//返回值：true满， false不满
bool MyQueue::isFull()
{
	//当有效元素的个数等于队列最大长度时为满
	return (this->size == this->capacity);
}

//函数功能：判断队列是否为空
//返回值：true空， false不空
bool MyQueue::isEmpty()
{
	//长度为零时，就是空嘛
	return (this->size == 0);
}

//函数功能：入队
void MyQueue::push(const DataType &val)
{
	if (isFull()) return;                          //判断是否为满
	this->rear = (this->rear + 1) % this->capacity;//改变队尾下标
	this->array[this->rear] = val;                 //入队
	this->size++;                                  //有效长度加1
}

//函数功能，出队
void MyQueue::pop()
{
	if(isEmpty()) return;
	this->front = (this->front + 1) % this->capacity;
	this->size--;
}

//函数功能：返回队列首个元素
DataType& MyQueue::getFront()
{
	return this->array[this->front];
}

//函数功能：获取长度
int MyQueue::getSize()
{
	return this->size;
}