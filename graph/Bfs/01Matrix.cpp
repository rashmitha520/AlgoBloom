 vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
     vector<vector<bool>> vis(mat.size(),vector<bool>(mat[0].size()));
     int m=mat.size(),n=mat[0].size();
     queue<pair<int,int>> q;
     for(int i=0;i<m;i++)
     {
         for(int j=0;j<n;j++)
         {
             if(mat[i][j]==0) 
             {
                 q.push({i-1,j});
                 q.push({i,j-1});
                 q.push({i+1,j});
                 q.push({i,j+1});
             }
         }
     }
    int steps=0;  
    while(!q.empty())
    {
        steps++;
        
        int sz=q.size();
        for(int k=0;k<sz;k++)
        {  pair<int,int> frt = q.front();
            int i=frt.first,j=frt.second;
            q.pop(); 
            if(i>=0 && j>=0 && i<m && j<n && vis[i][j]==0 && mat[i][j]==1)
            {
                vis[i][j]=true;
                mat[i][j]=steps;
                 q.push({i-1,j}),q.push({i,j-1}),q.push({i+1,j}),q.push({i,j+1});
            }
           
           
            
        }
        
    }
        return mat;
        
        
        
    }
