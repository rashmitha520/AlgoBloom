  #define ll long long 
    ll m = 1e9+7;
    ll dp[100001];
    string s;
    int numDecodings(string st) {
        s=st;
       for(int i = 0 ; i <= s.size(); i++){
            dp[i] = -1;
        }
        return solve(0);
    }
    ll solve(int i)
    {
       if(i>=s.length()) return 1;
       if(dp[i]!=-1) return dp[i];
       if(s[i]=='0') return dp[i]=0;
       
       ll res=solve(i+1);
       if(s[i]=='*')
       {
           res*=9;
           if((i+1)<s.size() && s[i+1]>='0' && s[i+1]<='9')
               res+=solve(i+2);
            if((i+1)<s.size() && s[i+1]=='*')
               res= res+(9*solve(i+2));
           if((i+1)<s.size() && s[i+1]>='0' && s[i+1]<='6')
               res+=solve(i+2);
           if((i+1)<s.size() && s[i+1]=='*')
               res= res+(6*solve(i+2));
      
           
       }
     
       else if((i+1)<s.length() && s[i]=='1')
       {
         if(s[i+1]>='0' && s[i+1]<='9') 
             res+=solve(i+2);
         else if(s[i+1]=='*')
             res=res+9*solve(i+2);
       }
       else if((i+1)<s.length() && s[i]=='2')
       {
         if(s[i+1]>='0' && s[i+1]<='6') 
             res+=solve(i+2);
         else if(s[i+1]=='*')
             res=res+6*solve(i+2);
       }
        res=res%m;
        return dp[i]=res;
    }
