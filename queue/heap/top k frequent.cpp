
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int k1=0;vector<int> v; map<int,int> m;
        for(auto i:nums) m[i]++;
        priority_queue<pair<int,int>> p;
        for(auto i:m)
        {
            
            p.push({i.second,i.first});
           
        }
        while(!p.empty())
        {
            if(k==0) break;
            v.push_back(p.top().second);
            p.pop();
            k--;
        }
        return v;
        
    }
