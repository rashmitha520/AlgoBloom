    int numSubarraysWithSum(vector<int>& nums, int goal) {
        map<int,int> m; m[0]=1;int sum=0,count=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            count+=m[sum-goal];
            m[sum]++;
        }
        return count;
    }
