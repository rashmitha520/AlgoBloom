 long mod=1e9+7;
    int dp[250][1001];
    void generate(string s,char c,int n,vector<string>& v)
    {  // string ans="";
        if(n==0) 
        {
            v.push_back(s);
            return;
        }
        string colors="RGB";
        
        for(char &color:colors)
        {
            if(c!=color)
                generate(s+color,color,n-1,v);
        }
    }
    int dfs(int cur,int e,vector<vector<int>>& grid)
    {
        if(e==0) return 1;
        if(dp[cur][e]!=-1) return dp[cur][e];
        long long ans=0;
        for(int i:grid[cur])
        {   
            ans = (ans+dfs(i,e-1,grid))%mod;
        }
        return dp[cur][e]=ans%mod;
    }
    int colorTheGrid(int m, int n) {
        //produce all the strings of column 1;
        vector<string> v;
        generate("",'*',m,v);
        bool flag;
        
        
        //push back all those dissimilar for graphs
        vector<vector<int>> grid(v.size());
        int states=v.size();
        for(int i=0;i<states;i++)
        {
            for(int j=0;j<states;j++)
            {
                flag=0;
                for(int k=0;k<m;k++)
                {
                    if(v[i][k]==v[j][k])
                    {
                        flag=1;break;
                    }
                }
                if(flag==0) grid[i].push_back(j);
            }
        }
        
        //count no of branches formed
        memset(dp,-1,sizeof(dp));
        int ans=0;
        for(int i=0;i<states;i++)
            ans=(ans+dfs(i,n-1,grid))%mod;
        return ans;
    }
