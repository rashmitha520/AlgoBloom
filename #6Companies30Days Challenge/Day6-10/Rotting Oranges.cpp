class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int fresh=0,ans=0,m=grid.size(),n=grid[0].size();
        queue<pair<int,int>> q;
        vector<int> is = {-1,1,0,0},js={0,0,-1,1};
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1) fresh++;
                else if(grid[i][j]==2) q.push({i,j});
            }
        }
        if(fresh==0) return 0;
        while(!q.empty()){
            int s=q.size();
            while(s--){
                pair<int,int> index=q.front();
                q.pop();
                for(int i=0;i<4;i++){
                    int x=is[i]+index.first,y=js[i]+index.second;
                    if(x<m && y<n && x>=0 && y>=0 && grid[x][y]==1)
                    {
                        grid[x][y]=2;
                        fresh--;
                        q.push({x,y});
                    }
                }
            }
            if(fresh==0) return ans+1;
            ans++;
        }
        
        return -1;
    }
};
