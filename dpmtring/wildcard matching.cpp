 bool isMatch(string s, string p) {
        vector<vector<bool>> dp(p.length()+1,vector<bool>(s.length()+1,0));
        int r=p.length()+1,c=s.length()+1;
        for(int i=r-1;i>=0;i--)
        {
            for(int j=c-1;j>=0;j--)
            {
                if(i==r-1 and j==c-1) dp[i][j]=true;
                else if(i==r-1)
                {
                    dp[i][j]=false;
                }
                else if(j==c-1)
                {
                    if(p[i]=='*') dp[i][j]=dp[i+1][j];
                    
                }
                else
                {
                    if(p[i]==s[j]||p[i]=='?') dp[i][j]=dp[i+1][j+1];
                    else if(p[i]=='*') dp[i][j]=dp[i+1][j]||dp[i][j+1];
                    
                }
            }
        }
        return dp[0][0];
    }
