class Solution {
public:
    int solve(vector<int>& nums,int s,int e)
    { 
     int n=nums.size();
     //if one element only return the same
     if(s==e) return nums[s];
     
     vector<int> dp(n);
    
     dp[s]=nums[s];
     dp[s+1]=max(dp[s],nums[s+1]);
     
     for(int i=s+2;i<=e;i++)
     {
       dp[i]=max(dp[i-1],dp[i-2]+nums[i]);  
     }
       return dp[e]; 
    }
    int rob(vector<int>& nums) {
      int n=nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];
        //include last or first 
        return max(solve(nums,0,n-2),solve(nums,1,n-1));
    }
};
