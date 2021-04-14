/*
1. You are given a number n, representing the number of days.
2. You are given n numbers, where ith number represents price of stock on ith day.
3. You are required to print the maximum profit you can make if you are allowed infinite transactions, but have to cooldown for 1 day after 1 transaction
i.e. you cannot buy on the next day after you sell, you have to cooldown for a day at-least before buying again.
Note - There can be no overlapping transaction. One transaction needs to be closed (a buy followed by a sell) before opening another transaction (another buy).
*/
#include<bits/stdc++.h>
#include<vector>
using namespace std;
int profit(vector<int>& v,int n)
{ int bsp=-v[0],ssp=0,csp=0;
    for(int i=0;i<n;i++)
    {
       bsp=max(bsp,csp-v[i]);
       csp=max(ssp,csp);
       ssp=max(ssp,v[i]+bsp);
       
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
  // cin>>k;
   cout<<profit(v,n);
}
