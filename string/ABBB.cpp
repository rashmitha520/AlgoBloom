/*
Zookeeper is playing a game. In this game, Zookeeper must use bombs to bomb a string that consists of letters 'A' and 'B'. He can use bombs to bomb a substring which is either "AB" or "BB". When he bombs such a substring, the substring gets deleted from the string and the remaining parts of the string get concatenated.

For example, Zookeeper can use two such operations: AABABBA →
→
 AABBA →
→
 AAA.

Zookeeper wonders what the shortest string he can make is. Can you help him find the length of the shortest string?*/
#include <iostream>
#include<vector> 

#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;

int main() {
int t;
cin>>t;
while(t--)
{   string s;
    cin>>s;
    int n=s.length();
    stack<int> st;
    for(int i=0;i<n;i++)
    {
        if(st.empty() or s[i]=='A')
         st.push(i);
        else st.pop();
       
    }
    cout<<st.size()<<endl;
    
}



}
