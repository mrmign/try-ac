/*
 * template.cpp
 * Copyright (C) 2014 Arming lee <cloudniw1@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#include<cstdio>
#include<stack>
#include<string>
#include<iostream>
using namespace std;
/*
 * 用两个栈实现一个队列
 */
/*int dequeue(stack<int> &s1, stack<int> &s2)
{
    if(s1.empty() && s2.empty())
        return -1;
    if(s1.empty()){
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }
    int p = s1.top();
    s1.pop();
    return p;
}
int main()
{
    string op;
    //char *op[10];
    int val = 0;
    int n;
    stack<int> s1, s2;
    while(scanf("%d", &n) != EOF){
        while(n--){
            //scanf("%s", &op);
            cin>>op;
            if(op == "PUSH"){
                cin>>val;
                //scanf("%d", &val);
                s2.push(val);
            }
            else if(op == "POP"){
                int v = dequeue(s1, s2);
                printf("%d\n",v);
            }
        }
        while(!s1.empty()){
            s1.pop();
        }
        while(!s2.empty()){
            s2.pop();
        }
    }
    return 0;
}*/

/*
 * 用两个队列实现栈
 */
#include<queue>
int pop_stack(queue<int> &q1, queue<int> &q2)
{
    if(q1.empty() && q2.empty())
        return -1;
    if(q1.empty()){
        while(q2.size() != 1){
            q1.push(q2.front());
            q2.pop();
        }
        int r = q2.front();
        q2.pop();
        return r;
    }
    else{
        while(q1.size() != 1){
            q2.push(q1.front());
            q1.pop();
        }
        int r = q1.front();
        q1.pop();
        return r;
    }
}

int main()
{
    string op;
    int n;
    int v;
    queue<int> q1, q2;
    scanf("%d", &n);
    while(n--){
        cin>>op;
        if(op == "PUSH"){
            scanf("%d", &v);
            if(q1.empty() && q2.empty() || q2.empty()){
                q1.push(v);
            }
            else if(q1.empty()){
                q2.push(v);

            }
        }
        else{
            printf("%d\n",pop_stack(q1, q2) );
        }
    }
    return 0;
}
