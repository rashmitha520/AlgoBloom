 int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int r=matrix.size(),c=matrix[0].size()+1;
        vector<vector<int>> mat(r,vector<int>(c,0));
        int maxi=INT_MIN;
        //prefix sum
        for(int i=0;i<r;i++)
        {
            for(int j=1;j<c;j++)
                mat[i][j]=mat[i][j-1]+matrix[i][j-1];
        }
        
        for(int s1=0;s1<c;s1++)
        {
            for(int s2=s1+1;s2<c;s2++)
            {
                set<int> m;
                m.insert(0);int sum=0;
                for(int i=0;i<r;i++)
                {
                    sum+=(mat[i][s2]-mat[i][s1]);
                    auto it = m.lower_bound(sum-k);//doubt
                    if(it!=m.end()) 
                        maxi=max(maxi,sum-*it);//doubt
                    m.insert(sum);
                }
            }
        }
        return maxi;
        
    }
