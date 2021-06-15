/*Given an integer array nums and an integer k, return true if it is possible to divide this array into k non-empty subsets whose sums are all equal.

 

Example 1:

Input: nums = [4,3,2,3,5,2,1], k = 4
Output: true
Explanation: It's possible to divide it into 4 subsets (5), (1, 4), (2,3), (2,3) with equal sums.
Example 2:

Input: nums = [1,2,3,4], k = 3
Output: false*/

bool solve(vector<int>& nums, int k,int s,vector<int> vis,int sum,int tar)
    {
        if(k==1) return true;
        if(tar==sum) return solve(nums,k-1,0,vis,0,tar);
        
        for(int i=s;i<nums.size();i++)
        {
            if(vis[i]==-1)
            {
               vis[i]=1;
               if(solve(nums,k,i+1,vis,sum+nums[i],tar)) return 1;
                vis[i]=-1;
            }
        }
        return 0;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
      int sum=0;
        for(int n:nums) sum+=n;
        int n=nums.size();
        if(sum%k!=0) return false;
        sort(nums.begin(),nums.end());
        if(nums[n-1]>sum/k) return 0;
        vector<int> vis(n,-1);
        return solve(nums,k,0,vis,0,sum/k);
    }
