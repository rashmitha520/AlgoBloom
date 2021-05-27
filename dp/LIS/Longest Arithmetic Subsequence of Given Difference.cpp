//tle
int longestSubsequence(vector<int>& arr, int d) {
        int n=arr.size();
        int ans=0; vector<int> dp(n,1);
        unordered_map<int,int> m;
        
        for(int i=0;i<n;i++)
        {
            int cur = arr[i];
            int maxi=0;
            for(int j=0;j<i;j++)
            {
                if(arr[i]-arr[j]==d) 
                {
                   maxi=max(dp[j],maxi); 
                }
            }
            dp[i]=maxi+1;
            ans=max(ans,dp[i]);
        }
        return ans;
    }

//hashmap
int longestSubsequence(vector<int>& arr, int d) {
        int n=arr.size();
        int ans=0;// vector<int> dp(n,1);
        unordered_map<int,int> dp;
       // dp[0]=1;
        for(int i=0;i<n;i++)
        {
            if(dp.find(arr[i]-d)!=dp.end())
                dp[arr[i]]=dp[arr[i]-d]+1;
            else dp[arr[i]]=1;
            
            ans = max(ans,dp[arr[i]]);
        }
        return ans;
    }
