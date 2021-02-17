
/*
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix[matrix.size()-1][matrix[0].size()-1]<target) return 0;
        if(matrix[0][0]>target) return 0;
        for(int i=0;i<matrix.size();i++)
        {
            if(matrix[i][matrix[0].size()-1]>=target)
            {
              for(int j=0;j<matrix[0].size();j++)
              {
                  if(matrix[i][j]==target) return true;
                
              }
              
            }
          
        }
        return false;
    }
};
