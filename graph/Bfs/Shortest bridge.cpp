class Solution {
public:
    queue<pair<int,int>> q;
    int n,m;
    void dfs(vector<vector<int>>& grid,int i,int j)
    {
       if(i<0||i>=n||j<0||j>=m||grid[i][j]!=1) return;
        grid[i][j]=-1;
        q.push({i,j});
       
        int dx[] = {0,1,0,-1};
        int dy[] = {1,0,-1,0};
        int x=i,y=j;
        for(int i=0;i<4;++i){
            int x1 = x+dx[i], y1 = y+dy[i];
            if(x1<0 || x1>=n || y1<0 || y1>=m ||grid[x1][y1]!=1) continue;
            dfs(grid,x1,y1);
        }
    }
    int shortestBridge(vector<vector<int>>& grid) {
      vector<int> dx={-1,0,1,0},dy={0,1,0,-1};
     // queue<pair<int,int>> q;
      bool yes=0;
       n=grid.size();m=grid[0].size();
      for(int i=0;i<n;i++)
      {
           
          for(int j=0;j<m;j++)
          {
              if(grid[i][j])
                 { dfs(grid,i,j);yes=1;break;}
          }
          if(yes) break;
      }
      //  cout<<q.size();
      int steps=0;
      while(!q.empty())
      {
          
          int sz=q.size();
          while(sz--)
          {   auto p=q.front();
              int x=p.first,y=p.second;
              grid[x][y]=-1;
              q.pop();
              for(int i=0;i<4;i++)
              {
                  if(x+dx[i]<0||x+dx[i]>=n||y+dy[i]<0||y+dy[i]>=m||grid[x+dx[i]][y+dy[i]]==-1) continue;
                  if(grid[x+dx[i]][y+dy[i]]) return steps;
                  grid[x+dx[i]][y+dy[i]]=-1;
                  q.push({x+dx[i],y+dy[i]});
                  
              }
          }
          steps++;
      }
       return -1; 
    }
};
