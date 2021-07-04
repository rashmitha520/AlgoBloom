class Solution {
public:
    int dfs(vector<vector<int>>& grid,int i,int j)
    {
        if(i<0||j<0||i>=grid.size()||j>=grid[0].size()||grid[i][j]==0) return 0;
        
        int k=grid[i][j];
        grid[i][j]=0;
        int u=dfs(grid,i+1,j);
        int l=dfs(grid,i-1,j);
        int r=dfs(grid,i,j+1);
        int d=dfs(grid,i,j-1);
        grid[i][j]=k;
        return k+max(max(u,l),max(r,d));
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int sum=INT_MIN;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]!=0)
                {
                    sum=max(sum,dfs(grid,i,j));
                }
            }
        }
        return sum;
    }
};
