//bruteforce
void gameOfLife(vector<vector<int>>& board) {
      
        vector<vector<int>> temp=board;
        int n=board.size(),m=board[0].size();
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            { count=0;
                if(i>0 and j>0) 
                {
                    if(board[i-1][j-1]) count++;
                }
              if(i>0 and j<m-1) 
                {
                    if(board[i-1][j+1]) count++;
                }
             if(i<n-1 and j<m-1) 
                {
                    if(board[i+1][j+1]) count++;
                }
             if(i>0 and j>=0) 
                {
                    if(board[i-1][j]) count++;
                }
             if(i>=0 and j>0) 
                {
                    if(board[i][j-1]) count++;
                }
           if(i<n-1 and j>0) 
                {
                    if(board[i+1][j-1]) count++;
                }
              if(i<n-1 and j>=0) 
                {
                    if(board[i+1][j]) count++;
                }
              if(i>=0 and j<m-1) 
                {
                    if(board[i][j+1]) count++;
                }
                if(!board[i][j])
                {
                    if(count==3) temp[i][j]=1;
                }
                else
                {
                    if(count<2 or count>3) temp[i][j]=0;
                    //else board[i][j]=1;
                }
                
            }
            
        }
        
        board=temp;
    }
