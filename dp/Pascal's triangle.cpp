  vector<vector<int>> generate(int n) {
        vector<vector<int>> ans;
        ans.push_back({1});
        if(n==1) return ans;
        ans.push_back({1,1});
        if(n==2) return ans;
        for(int i=2;i<n;i++)
        {   vector<int> v,k;
            for(int j=1;j<ans[i-1].size();j++)
            {
               v.push_back(ans[i-1][j-1]+ans[i-1][j]); 
            }
            k.push_back(1);
            for(int j=0;j<v.size();j++)
            {
                k.push_back(v[j]);
            }
            k.push_back(1);
            ans.push_back(k);
        }
        return ans;
    }
