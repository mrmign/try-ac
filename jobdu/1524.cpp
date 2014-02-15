/*
 * template.cpp
 * Copyright (C) 2014 Arming lee <cloudniw1@gmail.com>
 *
 * Distributed under terms of the MIT license.
 *
 * 26.复杂链表的复制
 *
 */

#include<cstdio>
#include <vector>
using namespace std;

struct ListNode{
    int value;
    ListNode *next;
    ListNode *sibling;
    ListNode(int val):value(val), next(NULL), sibling(NULL){};
};

ListNode *init_list(int n, vector<ListNode*> &nodeaddr)
{
    int val;
    ListNode *head = NULL;
    ListNode *q;
    while(n--){
        scanf("%d", &val);
        ListNode *p = new ListNode(val);
        nodeaddr.push_back(p);
        if(head == NULL){
            head = p;
            q = p;
        }
        else{
            q->next = p;
            q = p;
        }
    }
    return head;
}

void init_sibling(ListNode *head, int n, vector<ListNode*> &nodeaddr)
{
    int v;
    for(int i = 0; i < n; i++){
        scanf("%d", &v);
        if(v != 0)
            head->sibling = nodeaddr[v-1];
        head = head->next;
    }
}

void clone_node(ListNode *head)
{
    while(head){
        ListNode *p = new ListNode(head->value);
        p->next = head->next;
        head->next = p;
        head = p->next;
    }
}

void init_clone_sibling(ListNode *head)
{
    while(head){
        ListNode *p = head->next;
        if(head->sibling)
            p->sibling = head->sibling->next;
        head = p->next;
    }
}

ListNode *link_cloned_node(ListNode *head)
{
    ListNode *cloneHead = NULL;
    ListNode *tmp = NULL;
    while(head){
        ListNode *p = head->next;
        if(cloneHead == NULL){
            cloneHead = p;
            tmp = p;
        }
        else{
            tmp->next = p;
            tmp = p;
        }
        head->next = p->next;
        
        head = head->next;
    }
    return cloneHead;

}

void print_node(ListNode *head)
{
    while(head){
        int sibVal=0;
        if(head->sibling)
            sibVal = head->sibling->value;
        else
            sibVal = 0;
        printf("%d %d\n", head->value, sibVal);
        head = head->next;
    }
}
int main()
{
    int n;
    while(scanf("%d", &n) != EOF){
        vector<ListNode *> nodes;
        ListNode *head = init_list(n, nodes);
        init_sibling(head, n, nodes);
        //print_node(head);
        clone_node(head);
        init_clone_sibling(head);
        ListNode *clone = link_cloned_node(head);
        print_node(clone);
    }
    return 0;
}



