int numberOfSubarrays(vector<int>& nums, int k) {
        map<int,int> m;
        m[0]=1;
        int res=0,sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i]%2;
            res+=m[sum-k];
            m[sum]++;
            
        }
        return res;
    }
//same as count subarrays with sum=k
