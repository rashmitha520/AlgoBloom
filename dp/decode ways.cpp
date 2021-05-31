   //tle
int find(string& s,int si)
    {
        if(s.length()==si) return 1; //s.length()==1 and si=1
        if(s[si]=='0') return 0; //invalid
        //exclude first no
        int ans=find(s,si+1);
        //include - '123' or '12''3' or '257' or '25'7
        if(si<s.length()-1 && (s[si]=='1'||s[si]=='2' && s[si+1]<'7'))
            ans+=find(s,si+2);
        return ans;
        
    }
    int numDecodings(string s) {
       return s.length()==0?0:find(s,0); 
    }

//memo
 int find(string& s,int si,vector<int>& dp)
    {
        if(s.length()==si) return 1; //s.length()==1 and si=1
        if(s[si]=='0') return 0; //invalid
        if(dp[si]!=-1) return dp[si];
        //exclude first no
        
        int ans=find(s,si+1,dp);
        //include - '123' or '12''3' or '257' or '25'7
        if(si<s.length()-1 && (s[si]=='1'||s[si]=='2' && s[si+1]<'7'))
            ans+=find(s,si+2,dp);
        return dp[si]=ans;
        
    }
    int numDecodings(string s) {
        vector<int>dp(s.length(),-1);
       return s.length()==0?0:find(s,0,dp); 
    }

//dp
   int numDecodings(string s) {
        vector<int> dp(s.length()+1);
        dp[s.length()]=1;
        for(int i=dp.size()-2;i>=0;i--)
        {
            if(s[i]=='0') {dp[i]=0;continue;}
            dp[i]=dp[i]+dp[i+1];
            if((i<s.length()-1) && (s[i]=='1'||(s[i]=='2' && s[i+1]<='6')))
                dp[i]+=dp[i+2];
            
        }
        return dp[0];
    }
