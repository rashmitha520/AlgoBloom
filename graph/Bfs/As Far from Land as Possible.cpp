   int x[]={-1,0,1,0};
    int y[]={0,1,0,-1};
class Solution {
public:

    int maxDistance(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j])
                {
                    
                    q.push({i,j});
                }
            }
        }
        if(q.size()==grid.size()*grid[0].size()) return -1;
        int steps=0;
        while(!q.empty())
        {
            
            int size=q.size();
            steps++;
            for(int sz=0;sz<size;sz++)
            {  
                pair<int,int> fr=q.front();
                 q.pop();
             for(int k=0;k<4;k++)
                {
                 int i=fr.first+x[k],j=fr.second+y[k];
                
                if(i<0||j<0||i>=grid.size()||j>=grid[0].size()||grid[i][j]!=0) continue;
                 q.push({i,j}); grid[i][j]=1;
                }
            }
            
        }
        return steps-1;
    }
};
