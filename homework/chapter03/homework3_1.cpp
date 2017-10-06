//
// Created by niracler on 17-9-27.
//

/*编写判断一个字符序列是否是回文的函数
 *要求:
 *输入:一个字符串
 *输出:是（否）
 * */

#include <iostream>

using namespace std;

bool isPalindrome(string &str);//判断一个字符序列是否是回文的函数

int main1006(void)
{
    string str;//声明一个字符串
    cin >> str;//输入

    //处理并输出
    if(isPalindrome(str))
    {
        cout << "是" << endl;
    }
    else
    {
        cout << "否" << endl;
    }

    return 0;
}

//函数功能：判断一个字符序列是否是回文
//参数：要检验的字符串
//返回值：是就true不是就false
bool isPalindrome(string &str)
{
    int i;

    for (i = 0; i < str.size()/2; ++i)
    {
        if(str[str.size()-1-i] != str[i])
        {
            break;
        }
    }

    if (i == str.size()/2)
    {
        return true;
    }
    else
    {
        return false;
    }
}
