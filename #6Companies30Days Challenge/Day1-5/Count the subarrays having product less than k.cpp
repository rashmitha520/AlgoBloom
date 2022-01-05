class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
      int ans=0,prod=1,start=0;
        if(k<=1) return 0;
      for(int i=0;i<nums.size();i++){
          prod=prod*nums[i];
          while(prod>=k){
              prod=prod/nums[start];
              start++;
          }
          ans=ans+i-start+1;
      }
     return ans; 
    }
};
