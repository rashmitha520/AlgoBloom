    void find(vector<int>& nums,vector<int>& per,set<int>& cur, vector<vector<int>>& v)
    {
     if(per.size()==nums.size())
     {
         v.push_back(per);
         return;
     }
     for(int i=0;i<nums.size();i++)
      {
          if(cur.find(nums[i])==cur.end())
          {
           per.push_back(nums[i]);
           cur.insert(nums[i]);
          
           find(nums,per,cur,v);
          
           per.pop_back();
           cur.erase(nums[i]);
          }
          
      }
     
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> per;set<int> cur; vector<vector<int>> v;
        find(nums,per,cur,v);  
        return v;
    }
