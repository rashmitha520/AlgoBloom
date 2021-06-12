//TLE-Recursive  
int solve(vector<string>& strs,int st, int m, int n)
    {
        if(st==strs.size()) return 0;
        if(m==0 and n==0) return 0;
        int ans=0,curr=0;int zero=0,one=0;
        
         string s=strs[st];
          for(int j=0;j<s.length();j++)
          {
              if(s[j]=='0') zero++;
              else one++;
          }
         if(zero<=m and one<=n) curr++;
        
        int incl = curr + solve(strs,st+1,m-zero,n-one); //include current subset
        int non  =max(curr,solve(strs,st+1,m,n));//dont include
        ans=max(incl,non);//take max of both
        return ans;
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
       
        return solve(strs,0,m,n);
    }
//memoization
int dp[601][101][101];
    int solve(vector<string>& strs,int st, int m, int n)
    {
        if(st==strs.size()||m<0||n<0) return 0;
        if(m==0 and n==0) return 0;
        if(dp[st][m][n]!=-1) return dp[st][m][n];
        int ans=0,curr=0;int zero=0,one=0;
        
         string s=strs[st];
          for(int j=0;j<s.length();j++)
          {
              if(s[j]=='0') zero++;
              else one++;
          }
        
         if(zero<=m and one<=n) curr++;
        
        int incl;
        //if(m>=zero and n>=one)
        incl = curr + solve(strs,st+1,m-zero,n-one);
        int non  =solve(strs,st+1,m,n);
        ans=max(incl,non);
        return dp[st][m][n]=ans;
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
         memset(dp,-1,sizeof(dp));
        return solve(strs,0,m,n);
    }


//dp
 int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
       
        for(int i=0;i<strs.size();i++)
        {
             int zero=0,one=0;
            for(auto j:strs[i])
            {
                if(j=='0') zero++;
                else one++;
            }
        
        
        for(int i=m;i>=zero;i--)
        {
            for(int j=n;j>=one;j--)
            {
                dp[i][j]=max(dp[i][j],1+dp[i-zero][j-one]);
            }
        }
        }
        return dp[m][n];
    }
