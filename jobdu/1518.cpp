/*
 * template.cpp
 * Copyright (C) 2014 Arming lee <cloudniw1@gmail.com>
 *
 * Distributed under terms of the MIT license.
 *
 * 反转链表
 *
 */

#include<cstdio>

struct ListNode{
    int value;
    ListNode *next;
    ListNode(int val):value(val), next(NULL){};
};
ListNode * initList(int n);
ListNode* reverseList(ListNode *head);
int main()
{
    int n;
    ListNode *head = NULL;
    ListNode *tail = NULL;
    while(scanf("%d", &n) != EOF){
       head = initList(n); 
       tail = reverseList(head);
       if(tail == NULL)
           printf("NULL\n");
       else{
           while(tail->next){
               printf("%d ",tail->value );
               tail = tail->next;
           }
           printf("%d\n", tail->value);
       }
    }
    return 0;
}


ListNode * initList(int n)
{
    if(n == 0)
        return NULL;
    ListNode *head = NULL;
    ListNode *p;
    int val;
    while(n--){
        scanf("%d", &val);
        ListNode* l = new ListNode(val);
        if(head == NULL){
            head = l;
            p = head;
            //continue;
        }
        else{
            p->next = l;
            p = l;
        }
    }    
    return head;
}
ListNode *reverseList(ListNode *head)
{
   if(head == NULL)
       return NULL;
   ListNode *tail, *p; 
   p = head;
   while(p->next != NULL) {
       p = p->next;
   }
   tail = p;
   tail->next = head;
   while(head->next != tail){
       p = head->next;
       head->next = p->next;
       p->next = tail->next;
       tail->next = p;
   }
   head->next = NULL;
   return tail;
}

