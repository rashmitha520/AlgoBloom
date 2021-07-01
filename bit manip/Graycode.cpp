    vector<int> grayCode(int n) {
        if(n==0) return {0};
        if(n==1)
        {
            return {0,1};
        }
        vector<int> prev=grayCode(n-1);
        vector<int> rest;
        for(int i=0;i<prev.size();i++)
        {
            rest.push_back(prev[i]|0<<(n-1));
            
        }
        for(int i=prev.size()-1;i>=0;i--)
        {
            rest.push_back(prev[i]|1<<(n-1));
            
        }
        return rest;
    }
