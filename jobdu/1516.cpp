/*
 * template.cpp
 * Copyright (C) 2014 Arming lee <cloudniw1@gmail.com>
 *
 * Distributed under terms of the MIT license.
 *
 *条件判断，浪费了不少时间，考虑要全面
 */

#include<cstdio>
using namespace std;

/*void reorder(int *a, int n)
{
    int *p, *q;
    int t;
    p = a, q = a;
    while(p<a+n && q<a+n){
        //while(p<a+n && *p % 2 != 1){
        while(p<a+n && (*p & 0x01 != 1)){
            //++p;
            p++;
        }
        while(q<a+n && (*q & 0x01 != 0)){
            q++;
        }
        if(p>q){
            int *m = p;
            t = *p;
            while(m>q){
                *m = *(m-1);
                //--m;
                m--;
            }
            *q = t;
            q++;
            p++;
        }
        else{
            p++;
        }
    }
}*/
void reorder(int *a, int n)
{
    int p, q;
    int t;
    p = 0, q = 0;
    while(p<n && q<n){
        while(p<n && a[p] % 2 != 1){
        //while(p<n && (a[p] & 0x01 != 0)){
            //++p;
            p++;
        }
        while(q<n && (a[q] % 2 != 0)){
        //while(q<n && (a[q] & 0x01 != 1)){
            q++;
        }
        if(p<n && p>q &&(a[p] & 1)){
            int m = p;
            t = a[p];
            while(m>q){
                a[m] = a[m-1];
                //--m;
                m--;
            }
            a[q] = t;
            q++;
            p++;
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



