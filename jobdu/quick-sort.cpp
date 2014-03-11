/*
 * quick-sort.cpp
 * Copyright (C) 2014 Arming lee <cloudniw1@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#include<cstdio>
using namespace std;
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int *array, int s, int e)
{
    int t = array[e];
    int i = s-1;
    int j;
    for(j=s; j<e; j++){
        if(array[j] <= t){
            i++;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i+1], &array[e]);
    return i+1;
}
void quick_sort(int *array, int s, int e)
{
    if(s<e){
        int q = partition(array, s, e);
        quick_sort(array, s, q-1);
        quick_sort(array, q+1, e);
    }
}
int main(int argc, char *argv[])
{
    int a[10] = {0};
    for(int i = 0;i<10; i++)
    {
        scanf("%d", &a[i]);
    }
    quick_sort(a, 0, 9);
    for(int i = 0; i< 10; i++)
        printf("%d ",a[i] );
    return 0;
}


