//
// Created by niracler on 17-10-24.
//

#include <iostream>
#include <string>

using namespace std;
const int N = 8;

int main753846468468468468(void)
{
    int i;
    string A = "┏";
    for (i = 0; i < N; i++)A += "┳";
    {
        A += "┓\n";
    }
    string B = "┣";
    for (i = 0; i < N; i++)B += "╋";
    {
        B += "┫\n";
    }
    string C = "┗";
    for (i = 0; i < N; i++)C += "┻";
    {
        C += "┛\n";
        cout << A;
    }
    for (i = 0; i < N; i++)cout << B;
    {
        cout << C;
    }
    return 0;
}