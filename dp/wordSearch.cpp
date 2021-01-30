//Brute force
class Solution {
public:
    bool is(vector<vector<char>>& board,string s,int x,int y,int k)
    { int m=board.size();
        int n=board[0].size();
        if(k==s.length()) return true;
        if(x<0||y<0||x>m-1||y>n-1) return false;
         if(board[x][y]!=s[k])
             return false;
      //to prevent duplicacy
      board[x][y]='*';
     bool yes=(is(board,s,x+1,y,k+1)||is(board,s,x-1,y,k+1)||is(board,s,x,y-1,k+1)||is(board,s,x,y+1,k+1));
     //restore
     board[x][y]=s[k];
     return yes;
    }
    bool exist(vector<vector<char>>& board, string s) {
      int m=board.size();
        int n=board[0].size();
        //double loop to check chances from each block
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {if(is(board,s,i,j,0))
                    return true;}
        }
                    return false;
    }
};
