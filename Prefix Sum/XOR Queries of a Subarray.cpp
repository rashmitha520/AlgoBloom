    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
      
        vector<int> ans,pre(arr.size()+1);
        for(int i=0;i<arr.size();i++) pre[i+1]=pre[i]^arr[i];
        for(auto i:queries)
        {  
            int l=i[0],r=i[1];
           
          ans.push_back(pre[r+1]^pre[l]);//pre[l] because pre[l+1...r+1] included
            //as pre has one extra size so r=> r+1, l=>l+1
        }
        return ans;
    }
