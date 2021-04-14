#include<bits/stdc++.h>
#include<vector>
using namespace std;
int profit(vector<int>& v,int n)
{ int maxpro=0,buy=0,sell=0;
    for(int i=1;i<n;i++)
    {
        if(v[i]>=v[i-1]) sell++;
        else
        {
            maxpro+=(v[sell]-v[buy]);
            sell=buy=i;
        }
    }
    maxpro+=(v[sell]-v[buy]);
    return maxpro;
}
int main()
{
  int n;
  cin>>n;
  vector<int> v(n);
  for(int i=0;i<n;i++)
   cin>>v[i];
   
   cout<<profit(v,n);
}
