class Solution {
public:
    int countSubstrings(string s) {
        int c=0;
        vector<vector<bool>> dp(s.length(),vector<bool>(s.length(),0));
        for(int gap=0;gap<s.length();gap++)
        {
            for(int row=0,col=gap;col<s.length();row++,col++)
            {
                if(gap==0) dp[row][col]=true;
                else if(gap==1)
                {
                    if(s[row]==s[col]) dp[row][col]=true;
                }
                else
                {
                    if(s[row]==s[col] && dp[row+1][col-1]==true)
                        dp[row][col]=true;
                }
                  if(dp[row][col]) c++;
            }
          
        }
        return c;
        
    }
};
