#include<bits/stdc++.h>
#include<vector>
using namespace std;
int profit(vector<int>& v,int n)
{ int maxpro=INT_MIN;
    for(int i=0;i<n;i++)
    {
        int cur=v[i];
        for(int j=i+1;j<n;j++)
        {
           if(v[j]>=v[i])
            maxpro=max(maxpro,v[j]-v[i]);
        }
    }
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
