 int dfs(vector<vector<int>>& grid,int i,int j)
    {
       
      if(i<0||j<0||i>=grid.size()||j>=grid[0].size()||grid[i][j]==0) return 0;
     
        grid[i][j]=0;
      int u=dfs(grid,i-1,j);
      int d=dfs(grid,i+1,j);
      int l=dfs(grid,i,j-1);
      int r=dfs(grid,i,j+1);
      int ans=1+(u+d+l+r);
      return ans;
      
    
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int area=0;
     
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
                if(grid[i][j]==1)
                area=max(area,dfs(grid,i,j));
        }
        
        return area;
    }

//iterative approach
