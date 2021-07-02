    void dfs(vector<vector<int>>& grid,int i)
    {
      //  if(i<0||j<0||i>=grid.size()||j>=grid[0].size()||grid[i][j]==0)
        //    return;
       // grid[i][j]=0;
        for(int k=0;k<grid.size();k++)
        {
            if(grid[i][k]==1)
                {
                grid[i][k]=grid[k][i]=0;
                dfs(grid,k);
            }
        }
        
    }
    int findCircleNum(vector<vector<int>>& grid) {
        int c=0;
        for(int i=0;i<grid.size();i++)
        {
            
                if(grid[i][i])
                {
                    dfs(grid,i);
                    c++;
                }
            
        }
        return c;
    }
