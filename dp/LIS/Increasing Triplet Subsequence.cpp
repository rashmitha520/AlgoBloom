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
//BETTER APPROACH NOT ORIGINAL
bool increasingTriplet(vector<int>& nums) {
    int c1 = INT_MAX, c2 = INT_MAX;
    for (int x : nums) {
        if (x <= c1) {
            c1 = x;           // c1 is min seen so far (it's a candidate for 1st element)
        } else if (x <= c2) { // here when x > c1, i.e. x might be either c2 or c3
            c2 = x;           // x is better than the current c2, store it
        } else {              // here when we have/had c1 < c2 already and x > c2
            return true;      // the increasing subsequence of 3 elements exists
        }
    }
    return false;
}
