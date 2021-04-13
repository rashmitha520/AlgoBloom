#include<iostream>
#include<bits/stdc++.h>
#include<climits>
#include<vector>
using namespace std;
int cost(vector<vector<int>>& v,int n,int m)
{
    vector<vector<int>> dp(n,vector<int>(m));
    for(int i=n-1;i>=0;i--)
    {
        for(int j=m-1;j>=0;j--)
         {  
            if(i==n-1 && j==m-1)
               dp[i][j]=v[i][j];
            else if(i==n-1)
               dp[i][j]=dp[i][j+1]+v[i][j];
            else if(j==m-1)
               dp[i][j]=dp[i+1][j]+v[i][j];
            else
             dp[i][j]=v[i][j]+min(dp[i+1][j],dp[i][j+1]);
             
             
         }
    }
    return dp[0][0];
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> arr(n,vector<int>(m,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
         {
             cin>>arr[i][j];
             
         }
    }
    
    cout<<cost(arr,n,m);
}
