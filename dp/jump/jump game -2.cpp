/*Given an array of non-negative integers nums, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

You can assume that you can always reach the last index.

 

Example 1:

Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.*/
//recursive - todo
//dp O(n*n)
class Solution {
public:
    int jump(vector<int>& nums) {
      int n=nums.size();
         vector<int> dp(nums.size(),INT_MAX);  
        dp[n-1]=0;
        for(int i=n-2;i>=0;i--)
        {    
            if(nums[i]==0) continue;
            else if(nums[i]>=n-i-1) dp[i]=1;
            else 
            {  int mini=INT_MAX;
                int reach=(i+nums[i])>(n-1)?(n-1):i+nums[i]; 
            for(int j=i+1;j<=reach;j++)
            {
                if(mini>dp[j]) mini=dp[j];
            }
             if(mini!=INT_MAX) dp[i]=mini+1;
             
            }
        }
        return dp[0];
    }
};
//O(N) soln
