//
// Created by niracler on 17-9-27.
//
//
//一矩形阵列由数字0到9组成，数字1到9代表细胞，细胞的定义为沿细胞数字上下左右还是相同数字则为同一细胞，如:阵列
//scholat.com
// 有5个细胞，编写程序求给定矩形阵列的细胞个数

//当然，这个是老师的辅助代码
#include <queue>
#include <iostream>
#include <iomanip>

using namespace std;

//两个数组依次结合代表四个方向
void bfs(int **area, int x, int y, int maxsize,int cell);

//矩阵类
class Matrix
{
private:
    int **area;
    int maxsize;//图像大小（二维数组阶数）
    int type;//细胞种类数
public:
    Matrix(int n, int type);

    friend int count(Matrix &mat);         //一个数细胞数目的函数
    friend ostream &operator<<(ostream &out, Matrix &mat);
};

int main201710202020(void)
{
    Matrix mat(5, 2);

    cout << "\n好，下面这里是培养皿:" << endl;
    cout << mat << endl;
    cout << "细胞数目：" << count(mat) << endl;

    return 0;
}

Matrix::Matrix(int maxsize, int type)
{
    this->maxsize = maxsize;
    this->type = type;

    //随机生成显微镜图像
    area = new int *[maxsize];
    srand(time(NULL));

    for (int i = 0; i < maxsize; i++)
    {
        area[i] = new int[maxsize];
    }

    for (int i = 0; i < maxsize; i++)
    {
        for (int j = 0; j < maxsize; j++)
        {
            area[i][j] = rand() % (this->type + 1);
        }
    }
}


//输出函数重载
ostream &operator<<(ostream &out, Matrix &mat)
{
    for (int i = 0; i < mat.maxsize; i++)
    {
        for (int j = 0; j < mat.maxsize; j++)
        {
            out << setw(4) << mat.area[i][j];
        }
        out << endl;
    }

    return out;
}

//一个数细胞数目的函数
int count(Matrix &mat)
{
    int num = 0;
    int cell;//细胞数字

    //接下来就一个一个地找，为了保证每次都有四个方向,所以从1开始
    for (int i = 0; i < mat.maxsize; i++)
    {
        for (int j = 0; j < mat.maxsize; j++)
        {
            //找到细胞的边角
            if (mat.area[i][j] != 0)
            {
                cell = mat.area[i][j];
                mat.area[i][j] = 0;//千万不能漏
                bfs(mat.area, i, j, mat.maxsize, cell);
                num++;
            }
        }
    }

    return num;
}

void bfs(int **area, int x, int y, int maxsize, int cell)
{
    int x1[4] = {1, 0, -1, 0}, y1[4] = {0, 1, 0, -1};//利用简单数组表示方向；

    //依次找到四个方向
    for (int i = 0; i < 4; i++)
    {
        if (x + x1[i] >= 0 && x + x1[i] < maxsize && y + y1[i] >= 0 && y + y1[i] < maxsize/*排除越界的可能*/
            && area[x + x1[i]][y + y1[i]] == cell/*确认是否是细胞数字*/)
        {
            area[x + x1[i]][y + y1[i]] = 0; //将找到细胞数字置为0防止重复
            bfs(area, x + x1[i], y + y1[i], maxsize, cell);//搜索下一个点
        }
    }
}