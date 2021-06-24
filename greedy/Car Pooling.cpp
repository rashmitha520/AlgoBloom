    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<pair<int,int>> v;
        for(auto trip:trips)
        {
            v.push_back({trip[1],trip[0]}); //when people getin
            v.push_back({trip[2],-trip[0]});//when they getout
            
        }
        sort(v.begin(),v.end());
        int filled=0;
        for(int i=0;i<v.size();i++)
        {
            filled+=v[i].second;
            if(filled>capacity) return 0;
            
        }
        return 1;
    }
