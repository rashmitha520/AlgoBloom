```cpp
class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int r=matrix.size(),c=matrix[0].size();
        int col=matrix[0].size()+1;
        vector<vector<int>> mat(r,vector<int>(col,0));
        for(int i=0;i<r;i++)
        {
            for(int j=1;j<col;j++)
            {
                mat[i][j]=mat[i][j-1]+matrix[i][j-1];
            }
        }
        int count=0;
         for(int slide1=0;slide1<col;slide1++)//first sliding 
        {
            for(int slide2=slide1+1;slide2<col;slide2++)//second slide
            {
                map<int,int> m;
                m[0]=1;int sum=0;
                for(int k=0;k<r;k++)//find the sum btw them and find if it is found
                {
                    sum+=(mat[k][slide2]-mat[k][slide1]);
                    if(m[sum-target]!=0) count+=m[sum-target];//add no of answers
                    m[sum]++;
                    
                }
            }
        }
        return count;
    }
};
```
https://leetcode.com/problems/number-of-submatrices-that-sum-to-target/discuss/803353/Java-Solution-with-Detailed-Explanation
