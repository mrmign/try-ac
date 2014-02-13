/*
 * template.cpp
 * Copyright (C) 2014 Arming lee <cloudniw1@gmail.com>
 *
 * Distributed under terms of the MIT license.
 *
 * 斐波那契数列
 *
 */

#include<cstdio>
using namespace std;

/*int main()
{
    long long a = 1, b = 1;
    int n;
    long long tmp;
    int count;
    while(scanf("%d", &n) != EOF){
       a = 1, b = 1;
       count = n-2;
       while(count>0 && count--){
          tmp = a + b;
          a = b;
          b = tmp;
       }
       printf("%lld\n", b);
    }
    return 0;
}*/

/*int main()
{
    long long fib[71] = {0,1,1};
    int n;
    for(int i=3;i<71;i++)
        fib[i] = fib[i-1] + fib[i-2];
    while(scanf("%d", &n) != EOF)
        printf("%lld\n", fib[n]);
    return 0;
}*/


/*
 * 利用矩阵进行求解
 */

long long a[][2] = { {1, 1},
                    {1, 0}};
long long fib(int n);
int main()
{
    int n;
    while(scanf("%d", &n) != EOF){
        long long ret = fib(n);
        printf("%lld\n", ret);
    }

    return 0;
}

long long fib(int n)
{

}
