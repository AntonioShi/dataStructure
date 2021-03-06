//
// Created by niracler on 17-9-27.
//

//棋类比赛后需要“复盘”，即将比赛双方的每一步操作重现，但不包括“悔棋”操作，请设计一种结构能够在比赛过程进行记录，在比赛后能够将操作保存下来进行复盘。（以围棋为例，每一步操作包括记录落子的行、列、颜色）
//要求:
//1、设计存储结构
//2、对多次输入进行记录（输入:三个整形，分别代表行、列、颜色）
//3、若输入-1，则将前一步的输入删除（注意连续多个-1的情况）
//4、将所有输出按输入顺序输出

#include <iostream>
#include <stack>//好吧，决定用栈了

using namespace std;

//棋步的类
class Chess
{
private:
    int row;
    int column;
public:
    friend ostream &operator<< (ostream &out, Chess &che);

    friend istream &operator>> (istream &in, Chess &che);
};

int main (void)
{
    Chess newChe;
    stack<Chess> checkerboard;
    stack<Chess> checkerboard2;

    //输入部分
    cout << "请输入\"行 列\"（-1悔棋,0结束输入）:" << endl;
    for (int i = 1;; ++i)
    {
        cout << "第" << i << "步";
        if (i % 2 == 1)
        {
            cout << "(黑)：";
        }
        else
        {
            cout << "(白)：";
        }

        try
        {
            cin >> newChe;
        }
        catch (int x)
        {
            if (x == -1)//-1就是悔棋,弹出
            {
                i -= 2;
                checkerboard.pop();
                continue;
            }
            else
            {
                break;
            }
        }
        catch (char const* message)
        {
            i -= 1;
            cout << message << endl;
            continue;
        }

        checkerboard.push(newChe);
    }


    //输出部分
    for (int i = 1;!checkerboard.empty(); ++i)
    {
        newChe = checkerboard.top();
        checkerboard2.push(newChe);
        checkerboard.pop();
    }

    for (int i = 1;!checkerboard2.empty(); ++i)
    {
        newChe = checkerboard2.top();
        checkerboard2.pop();
        cout << "第" << i << "步";
        if (i % 2 == 1)
        {
            cout << "(黑)：";
        }
        else
        {
            cout << "(白)：";
        }
        cout << newChe;
    }

    return 0;
}

ostream &operator<< (ostream &out, Chess &che)
{
    cout << che.row << " ";
    cout << che.column << " " << endl;

    return out;
}

istream &operator>> (istream &in, Chess &che)
{
    in >> che.row;

    if (che.row == 0 || che.row == -1)
    {
        throw che.row;
    }

    in >> che.column;

    if (che.row > 16 || che.row < 0 || che.column > 16 || che.row < 0)
    {
        throw "\n超过棋盘大小了\n";
    }

    return in;
}
