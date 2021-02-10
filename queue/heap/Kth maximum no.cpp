class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> p;
       // int s=nums.size()-k+1;
        for(int i=0;i<nums.size();i++)
        {
            p.push(nums[i]);
            if(i>=nums.size()-k+1) p.pop();
        }
       // for(int i=0;i<k-1;i++)
         //   p.pop();
        return p.top();
    }
};
