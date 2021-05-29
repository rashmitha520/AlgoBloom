//recursion
int lcs(string& str,int s,int e)
    { int ans=0;
        if(s>e) return 0;
        if(s==e) return 1;
        if(str[s]==str[e])
            ans=2+lcs(str,s+1,e-1);//c1=c2
        else 
            ans = max(lcs(str,s+1,e),lcs(str,s,e-1));//c1 != c2
      return ans;
     
            
    }
    int longestPalindromeSubseq(string s) {
        if(s.length()==0) return 0;
        return lcs(s,0,s.length()-1);
    }

//memoization
int lcs(string& str,int s,int e,vector<vector<int>>& dp)
    { int ans=0;
        if(s>e) return 0;
        if(s==e) return 1;
       if(dp[s][e]!=-1) return dp[s][e];
        if(str[s]==str[e])
            ans=2+lcs(str,s+1,e-1,dp);
        else 
            ans = max(lcs(str,s+1,e,dp),lcs(str,s,e-1,dp));
      return dp[s][e]=ans;
     
            
    }
    int longestPalindromeSubseq(string s) {
        if(s.length()==0) return 0;
        vector<vector<int>> dp(s.length(),vector<int>(s.length(),-1));
        return lcs(s,0,s.length()-1,dp);
    }
//dp
 int longestPalindromeSubseq(string s) {
       //lcs approach
        int n=s.length();
        string st=s;
        reverse(st.begin(),st.end());
        string t =st;
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(s[i-1]==t[j-1]) 
                  dp[i][j]=1+dp[i-1][j-1];
                else 
                  dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n][n];
    }
