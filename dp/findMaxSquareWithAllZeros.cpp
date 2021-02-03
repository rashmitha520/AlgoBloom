
int findMaxSquareWithAllZeros(int **arr, int n, int m)
{
	//Write your code here
    int dp[n][m];int ans=0;
    for(int i=n-1;i>=0;i--)
    {
        for(int j=m-1;j>=0;j--)
        {
            if(i==n-1 || j==m-1)
            { dp[i][j]= (arr[i][j]==0)?1:0;
                 if(ans<dp[i][j])
                   ans=dp[i][j];
            }
          
            else{
                if(arr[i][j]==1)
                    dp[i][j]=0;
                
                else{ int mini=min(dp[i+1][j],min(dp[i+1][j+1],dp[i][j+1]));
                    dp[i][j]=mini+1;
                    if(ans<dp[i][j])
                        ans=dp[i][j];}
                
            }
        }
    }
    return ans;
}
