/*
 * template.cpp
 * Copyright (C) 2014 Arming lee <cloudniw1@gmail.com>
 *
 * Distributed under terms of the MIT license.
 *
 * 链表中倒数第k个结点
 */

#include<cstdio>
using namespace std;
struct ListNode{
    int value;
    ListNode *next;
};
void backNth(ListNode **header, int n);
int main()
{
    int n, val, num;
    ListNode **header = NULL;
    ListNode *p;
    while(scanf("%d %d", &num, &n) != EOF){
        if(num ==0 || n == 0){
            printf("NULL\n");
            continue;
        }
        while(num--){
           ListNode *ln = new ListNode; 
           //scanf("%d", &(ln->value)); 
           scanf("%d", &val); 
           ln->value = val;
           ln->next = NULL;
           if(header == NULL){
               p = ln;
               header = &ln;
           }
           else{
               p->next = ln;
               p = ln;
           }
        }
        backNth(header, n);
        header = NULL;
    }
    return 0;
}

void backNth(ListNode **header, int n)
{
    if(header == NULL)
        return;
    ListNode *p, *q;
    p = *header, q = *header;
    int c = n;
    while((c--, c>0) && p != NULL)
        p = p->next;
    if(p == NULL){
        printf("NULL\n");
        return;
    }
    while(p->next != NULL){
        p = p->next;
        q = q->next;
    }
    printf("aa%d\n", q->value);
}
