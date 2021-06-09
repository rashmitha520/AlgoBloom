//O(N)   
  int maxResult(vector<int>& nums, int k) {
        int n=nums.size();
        deque<int> q;//monotonic queue- puts best one first
        
        vector<int>dp(n);
        
        dp[n-1]=nums[n-1];
        q.push_back(n-1);
        
        for(int i=n-2;i>=0;i--)
        {
            if(q.front()-i>k) q.pop_front(); //popping element out of reach
            
            dp[i]=dp[q.front()]+nums[i];
            
            while(q.size() && dp[q.back()]<dp[i]) q.pop_back();
            
            q.push_back(i);
        }
        return dp[0];
    }

//O(N*k)-TLE
 int maxResult(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> dp(n,INT_MIN);
        dp[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--)
        {
            for(int j=i+1;j<min(n,i+k+1);j++)
            {
                dp[i]=max(dp[j]+nums[i],dp[i]);
            }
        }
        return dp[0];
    }
