  bool canArrange(vector<int>& nums, int k) {
      unordered_map<int,int> m;
        int count=0,n=nums.size();
     
        /*
        For pairs to be divisible : 
        (nums[i]+nums[j])%k=0
        i.e. nums[i]%k = -nums[j]%k
        if re=(nums[i]%k+k)%k because to make positive
        then -nums[j]%k = (k-re)%k
        */
        for(int num:nums)
        { 
          int re=(num%k+k)%k;
           int key=(k-re)%k;
          if(m[key]>0)
          {
              
              m[key]--;
              count++;
          }
         else
         {
             m[re]++;
         }
        }
        return count==n/2;
    }
