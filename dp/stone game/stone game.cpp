   int solve(vector<int>& piles,vector<vector<int>>& dp,int s,int e,int odd){
      if(s>e) return 0;
      if(dp[s][e]!=-1) return dp[s][e];
      if(odd%2!=0)
      {
          int r1=solve(piles,dp,s+1,e,odd++)+piles[s];
          int r2=solve(piles,dp,s,e-1,odd++)+piles[e];
          int ans=max(r1,r2);
          return dp[s][e]=ans; //max score to alex
      }
     int r1=solve(piles,dp,s+1,e,odd++)-piles[s];
     int r2=solve(piles,dp,s,e-1,odd++)-piles[e];
        int ans=min(r1,r2);
        return dp[s][e]=ans;//min score to bob
      
    }
    bool stoneGame(vector<int>& piles) {
     vector<vector<int>> dp(piles.size(),vector<int>(piles.size(),-1));
        solve(piles,dp,0,piles.size()-1,1);
      return dp[1][piles.size()-1]>0;
        
    }
