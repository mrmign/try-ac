/*
 * template.cpp
 * Copyright (C) 2014 Arming lee <cloudniw1@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#include<cstdio>
using namespace std;

void reorder(int *a, int n)
{
    int *p, *q;
    int t;
    p = a, q = a;
    while(p<a+n && q<a+n){
        while(p<a+n && *p % 2 != 1){
            ++p;
        }
        while(q<a+n && *q %2 != 0){
            ++q;
        }
        if(p>q){
            int *m = p;
            t = *p;
            while(m>q){
                *m = *(m-1);
                --m;
            }
            *q = t;
            ++q;
            ++p;
        }
        else{
            p++;
        }
    }
}
void print(int *a, int n)
{
    for(int i = 0; i < n-1; ++i){
        printf("%d ", a[i]);
    }
    printf("%d\n", a[n-1]);
}
int main()
{
    int n;
    while(scanf("%d", &n) != EOF){
        int *a = new int[n];
        int i = 0;
        while(i < n){
            scanf("%d", &a[i]);
            ++i;
        }
        reorder(a, n);
        print(a,n);
        delete []a;
    }
    return 0;
}



