    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        queue<pair<int,int>> q;
        int m=maze.size(),n=maze[0].size();
        
        vector<int> dx={1,0,-1,0};
        vector<int> dy={0,-1,0,1};
        
        q.push({entrance[0],entrance[1]});
        
      //  if(entrance[0]==0||entrance[0]==m-1||entrance[1]==0||entrance[1]==n-1)
         //   return 0;
        
        int steps=0;
        
        maze[entrance[0]][entrance[1]]='+';
        
        while(!q.empty())
        {
            steps++;
            int s=q.size();
            for(int k=0;k<s;k++)
            {
                pair<int,int> p=q.front();
                q.pop();
                int i=p.first,j=p.second;
                for(int dir=0;dir<4;dir++)
                {
                   int I=i+dx[dir],J=j+dy[dir];
                
                if(I<0||J<0||J>=n||I>=m||maze[I][J]=='+')
                       continue;
                else if(J==0||J==n-1||I==0||I==m-1)
                    return steps;
                    
                    q.push({I,J});
                    maze[I][J]='+';
                    
                    
                }
            }
        }
        return -1;
    }
