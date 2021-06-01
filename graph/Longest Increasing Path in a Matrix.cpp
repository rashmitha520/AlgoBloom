    int dfs(vector<vector<int>>& matrix,int i,int j,int cur,vector<vector<int>>& dp)
    {
        if(i<0||j<0||i>=matrix.size()||j>=matrix[0].size()||matrix[i][j]==-1||matrix[i][j]<=cur)
            return 0;
        cur=matrix[i][j];
       // matrix[i][j]=-1;
        if(dp[i][j]!=-1) return dp[i][j];
        int u=dfs(matrix,i-1,j,cur,dp);
        int d=dfs(matrix,i+1,j,cur,dp);
        int l=dfs(matrix,i,j-1,cur,dp);
        int r=dfs(matrix,i,j+1,cur,dp);
        return dp[i][j]=1+max(max(u,d),max(l,r));
            
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                ans=max(dfs(matrix,i,j,INT_MIN,dp),ans);
            }
        }
        return ans;
    }
