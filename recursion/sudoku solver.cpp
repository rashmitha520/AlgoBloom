class Solution {
public:
   bool valid(vector<vector<char>>& board,char val,int i,int j)
    { 
       //horizontal check
        for(int k=0;k<board[0].size();k++)
        {
            if(board[i][k]==val) return false;
        }
       //vertical check
       for(int k=0;k<board.size();k++)
        {
            if(board[k][j]==val) return false;
        }
       //corner pt of each block
       int x=i/3*3,y=j/3*3;
       for(int p=0;p<3;p++)
       {
           for(int q=0;q<3;q++)
           {
               if((board[p+x][q+y])==val) return 0;
           }
       }
        return 1;
           
    }
    void solve(vector<vector<char>>& board,int i,int j,vector<vector<char>>& b)
    {
       int ni=0,nj=0;
         
       if(i==board.size()){ b=board;return;}
        if(j==board[0].size()-1)
        {
            ni=i+1;
            nj=0;
        }
        else
        {
           ni=i;nj=j+1; 
        }
        if(board[i][j]!='.') solve(board,ni,nj,b);
        else{
            for(int pos=1;pos<=9;pos++)
            {
                if(valid(board,pos+'0',i,j)==1)
                {
                    board[i][j]=pos+'0';
                    solve(board,ni,nj,b);
                    board[i][j]='.';
                }
            }
        }
        
    }
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<char>> b;
        solve(board,0,0,b);
        board=b;
    }
};
