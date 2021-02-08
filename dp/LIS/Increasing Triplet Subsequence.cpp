/*Given an integer array nums, return true if there exists a triple of indices (i, j, k) such that i < j < k and nums[i] < nums[j] < nums[k]. If no such indices exists, return false.*/
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n=nums.size();
       vector<int> dp(n);
        dp[0]=1;int om=1;
        for(int i=1;i<n;i++)
        {
            int maxi=0;
            for(int j=0;j<n;j++)
            {
                if(nums[i]>nums[j])
                    if(dp[j]>maxi)
                        maxi=dp[j];
            }
            dp[i]=maxi+1;
            
        }
        for(int i=0;i<n;i++)
        {
            if(dp[i]>=3) return true;
        }
        return false;
    }
};
