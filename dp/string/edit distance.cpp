 int minDis(string word1, string word2,int m,int n,vector<vector<int>>& dp)
    {
      int ans=0;
      if(n==0 ) return m;
      if(m==0) return n;
      if(dp[m][n]!=-1) return dp[m][n];
      if(word1[m-1]==word2[n-1])
           ans=minDis(word1,word2,m-1,n-1,dp);
      else{
          int replace = minDis(word1,word2,m-1,n-1,dp);
          int insert  = minDis(word1,word2,m,n-1,dp);
          int del     = minDis(word1,word2,m-1,n,dp);
          ans=1+min(replace,min(del,insert));}
      
        return dp[m][n]=ans;
    }
    int minDistance(string word1, string word2) {
      int n=word1.length(),m=word2.length();
           vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
       int ans=minDis(word1,word2,n,m,dp);
        return ans;
    }
//dp
