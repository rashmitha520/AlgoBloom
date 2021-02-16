class Solution {
public:
    string longestPalindrome(string s) {
        int c;int i,j;
        vector<vector<bool>> dp(s.length(),vector<bool>(s.length(),false));
        for(int gap=0;gap<s.length();gap++)
        {
            for(int row=0,col=gap;col<s.length();col++,row++)
            {
                if(gap==0) dp[row][col]=true;
                else if(gap==1) {if(s[row]==s[col]) dp[row][col]=true;}
                else
                {
                    if(s[row]==s[col] && dp[row+1][col-1]==true)
                        dp[row][col]=true;
                }
            if(dp[row][col]){ i=row;j=gap+1;}
            }
        }
        return s.substr(i,j);
    }
};
