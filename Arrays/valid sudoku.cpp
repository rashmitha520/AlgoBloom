class Solution {
public:
    bool hor(vector<vector<char>>& board,int i,int j,char val)
    {
       
        for(int a=0;a<9;a++)
        {   if(a==j) continue;
            if(board[i][a]==val && a!=j) return false;
        }
        return true; 
    }
    bool ver(vector<vector<char>>& board,int i,int j,char val)
    {
        for(int a=0;a<9;a++)
        {
            if(a==i) continue;
            if(board[a][j]==val) return false;
        }
        return true;
    }
    bool bo(vector<vector<char>>& board,int i,int j,char val)
    {
        int corx=i/3*3,cory=j/3*3;
        for(int a=0;a<3;a++)
        {
            for(int b=0;b<3;b++)
               { if(a+corx== i && b+cory==j) continue;
                if(board[a+corx][b+cory]==val ) return false;}
        }
        return true;
        
    }
    bool valid(vector<vector<char>>& board,int i,int j)
    {
        for(int i=0;i<9;i++)
            for(int j=0;j<9;j++)
        {  
            if(board[i][j]=='.') continue;
            bool h=hor(board,i,j,board[i][j]);
            bool v=ver(board,i,j,board[i][j]);
            bool b=bo(board,i,j,board[i][j]);
           if(h==0 or v==0 or b==0) return 0;
             
           
        }
        return true;
        
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        bool b=valid(board,0,0);
        return b;
    }
};
