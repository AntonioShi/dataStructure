//
// 这个呢，不是我的代码
// 是我同学的代码，可能是正解

#include<iostream>
#include<queue> //他这里是用队列，我那是用递归

using namespace std;

//分别对应上下左右四个方向
const int gx[4] = {0, 0, -1, 1};
const int gy[4] = {1, -1, 0, 0};

int m, n, total = 0;//可翔打错字,我改过来了
int a[100][100];    //这里是100*100大小的棋盘,当然，是否用完是另外一回事

void init();                //初始化细胞板的函数
void calculate(int, int);   //实不相瞒，这个就是bfs算法

int mainxukexinag()
{
    init();
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (a[i][j])
            {
                calculate(i, j);
            }
        }
    }
    cout << "tatol(总数)=" << total << endl;

    return 0;
}

void calculate(int x, int y)
{
    queue<int> qx, qy;//两队列分别存储当前点的行和列
    int x1, y1;
    int temp;
    total++; //细胞数加一
    qx.push(x); //把当前细胞的行和列入队
    qy.push(y);
    temp = a[x][y];
    a[x][y] = 0;
    while (!qx.empty())//当队列非空
    {
        for (int i = 0; i < 4; i++)//对当前细胞的上下左右进行搜索
        {
            x1 = qx.front() + gx[i];
            y1 = qy.front() + gy[i];
            if (x1 >= 0 && x1 < m && y1 >= 0 && y1 < n && a[x1][y1] == temp)
            {
                qx.push(x1);//如果没有越界且（x1,y1）为细胞 ，入队
                qy.push(y1);
                a[x1][y1] = 0;
            }
        }
        qx.pop();
        qy.pop();
    }
}

void init()
{
    cout << "请输入矩阵的行数和列数: ";
    cin >> m >> n;
    cout << "请输入矩阵:" << endl;
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> a[i][j];
        }
    }
}