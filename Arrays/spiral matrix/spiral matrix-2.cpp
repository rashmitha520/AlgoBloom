class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n,vector<int>(n));
         int r=matrix.size(),c=matrix[0].size();
        int ru=0,rd=n-1,cl=0,cr=n-1;int ele=1;
        while(ele<=n*n)
        {   
            {
                for(int i=cl;i<=cr;i++)
                    matrix[ru][i]=ele++;
                ru++;
            }
            
            {
                for(int i=ru;i<=rd;i++)
                    matrix[i][cr]=ele++;
                cr--;
            }
           
            {
                for(int i=cr;i>=cl;i--)
                    matrix[rd][i]=ele++;
                rd--;
            }
            
            {
                for(int i=rd;i>=ru;i--)
                    matrix[i][cl]=ele++;
                cl++;
            }
        }
        return matrix;
    }
};
