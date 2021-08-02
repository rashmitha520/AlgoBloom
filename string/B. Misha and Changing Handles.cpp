#include <iostream>
#include<vector> 
#include<set>
#include<map>
#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;

int main() {
int n;
cin>>n;
vector<pair<string,string>> adj;

for(int i=0;i<n;i++)
{
  string s1,s2;
  cin>>s1>>s2;
  bool flag=0;
  for(int j=0;j<adj.size();j++)
  {
      if(adj[j].second==s1) {adj[j].second=s2;flag=1;break;}
  }
  if(flag==0)
  {
      adj.push_back({s1,s2});
  }
  
}
cout<<adj.size()<<endl;
for(auto i:adj)
{
    cout<<i.first<<" "<<i.second<<endl;
}

}
