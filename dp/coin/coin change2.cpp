 int change(int amount, vector<int>& coins) {
     vector<vector<int>> dp(amount+1,vector<int>(coins.size()+1,-1));
       
        for(int i=0;i<=coins.size();i++) 
            dp[0][i]=1;
        
        for(int i=0;i<=amount;i++) 
            dp[i][0]=0;
        
        int n=amount+1,m=coins.size()+1;
        for(int i=1;i<=amount;i++)
        {
            for(int j=1;j<=coins.size();j++)
            {
                if(coins[j-1]<=i)
                {
                    dp[i][j]=dp[i][j-1]+dp[i-coins[j-1]][j];
                }
                else
                {
                    dp[i][j]=dp[i][j-1];
                }
            }
        }
        return dp[n-1][m-1];
    }
