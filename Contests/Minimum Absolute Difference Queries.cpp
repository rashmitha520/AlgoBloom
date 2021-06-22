    vector<int> minDifference(vector<int>& nums, vector<vector<int>>& q) {
        int n=nums.size();
        long long int pre[n][101];
        memset(pre,0,sizeof(pre));
    for(int i=0;i<n;i++)
        {
            pre[i][nums[i]]++;
            for(int j=1;j<=100;j++)
            {   if(i!=0)
                pre[i][j]+=pre[i-1][j];
            }
        }
        
        vector<int> ans;
        for(int i=0;i<q.size();i++)
        {
            int l=q[i][0],r=q[i][1];
             vector<int> v;
            for(int j=1;j<=100;j++)
            {
                if(l==0)
                {if(pre[r][j]>0)
                  v.push_back(j);
                }
                else
                {
                    if(pre[r][j]-pre[l-1][j]>0)
                        v.push_back(j);
                        
                }
            }
            int mini=100;
            for(int j=1;j<v.size();j++)
            {
                if(v[j]!=v[j-1])
                    mini=min(mini,v[j]-v[j-1]);
            }
            
            if(mini!=100) ans.push_back(mini);
            else ans.push_back(-1);
        }
        return ans;
        
        
    }
