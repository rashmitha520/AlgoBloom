    #define MOD 1000000007
    int find(int d, int f, int target,vector<vector<int>>& dp)
    {
        if(d==0 and target==0) return 1; //if no dice and no target
        else if(d<=0||target<=0) return 0; //-ve target cannot be achieved
        //with no dies no way
        if(dp[d][target]!=-1) return dp[d][target];
        int ans=0;
        for(int i=1;i<=f;i++)
        {
            ans=(ans+find(d-1,f,target-i,dp))%MOD;
        }
        return dp[d][target]=ans;  
    }
    int numRollsToTarget(int d, int f, int target) {
      vector<vector<int>> dp(d+1,vector<int>(target+1,-1));
       return find(d,f,target,dp);
    }

//dp 
 #define m 1000000007
  
    int numRollsToTarget(int d, int f, int target) {
      vector<vector<int>> dp(d+1,vector<int>(target+1,0));
      
        dp[0][0]=1;
       
        for(int dice=1;dice<=d;dice++)
            for(int tar=1;tar<=target;tar++)
                 for(int i=1;i<=f;i++)
                 { if(tar>=i)
                   dp[dice][tar]=((dp[dice][tar]%m)+ (dp[dice-1][tar-i]%m))%m;
                   }
        return dp[d][target]; 
    }
