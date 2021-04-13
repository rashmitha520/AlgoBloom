class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp(n,0);
        dp[0]=cost[0],dp[1]=cost[1];
        for(int i=2;i<n;i++)
        {
            dp[i]=cost[i]+min(dp[i-1],dp[i-2]);
        }
        return min(dp[n-2],dp[n-1]);
    }
};

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        int f=0,s=0;
        //vector<int> dp(n,0);
       // dp[0]=cost[0],dp[1]=cost[1];
        for(int i=n-1;i>=0;i--)
        {
           // dp[i]=cost[i]+min(dp[i-1],dp[i-2]);
            int co=cost[i]+min(f,s);
            f=s;
            s=co;
        }
        return min(f,s);
    }
};
