/*
 * template.cpp
 * Copyright (C) 2014 Arming lee <cloudniw1@gmail.com>
 *
 * Distributed under terms of the MIT license.
 *
 * 两个链表的第一个公共结点 
 *
 */

#include<cstdio>
using namespace std;
struct ListNode{
    int value;
    ListNode *next;
    ListNode(int val):value(val), next(NULL){};
};
ListNode *initList(int n);
ListNode *firtCommon(ListNode *first, ListNode *second);
int getListLength(ListNode *list);
int main()
{
    int m, n;
    while(scanf("%d %d", &m, &n) != EOF){
        ListNode *first = initList(m);
        ListNode *second = initList(n);
        ListNode *common = firtCommon(first, second);
        if(!common)
            printf("My God\n");
        else{
            printf("%d\n", common->value);
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

ListNode *firtCommon(ListNode *first, ListNode *second)
{
    if(first == NULL)
        return NULL;
    if(second == NULL)
        return NULL;
    int len1 = getListLength(first);
    int len2 = getListLength(second);
    int diff = len1 - len2;
    ListNode *longList = first;
    ListNode *shortList = second;
    if(len2 > len1){
        longList = second;
        shortList = first;
        diff = len2 - len1;
    }
    for(int i = 0; i<diff; ++i)
        longList = longList->next;
    while(longList && shortList && longList->value != shortList->value){
        longList = longList->next;
        shortList = shortList->next;
    }
    return longList;
}

int getListLength(ListNode *list)
{
    int length = 0;
    ListNode *p = list;
    while(p){
        ++length;
        p = p->next;
    }
    return length;
}
/*
 * 利用栈实现
 */
/*#include<stack>

void init_stack(int n, stack<int> &st);
const int FLAG = -9999999;
int main()
{
    int m, n;
    stack<int> a, b;
    int common;
    while(scanf("%d %d", &m, &n) != EOF){
        while(! a.empty())
            a.pop();
        while(!b.empty())
            b.pop();
        common = FLAG;
        init_stack(m, a);
        init_stack(n, b);
        while(a.top() == b.top()){
            common = a.top();
            a.pop();
            b.pop();
        }
        if(common == FLAG)
            printf("My God\n");
        else
            printf("%d\n", common);
    }
    return 0;
}

void init_stack(int n, stack<int> &st)
{
    int val;
    while(n--){
        scanf("%d", &val);
        st.push(val);
    }
}*/
