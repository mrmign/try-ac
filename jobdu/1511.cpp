/*
 * 1510.cpp
 * Copyright (C) 2014 Arming lee <cloudniw1@gmail.com>
 *
 * Distributed under terms of the MIT license.
 * 
 * 从尾到头打印链表
 *
 * */

//#include<iostream>
// 用cin, cout 又一次超时
#include<stack>
#include<cstdio>
using namespace std;
/*int main()
{
    stack<int> st;
    int input;
    //while(cin>>input){
    while(scanf("%d", &input) != EOF){
        if(input != -1)
            st.push(input);
        else
            break;
    }
    while(!st.empty()){
        //cout<< st.top()<<endl;
        printf("%d\n", st.top());
        st.pop();
    }
    return 0;

}*/

struct ListNode{
    int value;
    ListNode *next;
};
void printList(ListNode *head);
int main()
{
    ListNode header;
    ListNode *p = &header;
    int in(0);
    while(scanf("%d", &in) != EOF && in != -1){
        ListNode *ln = new ListNode;
        ln->value = in;
        ln->next = NULL;
        p->next = ln;
        p = ln;
    }
    printList(header.next);
    return 0;
}
void printList(ListNode *head)
{
    if(head != NULL){
        if(head->next != NULL)
            printList(head->next);
        printf("%d\n", head->value);
        delete head;
    }
}
