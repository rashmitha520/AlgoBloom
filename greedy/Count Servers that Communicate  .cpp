    int countServers(vector<vector<int>>& grid) {
       map<int,int> rows,cols;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j])
                    rows[i]++,cols[j]++;
            }
        }
        int ans=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j] && (rows[i]>1 || cols[j]>1))
                   ans++;
            }
        }
        return ans;
    }
