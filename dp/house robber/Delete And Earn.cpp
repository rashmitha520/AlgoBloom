class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int> sum(10001),dp(nums.size());
        for(int i:nums){
            sum[i]+=i;
        }
     
        for(int i=2;i<10001;i++){
            sum[i]=max(sum[i]+sum[i-2],sum[i-1]);
        }
        return sum[10000];
    }
};
