   
// get subsequences and choose max
long long solve(vector<vector<long long int>>& dp,long long idx,vector<int>& nums,int flag)
    {
        if(idx>=nums.size()) return 0;
        if(dp[idx][flag]!=-1) return dp[idx][flag];
        long long non_incl = solve(dp,idx+1,nums,flag);//donot include
        long long incl = 0;
        if(flag==0)
            incl+=nums[idx];
        else
            incl-=nums[idx];
        incl+=solve(dp,idx+1,nums,1-flag);//include and add or subtract depending on turns
        return dp[idx][flag]=max(incl,non_incl);
    }
    long long maxAlternatingSum(vector<int>& nums) {
        vector<vector<long long>> dp(100001,vector<long long>(2,-1));
        long long flag=0;
        return solve(dp,0,nums,flag);
    }
