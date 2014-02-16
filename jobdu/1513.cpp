/*
 * template.cpp
 * Copyright (C) 2014 Arming lee <cloudniw1@gmail.com>
 *
 * Distributed under terms of the MIT license.
 *
 * 二进制中1的个数
 *
 */

#include<cstdio>
using namespace std;
int count(int n)
{
    int c = 0;
    unsigned int m = 1;
    while(m){
        if(n & m)
            c++;
        m <<= 1;
    }
    return c;
}

int count_1(int n)
{
    int cnt = 0;
    while(n){
        ++cnt;
        n = (n-1)&n;
    }
    return cnt;
}
int main()
{
    int n;
    while(scanf("%d", &n) != EOF){
        //printf("%d\n", count(n));
        printf("%d\n", count_1(n));
    }
    return 0;
}



