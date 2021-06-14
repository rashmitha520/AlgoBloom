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


//2nd method
  bool canArrange(vector<int>& nums, int k) {
       map<int,int> m;
        for(int num:nums)
        {  
            int rem=num%k;
            if(rem<0) rem+=k;
            m[rem]++;
        }
        if(m[0]%2==1) return false;
        for(int i=1;i<=k/2;i++)
        {
            if(m[i]!=m[k-i]) return false;
        }
        return true;
    }
