class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
       vector<int> ans;
        int r=matrix.size(),c=matrix[0].size();
        int ru=0,rd=r-1,cl=0,cr=c-1;
        while(ru<=rd and cl<=cr)
        {    //for the top row - traverse from left to right
            if(ru<=rd and cl<=cr)
            {
                for(int i=cl;i<=cr;i++)
                    ans.push_back(matrix[ru][i]);
                ru++;
            }
             if(ru<=rd and cl<=cr)
            {//for the last leftmost column , traverse from up to down
                for(int i=ru;i<=rd;i++)
                    ans.push_back(matrix[i][cr]);
                cr--;
            }
             if(ru<=rd and cl<=cr)
            {//for the down row,traverse from right to left
                for(int i=cr;i>=cl;i--)
                    ans.push_back(matrix[rd][i]);
                rd--;
            }
             if(ru<=rd and cl<=cr)
            {//for the first column,traverse from down to up
                for(int i=rd;i>=ru;i--)
                    ans.push_back(matrix[i][cl]);
                cl++;
            }
        }
        return ans;
    }
};
