    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int start=0;
        int ans=0,prod=1;
        if(k<=1) return 0;
        for(int i=0;i<nums.size();i++)
        {
            prod=prod*nums[i];
            while(prod>=k)
            {
               prod/=nums[start];
                start++;
            }
            ans+=(i-start+1);
        }
        return ans;
    }
