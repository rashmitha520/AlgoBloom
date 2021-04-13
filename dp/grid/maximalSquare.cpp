
/*Given an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.*/
class Solution {
public:
    int maximalSquare(vector<vector<char>>& arr) {
        int n=arr.size();int m=arr[0].size();
     vector<vector<int>> dp(n,vector<int>(m,0));int ans=0;
       
    for(int i=n-1;i>=0;i--)
    {
        for(int j=m-1;j>=0;j--)
        {
            if(i==n-1 || j==m-1)
            {dp[i][j]=arr[i][j]-'0';
             if(ans<dp[i][j])
                ans=dp[i][j];}
           
            else{
                if(arr[i][j]=='0')
                    dp[i][j]=0;
                else
                {
                    int mini=min(dp[i+1][j],min(dp[i+1][j+1],dp[i][j+1]));
                    dp[i][j]=mini+1;
                    if(ans<dp[i][j])
                        ans=dp[i][j];
                }
            }
        }
    }
    return ans*ans;  
    }
};
