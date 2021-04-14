#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#include<climits>
using namespace std;
int dig(vector<vector<int>>& nums,int n,int m)
{
    vector<vector<int>> dp(n,vector<int>(m,0));
    
   
    
    for(int i=n-1;i>=0;i--)
    {
        for(int j=m-1;j>=0;j--)
        {
         if(j==m-1){
             dp[i][j]=nums[i][j];
         }
         else if(i==0)
         {
             dp[i][j]=nums[i][j]+max(dp[i+1][j+1],dp[i][j+1]);
         }
         else if(i==n-1)
         {
             dp[i][j]=nums[i][j]+max(dp[i-1][j+1],dp[i][j+1]);
             
         }
         else
         {
             dp[i][j]=nums[i][j]+max(dp[i][j+1],max(dp[i-1][j],dp[i+1][j+1]));
         }
         
         
        }
    }
    int mix=dp[0][0];
    for(int i=1;i<n;i++)
    mix=max(dp[i][0],mix);
    return mix;
}
int main()
{
    int n,m;
  vector<vector<int>> arr(n,vector<int>(m,0));
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
         cin>>arr[i][j];
    }
    cout<<dig(arr,n,m);
}
