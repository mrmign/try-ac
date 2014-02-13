/*
 * template.cpp
 * Copyright (C) 2014 Arming lee <cloudniw1@gmail.com>
 *
 * Distributed under terms of the MIT license.
 *
 * 链表中倒数第k个结点
 *
 */

#include<cstdio>
using namespace std;
struct ListNode{
    int value;
    ListNode *next;
    ListNode(int x):value(x), next(NULL){  };
};

ListNode *backNth(ListNode *header,int num, int n);
void deleteListNode(ListNode *header);
int main()
{
    int n, val, num;
    ListNode *header = NULL;
    ListNode *p;
    while(scanf("%d %d", &num, &n) != EOF){
        int c = num;
        while(c--){
           scanf("%d", &val); 
           ListNode *ln = new ListNode(val); 
           //ln->value = val;
           //ln->next = NULL;
           if(header == NULL){
               p = ln;
               header = ln;
           }
           else{
               p->next = ln;
               p = ln;
           }
        }
        ListNode *it = header;
        //while(it){
        //    printf("%d ", it->value);
        //    it = it->next;
        //}
        ListNode * ret = backNth(header, num, n);
        if(ret)
            printf("%d\n", ret->value);
        else
            printf("NULL\n");
        deleteListNode(header);
        header = NULL;
    }
    return 0;
}

ListNode *backNth(ListNode *header,int num, int n)
{
    if(header == NULL)
        return NULL;
    if(n > num || n == 0)
        return NULL;
    if(n == num)
        return header;
    ListNode *p, *q;
    p = header, q = header;
    int c = n;
    //while((c--, c>0) && p != NULL)
    while(--c){
        p = p->next;
    }
    while(p->next != NULL){
        p = p->next;
        q = q->next;
    }
    //printf("aa%d\n", q->value);
    return q;
}

void deleteListNode(ListNode *header)
{
    ListNode *p = header;
    while(p){
        header = p->next;
        delete p;
        p = header;
    }
}

