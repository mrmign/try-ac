/*
 * template.cpp
 * Copyright (C) 2014 Arming lee <cloudniw1@gmail.com>
 *
 * Distributed under terms of the MIT license.
 *
 * 跳台阶
 *
 */

#include<cstdio>
#include<cmath>
using namespace std;
long long s[71];
long long s2[51];
void init()
{
    /*s[1] = 1;
    s[2] = 2;
    for(int i = 3;i<71; i++)
    {
        s[i] = s[i-1] + s[i-2];
    }*/
    for (int i = 1; i < 51; ++i)
    {
        s2[i] = (long long)pow((double)2, (double)(i-1));
    }
}
long long dance_steps(int n)
{
    /*if(n == 1)
        return 1;
    if(n == 2)
        return 2;
    return dance_steps(n-1) + dance_steps(n-2);*/
    // return s[n];
    return s2[n];
}

void solve(int n)
{
    long long steps = dance_steps(n);
    printf("%lld\n", steps);
}
int main()
{
    init();
    int n;
    while(scanf("%d", &n) != EOF){
        solve(n);
    }
    return 0;
}



