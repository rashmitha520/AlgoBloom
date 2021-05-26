class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        //doubt
        vector<bool> dp(s.length()+1,false);
        set<string> dict;
        
        for(auto i:wordDict)
            dict.insert(i);
        
        if(s.length()==1 ){return (dict.find(s)!=dict.end())?1: 0;}
        
        if(s.length()==0) return 1;
        
        dp[0]=1;//doubt
        
        for(int i=1;i<=s.length();i++)
        {
            for(int j=i-1;j>=0;j--)
            {//(i-j)
                if(dp[j] && dict.find(s.substr(j,i-j))!=dict.end()) 
                   { 
                    dp[i]=true;break;
                }
            }
        }
        
        
        
        return dp[s.length()]==true;
    }
};
