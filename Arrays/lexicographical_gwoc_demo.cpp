#include <iostream>
#include<string>
#include<bits/stdc++.h>

using namespace std;
int main() {
   int n;
   cin>>n;
   vector<string> s1,s2;
   while(n--)
   { string s;int k;
   cin>>s>>k;
   s=s+to_string(k);
       s1.push_back(s);
        s2.push_back(s);
   }
   sort(s2.begin(),s2.end());
   for(int i=0;i<s1.size();i++)
   {
       string l=s1[i];
       for(int j=0;j<s2.size();j++)
       {
           if(l==s2[j])
             {cout<<j+1<<endl;break;}
       }
   }
}
