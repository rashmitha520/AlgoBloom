    int dp[1000][1000];
    int solve(vector<int>& nums,vector<int>& multipliers,int s,int e,int idx)
    {
        if(idx==multipliers.size()) return 0;
        if(dp[s][idx]!=-1) return dp[s][idx];
        int first=multipliers[idx]*nums[s]+solve(nums,multipliers,s+1,e,idx+1);
        int second=multipliers[idx]*nums[e]+solve(nums,multipliers,s,e-1,idx+1);
        
        return dp[s][idx]=max(first,second);
    }
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
     
        memset(dp,-1,sizeof(dp));
       return solve(nums,multipliers,0,nums.size()-1,0); 
    }
