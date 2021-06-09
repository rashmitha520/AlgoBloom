//O(N^2)
    int minCut(string s) {
        int n=s.length();
        vector<vector<bool>> dp(s.length(),vector<bool>(s.length(),false));
 //for true-false part.
    for(int g=0;g<s.length();g++)
       {  
      for(int i=0,j=g;j<s.length();i++,j++)
        {
            if(g==0) dp[i][j]=1;
            else if(g==1)
            {
                dp[i][j]=s[i]==s[j]?1:0;
            }
            else
            {
                if(s[i]==s[j] && dp[i+1][j-1]) dp[i][j]=1; 
            }
        }
    }
      
     vector<int> str(s.length());
        str[0]=0;
        for(int i=0;i<n;i++)
        { int mini=INT_MAX;
           if(dp[0][i]) {str[i]=0;continue;}
            for(int j=i;j>=1;j--)
            {
               
                if(dp[j][i])
                {
                    if(str[j-1]<mini) mini=str[j-1];
                }
            }
         str[i]=mini+1;
        }
        return str[n-1];
        
    }
