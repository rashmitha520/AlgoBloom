/*intuition : if 'X' is always first 
incase 'O' wins : no of X==no of O 
incase 'X' wins : no of X > no of O and no of X - no of O = 1*/
class Solution {
public:
    bool h(char xo,vector<string>& board)
    {
       for(int i=0;i<3;i++)
       {
           if(board[i][0]==xo && (board[i][1]==board[i][2] && board[i][1]==board[i][0]))
               return 1;
           if(board[0][i]==xo && (board[1][i]==board[2][i] && board[1][i]==board[0][i]))
               return 1;
           if(board[0][0]==xo && (board[1][1]==board[2][2] && board[1][1]==board[0][0]))
               return 1;
           if(board[0][2]==xo && (board[1][1]==board[2][0] && board[1][1]==board[0][2]))
               return 1;
       }
        return 0;
    }
    bool validTicTacToe(vector<string>& board) {
        int O=0,X=0;
     for(int i=0;i<board.size();i++)
     {
         for(int j=0;j<3;j++)
         { 
            if(board[i][j]=='O') O++;
            else if(board[i][j]=='X') X++;
             else continue;
         }
     }
     if(O>X or X-O>1) return 0;
    if(O==X) {if(h('X',board)) return 0;}
    if(X-O==1){if(h('O',board)) return 0;}
        return true;
    }
};
