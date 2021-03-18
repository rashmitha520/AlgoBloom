class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int a=0,b=0;
      //as a^a=0, so the missing no will be the odd one and rest be 0.
       for(int i=0;i<=nums.size();i++)
           a=a^i;
    for(int i=0;i<nums.size();i++)
           b=b^nums[i];
        
        return a^b;
        
    }
};
