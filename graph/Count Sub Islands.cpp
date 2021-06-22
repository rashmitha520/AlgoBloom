  void dfs(vector<vector<int>>& grid,int i,int j,vector<pair<int,int>>& v)
    {
        if(i<0 || j<0||i>=grid.size()||j>=grid[0].size()||grid[i][j]==-1||grid[i][j]==0) return ;
        
        grid[i][j]=-1;
        v.push_back({i,j});
        dfs(grid,i-1,j,v);
        dfs(grid,i,j-1,v);
        dfs(grid,i+1,j,v);
        dfs(grid,i,j+1,v);
        
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        bool yes=true;int c=0;
        for(int i=0;i<grid2.size();i++)
        {  
            for(int j=0;j<grid2[0].size();j++)
               { 
                vector<pair<int,int>> ind; 
                if(grid2[i][j]==1) 
            {
                dfs(grid2,i,j,ind);
                
                for(int k=0;k<ind.size();k++)
                {  
                     if(grid1[ind[k].first][ind[k].second]!=1)
                     { 
                      yes=false;
                      break;
                     }
                }
                
                if(yes) c++;
                if(yes==false) yes=true;}
                
               }
            
        }
        return c;
    }
