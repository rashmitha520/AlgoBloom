 pair<int,int> coords(int curr,int n)
    {
        int r=n-((curr-1)/n)-1;
        int c=(curr-1)%n;
        if(r%2==n%2) return {r,n-c-1};
        return {r,c};
        
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        queue<int> q;
        vector<vector<int>> vis(board.size(),vector<int>(board.size(),0));
        
        q.push(1);
        
        int steps=0;
        
        int n=board.size();
        
        vis[n-1][0]=0;
        
        while(!q.empty())
        {   
            int size = q.size();
            for(int k=0;k<size;k++)
            {
            int cur=q.front();q.pop();
            if(cur==n*n) return steps;
            
            for(int i=1;i<=6;i++)
            {
               if((cur+i)>n*n) break;
                
                pair<int,int> pos=coords(cur+i,n);
                
                int x=pos.first;
                int y=pos.second;
                
               if( vis[x][y]==1) 
                   continue;
                
                vis[x][y]=1;
                
                if(board[x][y]!=-1)
                {
                    q.push(board[x][y]);
                }
                else
                {
                    q.push(cur+i);
                }
            }
            }
            steps++;
        }
        return -1;
    }
