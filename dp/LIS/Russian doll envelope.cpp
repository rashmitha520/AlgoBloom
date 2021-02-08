/*You have a number of envelopes with widths and heights given as a pair of integers (w, h). One envelope can fit into another if and only if both the width and height of one envelope is greater than the width and height of the other envelope.

What is the maximum number of envelopes can you Russian doll? (put one inside other)

Note:
Rotation is not allowed.*/

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& e) {
       int n=e.size();
        if(n==0) return 0;
       sort(e.begin(), e.end());
       //max no of envelopes as of now
       int omax=1;
        vector<int> dp(n);dp[0]=1;
        for(int i=1;i<n;i++)
        {
            int maxi=0;
            for(int j=0;j<i;j++)
            { //to ensure both height and width are more than the next.
                if(e[j][0]<e[i][0] && e[j][1]<e[i][1])
                    if(dp[j]>maxi) //if env. more than prev maxi
                        maxi=dp[j];
            }
            dp[i]=maxi+1;
            //store the maximum no of russian doll envelopes.
            omax=max(dp[i],omax);
               
        }
     return omax;   
    }
};
