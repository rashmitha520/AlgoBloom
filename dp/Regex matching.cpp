    //doubt for stars
    bool isMatch(string s, string p) {
        vector<vector<bool>> dp(p.length()+1,vector<bool>(s.length()+1));
        for(int i=0;i<dp.size();i++)
        {
            for(int j=0;j<dp[0].size();j++)
            {
                if(i==0 and j==0) dp[i][j]=1; // '-' and '-'
                else if(j==0)
                {
                    if(p[i-1]=='*') dp[i][j]=dp[i-2][j];
                    else dp[i][j]=0;
                }
                else if(i==0) dp[i][j]=0;
                else
                {
                    if(p[i-1]=='*') //doubt
                        {
                        dp[i][j]=dp[i-2][j];
                        if(p[i-2]==s[j-1]||p[i-2]=='.')
                        dp[i][j]=dp[i][j-1]||dp[i][j];
                    }
                    else if(p[i-1]=='.'||p[i-1]==s[j-1]) 
                        dp[i][j]=dp[i-1][j-1];
                    else
                        dp[i][j]=0;
                        
                }
            }
            
        }
        return dp[dp.size()-1][dp[0].size()-1];
            
    }
