/*
 * template.cpp
 * Copyright (C) 2014 Arming lee <cloudniw1@gmail.com>
 *
 * Distributed under terms of the MIT license.
 *
 * 17.合并两个排序的链表
 *
 */

#include<cstdio>

struct ListNode{
    int value;
    ListNode *next;
    ListNode(int val):value(val), next(NULL){};
};
ListNode *initList(int n);
ListNode *mergeList(ListNode *first, ListNode *second);
int main()
{
    int m, n;
    while(scanf("%d %d", &m, &n) != EOF){
        ListNode *first = initList(m);
        ListNode *second = initList(n);
        ListNode *merge = mergeList(first, second);
        if(!merge)
            printf("NULL\n");
        else{
            while(merge->next){
                printf("%d ", merge->value);
                merge = merge->next;
            }
            printf("%d\n", merge->value);
        }
    }
    return 0;
}

ListNode *initList(int n)
{
    if(n == 0)
        return NULL;
    ListNode *head = NULL;
    int val;
    ListNode *q;
    while(n--){
        scanf("%d", &val);
        ListNode *p = new ListNode(val);
        if(head == NULL)
        {
            head = p;
            q = p;
            continue;
        }
        q->next = p;
        q = p;
    }
    return head;
}

/*
 * 非递归解法
 */
/*ListNode *mergeList(ListNode *first, ListNode *second) {
    if(first == NULL)
        return second;
    if(second == NULL)
        return first;
    ListNode *merge = first->value <= second->value ? first : second;
    ListNode *p = merge, *q = first->value <= second->value ? second : first;
    ListNode *t = merge;
    while(p && q){
        if(p->value <= q->value){
            t = p;
            p = p->next;
        }
        else{
            t->next = q;
            t = q;
            q = q->next;
            t->next = p;
        }
    }
    if(p)
        t->next = p;
    if(q)
        t->next = q;
    return merge;
}*/

/*
 * 递归解法
 */
ListNode *mergeList(ListNode *first, ListNode *second)
{
    if(first == NULL)
        return second;
    if(second == NULL)
        return first;
    ListNode *mergeHeader = NULL;
    if(first->value <= second->value){
        mergeHeader = first;
        mergeHeader->next = mergeList(first->next, second);
    }
    else{
        mergeHeader = second;
        mergeHeader->next = mergeList(first, second->next);
    }
    return mergeHeader;
}

