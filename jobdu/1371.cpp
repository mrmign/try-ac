/*
 * template.cpp
 * Copyright (C) 2014 Arming lee <cloudniw1@gmail.com>
 *
 * Distributed under terms of the MIT license.
 *
 * 最小的K个数
 *
 */

#include<cstdio>
#include<set>
#include<functional>
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
void quicksort(int *array , int start, int end)
{
    if(start < end){
        int index = partition(array, start, end);
        quicksort(array, start, index - 1);
        quicksort(array, index + 1, end);
    }
}
void minK(int *array, int len, int k)
{
    int start = 0;
    int end = len - 1;
    int index = partition(array, start, end);
    while(index != k-1){
        if(index > k-1){
            end = index - 1;
        }
        else{
            start = index + 1;
        }
        index = partition(array, start, end);
    }
}
/*void solve(int *array, int len, int k)
{
    minK(array, len, k);
    quicksort(array, 0, k-1);
    bool out_space = false;
    for (int i = 0; i < k; ++i)
    {
        if(!out_space){
            printf("%d", array[i]);
            out_space = true;
        }
        else{
            printf(" %d", array[i]);
        }
    }
    printf("\n");
}*/
typedef multiset<int, greater<int> > Set;
typedef multiset<int, greater<int> >::iterator SetIter;
typedef multiset<int, greater<int> >::reverse_iterator SetReverseIter;
void solve(int *array, int len, int k)
{
    Set mink;
    for(int i = 0; i < len; i++){
        if(mink.size() < k){
            mink.insert(array[i]);
        }
        else{
            SetIter iter = mink.begin();
            if(array[i] < *iter){
                mink.erase(*iter);
                mink.insert(array[i]);
            }
        }
    }
    SetReverseIter it = mink.rbegin();
    bool space = false;

    for(;it != mink.rend(); ++it){
        if(!space){
            printf("%d",*it);
            space = true;
        }
        else
            printf(" %d", *it);
    }
    printf("\n");

}
int a[200001];
int main()
{
    int n;
    int k;
    while(scanf("%d %d", &n, &k) != EOF){
        for (int i = 0; i < n; ++i)
        {
            scanf("%d", &a[i]);
        }
        solve(a, n, k);
    }
    return 0;
}



