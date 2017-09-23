//
// Created by niracler on 17-9-13.
//

//关于快速幂的求法
//其时间复杂度为 O(log₂N)

#include <stdio.h>

int power(int m, int n)
{
    if(n==1) return m;
    int temp = power(m,n/2);
    return (n%2==0 ? 1 : m)*temp*temp;
}

int main0923(void)
{
    int x, n;

    scanf("%d%d", &x, &n);
    printf("%d", power(x, n));

    return 0;
}