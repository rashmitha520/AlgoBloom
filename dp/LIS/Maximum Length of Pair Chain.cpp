/*You are given n pairs of numbers. In every pair, the first number is always smaller than the second number.

Now, we define a pair (c, d) can follow another pair (a, b) if and only if b < c. Chain of pairs can be formed in this fashion.

Given a set of pairs, find the length longest chain which can be formed. You needn't use up all the given pairs. You can select pairs in any order.*/
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n=pairs.size();
        int omax=1;
        if(n==0) return 0;
        vector<int> dp(n);
        sort(pairs.begin(),pairs.end());
        dp[0]=1;
        for(int i=1;i<n;i++)
        {
            int maxi=0;
            for(int j=0;j<i;j++)
            {
                if(pairs[j][1]<pairs[i][0])
                {
                    if(dp[j]>maxi)
                        maxi=dp[j];
                }
            }
            dp[i]=maxi+1;
            omax=max(dp[i],omax);
        }
        return omax;
    }
};
