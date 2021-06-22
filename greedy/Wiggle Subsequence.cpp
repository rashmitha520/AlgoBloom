    
/*A wiggle sequence is a sequence where the differences between successive numbers strictly alternate between positive and negative. The first difference (if one exists) may be either positive or negative. A sequence with one element and a sequence with two non-equal elements are trivially wiggle sequences.

For example, [1, 7, 4, 9, 2, 5] is a wiggle sequence because the differences (6, -3, 5, -7, 3) alternate between positive and negative.
In contrast, [1, 4, 7, 2, 5] and [1, 7, 4, 5, 5] are not wiggle sequences. The first is not because its first two differences are positive, and the second is not because its last difference is zero.
A subsequence is obtained by deleting some elements (possibly zero) from the original sequence, leaving the remaining elements in their original order.

Given an integer array nums, return the length of the longest wiggle subsequence of nums.*/
int wiggleMaxLength(vector<int>& nums) {
        if(nums.size()<2) return nums.size();
        int prev=nums[1]-nums[0];
        int count=(prev!=0)?2:1;
        
        for(int i=2;i<nums.size();i++)
        {
            int diff=nums[i]-nums[i-1];
            if(diff>0 && prev<=0||diff<0 && prev>=0)
            {
                count++;
                
                prev=diff;
            }
        }
        return count;
    }
