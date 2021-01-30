
//dp
int numDistinct(string s, string t) {
        int n=s.size(),m=t.size();
        vector<vector<long long>> dp(m+1,vector<long long>(n+1));
        for(int i=1;i<=n;i++)
        {
                if(s[i-1]==t[0])
                    dp[1][i]=dp[1][i-1]+1;
                else
                    dp[1][i]=dp[1][i-1];
           
        }
         for(int i=2;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(t[i-1]==s[j-1])
                    dp[i][j]=dp[i][j-1]+dp[i-1][j-1];
                else
                    dp[i][j]=dp[i][j-1];
            }
        }
        return dp[m][n];
    }
//better approach
    int numDistinct(string s, string t) {
        int m = t.length(), n = s.length();
        vector<vector<int>> dp(m + 1, vector<int> (n + 1, 0));
        for (int j = 0; j <= n; j++) dp[0][j] = 1;
        for (int j = 1; j <= n; j++)
            for (int i = 1; i <= m; i++)
                dp[i][j] = dp[i][j - 1] + (t[i - 1] == s[j - 1] ? dp[i - 1][j - 1] : 0);
        return dp[m][n];
    }
