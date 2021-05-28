int numSquares(int n) {
        vector<int> dp(n+1);
        for(int i=0;i<=n;i++) 
		        dp[i]=i; //maximum times a number can be added is with 1s E.g 4=1+1+1+1
        
		for(int i=1;i<=n;i++)
            for(int j=1;j*j<=i;j++)  // We know that squares dealt will be equal or less than the number
            {
                dp[i]=min(dp[i-j*j]+1,dp[i]); // update the minimum no of steps 
            }
        
        
        return dp[n];
    }
