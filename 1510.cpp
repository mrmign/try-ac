/*
 * 1510.cpp
 * Copyright (C) 2014 Arming lee <cloudniw1@gmail.com>
 *
 * Distributed under terms of the MIT license.
 * 用 %20 替换字符串的空格
 */
//#include<cstdio>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
int main()
{
    string s;
    //while(scanf("%s", &s) != EOF){
    while(getline(cin, s)){
        //replace(s.begin(), s.end(), " ", "%20");
       //printf("%s\n", s);
       //cout<<s<<endl;
       for(string::iterator it = s.begin(); it != s.end(); ++it)
           if(*it == ' ')
               cout<<"%20";
            else
                cout<<*it;
       cout<<endl;
    }
    return 0;

}


