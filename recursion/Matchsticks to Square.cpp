    bool solve(vector<int>& nums,int tar,int sum,int s,vector<int> vis,int k)
    {
        if(k==1) return true;
        if(tar==sum) return solve(nums,tar,0,0,vis,k-1);
        for(int i=s;i<nums.size();i++)
        {
            if(vis[i]==-1)
            {
                vis[i]=1;
                if(solve(nums,tar,sum+nums[i],i+1,vis,k)) return 1;
                vis[i]=-1;
            }
        }
        return false;
    }
    bool makesquare(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int sum=0;
        for(int i:nums) sum+=i;
        if(sum%4!=0 or nums[n-1]>sum/4) return false;
        vector<int> vis(n,-1);
        return solve(nums,sum/4,0,0,vis,4);
    }
