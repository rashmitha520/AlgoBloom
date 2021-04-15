#include<bits/stdc++.h>
#include<vector>
#include<iostream>
using namespace std;
int knapsack(vector<int>& w,vector<int>& v,int cap)
{
    int n=w.size(),m=cap;
     vector<int> dp(m+1); dp[0]=0;
     for(int i=1;i<=m;i++)
    { int maxi=0;
        for(int j=0;j<n;j++)
        {
         if(w[j]<=i)
         {
             int rem = i-w[j];
             int val = dp[rem];
             int cur = v[j]+val;
             maxi=max(cur,maxi);
         }
        }
        dp[i]=maxi;
    }
    return dp[cap];
    
}
int main()
{
    int n;
    cin>>n;
    vector<int> w(n),v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>w[i];
    }
    int cap;
    cin>>cap;
    cout<<knapsack(w,v,cap);
}
