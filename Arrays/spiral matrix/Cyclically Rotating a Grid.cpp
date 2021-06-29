 vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
      int m=grid.size(),n=grid[0].size(),ll=min(m,n)/2;//--doubt
       
        for(int l=0;l<ll;l++)
        {
            vector<int> v;
            for(int i=l;i<n-l-1;i++) //first row
                v.push_back(grid[l][i]);
            for(int i=l;i<m-l-1;i++) //last col
                v.push_back(grid[i][n-l-1]);
            for(int i=n-l-1;i>l;i--) //last row
                v.push_back(grid[m-l-1][i]);
            for(int i=m-l-1;i>l;i--)
                v.push_back(grid[i][l]);//first col
            
            int start=k%v.size(); /*doubt*/
            
            for(int i=l;i<n-l-1;i++) //first row
                grid[l][i]=v[start++%v.size()];
            for(int i=l;i<m-l-1;i++) //last col
                grid[i][n-l-1]=v[start++%v.size()];;
            for(int i=n-l-1;i>l;i--) //last row
                grid[m-l-1][i]=v[start++%v.size()];
            for(int i=m-l-1;i>l;i--)
                grid[i][l]=v[start++%v.size()];//first col
            
                
        }
        return grid;
        
    }
