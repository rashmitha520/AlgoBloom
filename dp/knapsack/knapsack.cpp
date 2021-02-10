#include<vector>
int knapsack(int* w, int* v, int n, int m) {
	// Write your code here
   vector<vector<int>> dp(n+1,vector<int>(m+1,0));
   
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(j>=w[i-1])
            {
                dp[i][j]=max(dp[i-1][j],v[i-1]+dp[i-1][j-w[i-1]]);
            }
            else
                dp[i][j]=dp[i-1][j];
        }
    }
    return dp[n][m];
}
