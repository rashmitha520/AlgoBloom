/*
Example 1:

Input: s = "3242415"
Output: 5
Explanation: "24241" is the longest awesome substring, we can form the palindrome "24142" with some swaps.
*/    
int longestAwesome(string s) {
       int mask=0,res=0;
       vector<int> m(1024,s.size());m[0]=-1;
        for(int i=0;i<s.size();i++)
        {
            mask^=1<<(s[i]-'0');//for even palindromes
            res=max(res,i-m[mask]);
            for(int j=0;j<=9;j++)
            {
                
                res=max(res,i-m[mask^(1<<j)]);//for odd palindromes
            }
           
           m[mask]=min(m[mask],i);
        }
        return res;
    }
