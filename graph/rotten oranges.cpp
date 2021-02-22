class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
     queue<pair<int,int>> q;int fresh=0;int ans=-1;
     vector<int> dir={-1,0,1,0,-1};
        int n=grid[0].size();int m=grid.size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1) fresh++;
                else if(grid[i][j]==2)
                    q.push({i,j});
            }
        }
        while(!q.empty())
        { int s=q.size();
            while(s--)
            {
                pair<int,int> k=q.front();
                q.pop();
                for(int i=0;i<4;i++)
                {
                    int r=k.first+dir[i];
                    int c=k.second+dir[i+1];
                    if((r>=0 && c>=0) && r<m && c<n && grid[r][c]==1)
                    {
                        grid[r][c]=2;
                        q.push({r,c});
                        fresh--;
                    }
                }
                
            }
         ans++;
        }
        if(fresh>0) return -1;
        if(ans==-1) return 0;
        return ans;
    }
};
