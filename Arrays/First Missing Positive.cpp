 int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
       vector<int> onetoN(n+1,0);
       onetoN[0]=1;
       for(int i=0;i<n;i++)
       {
           if(nums[i]>0 && nums[i]<=n)
               onetoN[nums[i]]=1;
       }
       for(int i=1;i<=n;i++)
       {
           if(onetoN[i]==0) return i;
       }
        return n+1;
    }
//constant space
  int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
       for(int i=0;i<n;i++)
       {
           while(nums[i]>0 && nums[i]<=n && nums[i]!=nums[nums[i]-1])
               swap(nums[i],nums[nums[i]-1]);
       }
       for(int i=0;i<n;i++)
       {
           if(nums[i]!=i+1) return i+1;
       }
        return n+1;
    }
