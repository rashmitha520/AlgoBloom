/*
Given an array of non-negative integers nums, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

 

Example 1:

Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
*/

//recursive
class Solution {
public:
    bool jump(int pos,vector<int>& nums)
    {
        if(pos==nums.size()-1) return true;
        int reach =nums.size()-1;
        if(pos+nums[pos]<nums.size()-1)
        reach = pos+nums[pos];
        for(int i=pos+1;i<=reach;i++)
        {
            if(jump(i,nums)) return 1;
        }
        return 0;
    }
    bool canJump(vector<int>& nums) {
      if(nums.size()==1) return 1;
        if(nums[0]==0) return 0;
        return jump(0,nums);
    }
};

//dp-memo
class Solution {
public:
    bool jump(int pos,vector<int>& nums,vector<int>& dp)
    {
        if(pos==nums.size()-1) return true;
        int reach =nums.size()-1;
        if(dp[pos]!=-1) return dp[pos];
        if(pos+nums[pos]<nums.size()-1)
        reach = pos+nums[pos];
        for(int i=pos+1;i<=reach;i++)
        {
            if(jump(i,nums,dp)) {dp[i]=true;return dp[i];}
        }
        dp[pos]=false;
        return 0;
    }
    bool canJump(vector<int>& nums) {
      if(nums.size()==1) return 1;
        if(nums[0]==0) return 0;
        vector<int> s(nums.size(),-1);
        return jump(0,nums,s);
    }
};
//dp
class Solution {
public:
   
    bool canJump(vector<int>& nums) {
      if(nums.size()==1) return 1;
        if(nums[0]==0) return 0;
        
       int n=nums.size();
         vector<int> s(nums.size(),INT_MAX);
        s[nums.size()-1]=0;
     for(int i=n-2;i>=0;i--)
     {
         int reach=(i+nums[i])>(n-1)?(n-1):i+nums[i];
         for(int j=i+1;j<=reach;j++)
         {
             if(s[j]==0){ s[i]=0;break;}
         }
     }
     return s[0]==0;
    }
};
