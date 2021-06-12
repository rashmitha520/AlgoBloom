  
//memoization
  int solve(int sum,int left,int right,vector<vector<int>>& dp,vector<int>& stones)
    {
        if(left==right) return 0;
        if(right-left==1) return max(stones[left],stones[right]);
        if(dp[left][right]!=-1) return dp[left][right];
        
        int ans=max(sum-stones[left]-solve(sum-stones[left],left+1,right,dp,stones),sum-stones[right]-solve(sum-stones[right],left,right-1,dp,stones));
        return dp[left][right]=ans;
    }
    int stoneGameVII(vector<int>& stones) {
        int sum=0;vector<vector<int>> dp(stones.size(),vector<int>(stones.size(),-1));
        for(auto i:stones) sum+=i;
        
        return solve(sum,0,stones.size()-1,dp,stones);
    }

//dp
class Solution {
public:
    int stoneGameVII(vector<int>& stones) {
        vector<int> sum(stones.size()+1);
        for(int i=0;i<stones.size();i++)
        {
            sum[i+1]=sum[i]+stones[i];
        }
        
        vector<vector<int>> dp(stones.size(),vector<int>(stones.size()));
        for(int l=2;l<=dp.size();l++)
        {
            for(int i=0;i<=dp[0].size()-l;i++)
            {      int j=i+l-1;
                dp[i][j]=max(sum[j+1]-sum[i+1]-dp[i+1][j],sum[j]-sum[i]-dp[i][j-1]);
            }
        }
        return dp[0][dp.size()-1];
    }
};
