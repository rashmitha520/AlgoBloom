#include <iostream>
#include<vector> 

#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;

int main() {
int n,m;
cin>>n>>m;
set<string> dict; vector<string> words,left,right;
for(int i=0;i<n;i++)
{
    string k;
    cin>>k;
    words.push_back(k);
    dict.insert(k);
}
string mid;

for(int i=0;i<n;i++)
{
    string rev=words[i];
    reverse(rev.begin(),rev.end());
    if(rev==words[i])
    {
        mid=rev;
    }
    else if(dict.find(rev)!=dict.end())
    {
        left.push_back(words[i]);
        right.push_back(rev);
        dict.erase(rev);dict.erase(words[i]);
    }
}

cout<<left.size()*m*2+mid.length()<<endl;
for(auto i:left) cout<<i;
cout<<mid;
reverse(right.begin(),right.end());//we reversebecause first checked ones are first for right and left 1234321 : order of striings
for(auto i:right) cout<<i;



}
