class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp(s.length()+1,0);
        dp[s.length()]=1;
        for(int i=dp.size()-2;i>=0;i--){
            if(s[i]=='0') {dp[i]=0;continue;}
            dp[i]+=dp[i+1];
            if(i<s.length()-1 && (s[i]=='1'||(s[i]=='2' and s[i+1]<='6')))
                dp[i]+=dp[i+2];
                
        }
        return dp[0];
    }
};
