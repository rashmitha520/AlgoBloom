#include<vector>
int lcs(string s1, string s2)
{
	//Write your code here
        int n=s1.length(),m=s2.length();
        vector< vector<int>> dp(n+1, vector<int>(m+1));
        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--)
            {
                
                if(s1[i]==s2[j])
                {
                    dp[i][j]=1+dp[i+1][j+1];
                    
                }
                else
                {
                    dp[i][j]=max(dp[i][j+1],dp[i+1][j]);
                }
            }
        }
        return dp[0][0];
}
