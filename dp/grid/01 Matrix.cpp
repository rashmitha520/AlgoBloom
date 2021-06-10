  vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
     int r=mat.size();
     int c=mat[0].size();
     vector<vector<int>> dp(r,vector<int>(c,INT_MAX-100000));
     for(int i=0;i<r;i++)
     {
         for(int j=0;j<c;j++)
         {
             if(mat[i][j]==0) dp[i][j]=0;
             else
             {
                 if(i>0) dp[i][j]=min(dp[i-1][j]+1,dp[i][j]);
                 if(j>0) dp[i][j]=min(dp[i][j-1]+1,dp[i][j]);
             }
         }
     }
    
      for(int i=r-1;i>=0;i--)
     {
         for(int j=c-1;j>=0;j--)
         {
             if(mat[i][j]==0) dp[i][j]=0;
             else
             {
                 if(i<r-1) dp[i][j]=min(dp[i+1][j]+1,dp[i][j]);
                 if(j<c-1) dp[i][j]=min(dp[i][j+1]+1,dp[i][j]);
             }
         }
     }
        return dp;
        
    }
