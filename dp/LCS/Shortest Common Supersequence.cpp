 string shortestCommonSupersequence(string str1, string str2) {
        //finding lcs
        vector<vector<int>> dp(str1.length()+1,vector<int>(str2.length()+1,0));
        for(int i=1;i<=str1.length();i++)
        {
            for(int j=1;j<=str2.length();j++)
            {
                if(i>0 && j>0 && str1[i-1]==str2[j-1])
                {
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else
                {
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
                
                    
            }
        }
        int i=str1.length(),j=str2.length(); string res="";
        while(i>0 && j>0)
        {
            if(str1[i-1]==str2[j-1])
            {
                res+=str1[i-1];
                i--;j--;
            }
            else
            {
                if(dp[i-1][j]>dp[i][j-1])
                   { res+=str1[i-1];i--;cout<<res<<" ";}
                else
                    {res+=str2[j-1];j--;cout<<res<<" ";}
            }
        }
        while(i>0)
        {
           res+=str1[i-1] ; i--; 
        }
         while(j>0)
        {
            res+=str2[j-1];j--;
        }
        reverse(res.begin(),res.end());
        return res;
        
    }
