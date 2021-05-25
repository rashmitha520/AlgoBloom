#include<bits/stdc++.h>
class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
       int r=mat.size(),c=mat[0].size();
        //horizontal subarrays
        for(int i=0;i<r;i++)
        {
            for(int j=c-2;j>=0;j--)
            {
                if(mat[i][j]==1)
                mat[i][j]+=mat[i][j+1];
            }
        }
        int count=0;
        //vertical of particular height
         for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                int minw=mat[i][j];
                for(int k=i;k<r;k++)
                {
                    if(mat[k][j]==0) break;
                    minw=(minw>mat[k][j])?mat[k][j]:minw;
                    count+=minw;
                }
            }
        }
        return count;
    }
};
