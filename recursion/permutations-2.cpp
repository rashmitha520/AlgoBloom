 set<vector<int>> dup;
    void find(vector<vector<int>>& ans,vector<int>& per,set<int>& s,vector<int>& nums)
    {
        if(nums.size()==per.size())
        { if(dup.find(per)==dup.end())
            {ans.push_back(per);dup.insert(per);}
            return;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(s.find(i)==s.end())
            {
                per.push_back(nums[i]);
                s.insert(i);
                find(ans,per,s,nums);
                per.pop_back();
                s.erase(i);
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
      vector<vector<int>> ans;  vector<int> per;set<int>s;
      find(ans,per,s,nums);
        return ans;
    }
