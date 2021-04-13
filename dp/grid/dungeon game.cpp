class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n=dungeon.size();int m=dungeon[0].size();
        vector<vector<int>> dp(n,vector<int> (m));
        //base case
        dp[n-1][m-1]=(dungeon[n-1][m-1]>0)?1:1-dungeon[n-1][m-1];
        
        for(int i=n-2;i>=0;i--)
            dp[i][m-1]=max(1,dp[i+1][m-1]-dungeon[i][m-1]);
        
        for(int i=m-2;i>=0;i--)
            dp[n-1][i]=max(1,dp[n-1][i+1]-dungeon[n-1][i]);
        
        for(int i=n-2;i>=0;i--)
        {
            for(int j=m-2;j>=0;j--)
                dp[i][j]=max(1,min(dp[i+1][j]-dungeon[i][j],dp[i][j+1]-dungeon[i][j]));
        }
        return dp[0][0];
        
    }
