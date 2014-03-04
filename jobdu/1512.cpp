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
int dequeue(stack<int> &s1, stack<int> &s2)
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
}



