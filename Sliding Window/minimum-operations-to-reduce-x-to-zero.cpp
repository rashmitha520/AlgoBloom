    int minOperations(vector<int>& nums, int x) {
        int remSum =-x;
        for(int i:nums) remSum+=i;
        if(remSum==0) return nums.size();
        
        int ans=INT_MIN,sum=0;
        map<int,int> m;
        m[0]=-1;
        
        for(int i=0;i<nums.size();i++) //maximum subarray with remSum as its total sum
        {
            sum+=nums[i];
            if(m.find(sum-remSum)!=m.end())
                ans=max(ans,i-m[sum-remSum]);
            m[sum]=i;
        }
        
        return ans==INT_MIN?-1:nums.size()-ans;
    }
