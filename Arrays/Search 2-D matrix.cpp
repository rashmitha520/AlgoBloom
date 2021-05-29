  bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r=matrix.size();
        int c=matrix[0].size();
        int column=0;
       int i=0,j=(c==0?0:c-1);
        //last column
        while(i<r and j>=0)
        {
            if(matrix[i][j]==target) return 1;
            else if(matrix[i][j]>target) j--; //if target is less then its not present                                               
                                              //in that column
            else i++;                         //if greater then not present in that                                                
                                              //row
        }
        return 0;
    }
