    int longestOnes(vector<int>& nums, int k) {
       int maxi=INT_MIN,start=0,zero=0;
        for(int end=0;end<nums.size();end++)
        {
            if(nums[end]==0) zero++;
            while(zero>k)
            {
                if(nums[start]==0) zero--;
                start++;
            }
            maxi=max(end-start+1,maxi);
        }
        return maxi;
    }
