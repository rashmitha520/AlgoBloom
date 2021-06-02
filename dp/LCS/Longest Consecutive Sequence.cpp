  int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> dp;
        int ans=0;
       
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
        {
            if(dp[nums[i]-1]!=0) 
                dp[nums[i]]=dp[nums[i]-1]+1;
            else
             dp[nums[i]]=1;
            ans=max(ans,dp[nums[i]]);
        }
        return ans;
    }
