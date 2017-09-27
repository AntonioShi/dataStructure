//
// Created by niracler on 17-9-25.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>  //为了用isdigit(char )判断字符是否是数字
#include "MyStack.h"

int is_operator(char symbol);//判断运算符的函数
int precedence(char symbol);//判断各种运算符优先级的函数
void InfixToPostfix(char infix_exp[], char postfix_exp[]);//中缀转后缀的函数

int main092720(void)
{
    char infix[100], postfix[100];         //声明前缀表达式与后缀表达式的字符串

    printf("\n请输入中缀表达式 : ");
    scanf("%s", infix);

    InfixToPostfix(infix,postfix);
    printf("后缀表达式为: ");
    puts(postfix);

    return 0;
}

//判断运算符的函数
//参数：你要判断的字符
//返回值：是1，不是0
int is_operator(char symbol)
{
    if (symbol == '^' || symbol == '*' || symbol == '/' || symbol == '+' || symbol == '-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

//判断各种运算符优先级的函数
//参数：你要判断的字符
//返回值：优先级高度
int precedence(char symbol)
{
    if (symbol == '^')
    {
        return (3);
    }
    else if (symbol == '*' || symbol == '/')
    {
        return (2);
    }
    else if (symbol == '+' || symbol == '-')
    {
        return (1);
    }
    else
    {
        return (0);
    }
}

//中缀转后缀的函数
//参数：前缀，　后缀
void InfixToPostfix(char infix_exp[], char postfix_exp[])
{
    int i = 0, j = 0;//循环控制
    char item;       //当前操作元素
    char x;          //下一个操作元素呢！！！
    SeqStack myStack;//定义一个栈

    StackPush(&myStack, '(');            //将一个＇(＇放到栈底
    strcat(infix_exp, ")");              //将一个＇）＇放到后缀表达式的最后

    //开始遍历中缀表达式
    item = infix_exp[i];
    while (item != '\0')
    {
        //看见左括号进栈
        if (item == '(')
        {
            StackPush(&myStack, item);
        }
            //数字进后缀表达式
        else if (isdigit(item) || isalpha(item))
        {
            postfix_exp[j] = item;
            j++;
        }
            //看见运算符，出栈
        else if (is_operator(item) == 1)
        {
            StackPop(&myStack, &x);

            //假如栈顶运算符的优先级大于当前运算符，则放进后缀表达式
            while (is_operator(x) == 1 && precedence(x) >= precedence(item))
            {
                postfix_exp[j] = x;
                j++;
                StackPop(&myStack, &x);
            }
            //将x,item放回去
            StackPush(&myStack, x);
            StackPush(&myStack, item);
        }
            //遇见右括号,那么在看见左括号前，入栈吧！！
        else if (item == ')')
        {
            StackPop(&myStack, &x);
            while (x != '(')
            {
                postfix_exp[j] = x;
                j++;
                StackPop(&myStack, &x);
            }
        }
            //非数字非括号，非运算符，那么就错了
        else
        {
            printf("\n无效的中缀表达式。\n");
            getchar();
            exit(1);
        }
        i++;

        item = infix_exp[i]; //下一个字符进入，再次开始循环
    }

    //下面就是错误的表达式呢！！！
    if (!StackEmpty(&myStack))
    {
        printf("\n无效的中缀表达式。\n");
        getchar();
        exit(1);
    }

    postfix_exp[j] = '\0'; //在最后的最后,赋值上'\0'，表示结尾

}
