#include<bits/stdc++.h>
#include<vector>
using namespace std;
int profit(vector<int>& v,int n,int k)
{ int bsp=-v[0],ssp=0;
    for(int i=0;i<n;i++)
    {
       bsp=max(bsp,ssp-v[i]);
       ssp=max(ssp,v[i]+bsp-k);
    }
    return ssp;
}
int main()
{
  int n,k;
  cin>>n;
  vector<int> v(n);
  for(int i=0;i<n;i++)
   cin>>v[i];
   cin>>k;
   cout<<profit(v,n,k);
}
