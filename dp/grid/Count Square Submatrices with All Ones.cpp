class Solution {
public:
    int countSquares(vector<vector<int>>& mat) {
        int r=mat.size(),c=mat[0].size();
        int count=0;
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
               if((i==0||j==0) and mat[i][j]==1)
               {
                  count+=1; continue;
               }
                if(mat[i][j]==1)
                {
            mat[i][j]=min(min(mat[i-1][j],mat[i][j-1]),mat[i-1][j-1])+1;
                count+=mat[i][j];}
            }
        }
        
        return count;
    }
};
