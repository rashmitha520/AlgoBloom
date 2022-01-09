bool isValidSudoku(vector<vector<char>>& board) {
      
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                
                if(board[i][j]=='.') continue;
                //horizontal
                for(int hor=0;hor<board[0].size();hor++){
                    if(j==hor) continue;
                    if(board[i][hor]==board[i][j]) return 0;
                }
                //vertical
                for(int ver=0;ver<board.size();ver++){
                    if(i==ver) continue;
                    if(board[ver][j]==board[i][j]) return 0;
                }
                //inside box
                int bi=i/3*3,bj=j/3*3;
                for(int i1=0;i1<3;i1++)
                {
                    for(int j1=0;j1<3;j1++){
                        if(i1+bi==i && j1+bj==j) continue;
                        if(board[i1+bi][j1+bj]==board[i][j]) return 0;
                    }
                }
                
            }
        }
        return 1;
    }
