//dfs solution
class Solution {
public:
    void dfs(vector<vector<char>>& grid,int i,int j)
    {.  //checking if it is in range and if its not an island
        if(i<0||j<0||i>=grid.size()||j>=grid[i].size()||grid[i][j]=='0')
            return;
           //if visited then return
        if(grid[i][j]=='2') return;
        //search for water on 4 sides
        grid[i][j]='2';
        dfs(grid,i+1,j);
        dfs(grid,i,j-1);
        dfs(grid,i-1,j);
        dfs(grid,i,j+1);
        
    }
    int numIslands(vector<vector<char>>& grid) {
     int c=0;
        for(int i=0;i<grid.size();i++)
          for(int j=0;j<grid[i].size();j++)
              if(grid[i][j]=='1')
              {  //increment island count
                 c++,dfs(grid,i,j); 
              }
        return c;
    }
};

//bfs solution
