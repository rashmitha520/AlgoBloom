/*
Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1.

Example 1:

Input: [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with equal number of 0 and 1.
*/
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
      map<int,int> m;
        m[0]=-1;int k=0;
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
            {
                sum-=1;
            }
            if(nums[i]==1)
                sum+=1;
            if(m.find(sum)!=m.end())
            {
             k= max(k,i-m[sum] );
            }
            else
            {
                m[sum]=i;
            }
        }
        return k;
    }
};
