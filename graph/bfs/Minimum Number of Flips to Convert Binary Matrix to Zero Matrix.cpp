    int m,n;
    bool isZero(vector<vector<int>>& mat)
    {
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mat[i][j]) return 0;
            }
        }
        return 1;
    }
    vector<vector<int>> flips(vector<vector<int>>& mat,int i,int j)
    {
        mat[i][j]^=1;
        if(i-1>=0) mat[i-1][j]^=1;
        if(j-1>=0) mat[i][j-1]^=1;
        if(i+1<m) mat[i+1][j]^=1;
        if(j+1<n) mat[i][j+1]^=1;
        return mat;
        
    }
    int flipchoice(vector<vector<int>> mat,int i,int j)
    {
       if(j==n) j=0,i++;
       if(i==m) return isZero(mat)?0:10000;
       int res1 = flipchoice(mat,i,j+1);
       int res2 = flipchoice(flips(mat,i,j),i,j+1)+1;
       return min(res1,res2);
    
    }
    int minFlips(vector<vector<int>>& mat) {
        m=mat.size(),n=mat[0].size();
        auto res = flipchoice(mat,0,0);
        return res==10000?-1:res;
    }
