   int ans=0;
   void find(vector<int>& nums, int k,int s)
    {  
        if(s==nums.size()) 
        {
            if(k==0) 
                ans++;
           
            return ;
        }
        else{
              find(nums,k-nums[s],s+1);
              find(nums,k+nums[s],s+1);
            }
    
        
        
    }
    int findTargetSumWays(vector<int>& nums, int k) {
        int n=nums.size(); 
        find(nums,k,0);
        return ans;
    }
