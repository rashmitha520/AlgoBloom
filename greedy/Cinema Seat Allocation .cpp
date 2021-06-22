    bool vacant(int s,int e,vector<int>& rows)
    {
        for(auto row:rows)
        {
            if(s<=row && e>=row) return 0;
            
        }
        return true;
    }
    int maxNumberOfFamilies(int n, vector<vector<int>>& res) {
        int row=res.size(),col=res[0].size();
        unordered_map<int,vector<int>> m;
        for(auto i:res)
        {  if(i[1]==1 or i[1]==10) continue;
            m[i[0]].push_back(i[1]);//syntax
        }
        int ans=(n-m.size())*2;
        for(auto i:m)
        {
            if(vacant(2,5,i.second)||vacant(4,7,i.second)||vacant(6,9,i.second))//dbt
                ans++;
        }
        return ans;
    }
