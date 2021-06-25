//TLE
 void solve(int m, int n, int moves, int sr, int sc,int& count)
    {
        if((sr<0 or sc<0) or (sr>=m or sc>=n))
        {
            count++;
            return;
        }
        if(moves==0) return;
        solve(m,n,moves-1,sr-1,sc,count);
        solve(m,n,moves-1,sr,sc-1,count);
        solve(m,n,moves-1,sr+1,sc,count);
        solve(m,n,moves-1,sr,sc+1,count);
    }
    int findPaths(int m, int n, int moves, int sr, int sc) {

        int count=0;
        solve(m,n,moves,sr,sc,count);
        return count;
    }

//MEmo
#define mod 1000000007
    long long int dp[51][50][50];
    long long int solve(int m, int n, int moves, int sr, int sc,long long int& count)
    {
        if((sr<0 or sc<0) or (sr>=m or sc>=n))
        {
            return 1+count;
            
        }
        if(moves==0) return dp[0][sr][sc]=0;
        if(dp[moves][sr][sc]!=-1) return dp[moves][sr][sc];
        
     long long int a= solve(m,n,moves-1,sr-1,sc,count);
      long long int b=  solve(m,n,moves-1,sr,sc-1,count);
     long long int c=  solve(m,n,moves-1,sr+1,sc,count);
      long long int d= solve(m,n,moves-1,sr,sc+1,count);
        return dp[moves][sr][sc]=(a%mod+b%mod+c%mod+d%mod)%mod;
    }
    int findPaths(int m, int n, int moves, int sr, int sc) {
          memset(dp,-1,sizeof(dp));
     long long int count=0;
        long long int ans= solve(m,n,moves,sr,sc,count)%mod;
      return ans;
    }


//DP
