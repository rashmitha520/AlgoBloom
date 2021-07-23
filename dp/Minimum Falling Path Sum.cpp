    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        int n=matrix.size();
        vector<int> dp=matrix[n-1],vp=matrix[n-1];
        
        if(n==1) return matrix[0][0];
        
        for(int i=n-2;i>=0;i--)
        {
            for(int j=0;j<n;j++)
            {
                //dp[j]=dp[j]+matrix[i][j];
                int ans=INT_MAX;
                ans=min(ans,vp[j]);
                if(j+1<n)
                    ans=min(ans,vp[j+1]);
                if(j-1>=0)
                    ans=min(ans,vp[j-1]);
                
                
                dp[j]=matrix[i][j]+ans;
                
            }
            vp=dp;
        }
        int mini=INT_MAX;
        for(int i=0;i<n;i++)
        {
           mini=min(dp[i],mini); 
        }
        return mini;
    }
