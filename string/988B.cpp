#include <iostream>
#include<vector> 

#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;
bool cmp(string& a ,string& b){return a.length()<b.length();}
int main() {
int n;
cin>>n;
vector<string> v(n);
for(int i=0;i<n;i++)
{
    cin>>v[i];
}
sort(v.begin(),v.end(),cmp);
for(int i=0;i<n-1;i++)
{
    if(v[i+1].find(v[i])==string::npos){cout<<"NO"<<endl; return 0;}
}
cout<<"YES"<<endl;
for(auto i:v) cout<<i<<endl;

}
