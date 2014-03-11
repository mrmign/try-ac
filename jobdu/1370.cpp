/*
 * template.cpp
 * Copyright (C) 2014 Arming lee <cloudniw1@gmail.com>
 *
 * Distributed under terms of the MIT license.
 *
 * 数组中出现次数超过一半的数字
 *
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
bool checkTimes(int *array, int len, int num)
{
    int times = 0;
    for(int i = 0; i<len; i++){
        if(array[i] == num)
            times++;
    }
    if(times * 2 <= len)
        return false;
    else
        return true;
}
int moreThanHalfNum(int *array, int len)
{
    int mid = len>>1;
    int start = 0;
    int end = len - 1;
    int index = partition(array, start, end);
    while(index != mid){
        if(index > mid){
            end = index - 1;
        }
        else{
            start = index + 1;
        }
        index = partition(array, start, end);
    }
    int result = array[mid];
    if(checkTimes(array, len, result))
        return result;
    return -1;
}

/*
 * 解法2
 */
int countTimes(int *array, int len)
{
    int times = 1;
    int pre = array[0];
    for (int i = 1; i < len; ++i)
    {
        if(times == 0){
            pre = array[i];
            times = 1;
        }
        else if(array[i] == pre){
            times++;
        }
        else{
            times--;
        }
    }
    if(checkTimes(array, len, pre))
        return pre;
    else 
        return -1;
}
void solve(int *array, int len)
{
    //int s = moreThanHalfNum(array, len);
    int s = countTimes(array, len);
    printf("%d\n", s);
}

int a[100001];
int main()
{
    int n;
    while(scanf("%d", &n) != EOF){
        for (int i = 0; i < n; ++i)
        {
            scanf("%d", &a[i]);
        }
        solve(a, n);
        
    }
    return 0;
}


