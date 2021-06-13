    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n=stations.size();
        vector<long> dp(n+1);
        dp[0]=startFuel;
        for(int i=0;i<n;i++)
        {
            for(int j=i;j>=0;j--)
            { if(stations[i][0]<=dp[j])
                dp[j+1]=max(dp[j+1],dp[j]+(long int)stations[i][1]);
            }
        }
        for(auto i=0;i<dp.size();i++){if(dp[i]>=target) return i;}
        return -1;
    }
