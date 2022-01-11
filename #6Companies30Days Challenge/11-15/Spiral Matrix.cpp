    vector<int> spiralOrder(vector<vector<int>>& matrix) {
     vector<int> v;
        int up=0,down=0,r=0,l=0,m=matrix.size(),n=matrix[0].size();
        down=m-1;r=n-1;
        while(l<=r && up<=down){
            if(l<=r && up<=down){
                for(int i=l;i<=r;i++){
                    v.push_back(matrix[up][i]);
                }
                up++;
            }
            if(l<=r && up<=down){
                for(int i=up;i<=down;i++){
                    v.push_back(matrix[i][r]);
                }
                r--;
            }
            if(l<=r && up<=down){
                for(int i=r;i>=l;i--){
                    v.push_back(matrix[down][i]);
                }
                down--;
            }
              if(l<=r && up<=down){
                for(int i=down;i>=up;i--){
                    v.push_back(matrix[i][l]);
                }
                l++;
            }
            
        }
        return v;
    }
