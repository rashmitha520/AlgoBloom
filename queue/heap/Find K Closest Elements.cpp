    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> ans;
      
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> p;
        for(int i:arr)
        {
            p.push({abs(i-x),i});
        }
        for(int i=0;i<k;i++)
        {   
            ans.push_back(p.top().second);
            p.pop();
        }
        sort(begin(ans),end(ans));
        return ans;
    }
//Binary Search + Sliding Window

//Another Approach
