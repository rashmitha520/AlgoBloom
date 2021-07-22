 int partitionDisjoint(vector<int>& nums) {
        int n=nums.size();int ans=nums[0];
        vector<int> left(n),right(n);
        for(int i=0;i<n;i++)
        {
            ans=max(nums[i],ans);
            left[i]=ans;
        }
        ans=nums[n-1];
        for(int i=n-1;i>=0;i--)
        {
            ans=min(nums[i],ans);
            right[i]=ans;
          //  if(left[i]<=right[i]) return i-1;
        }
        for(int i=1;i<n;i++)
            if(left[i-1]<=right[i]) return i;
        return 0;
    }
