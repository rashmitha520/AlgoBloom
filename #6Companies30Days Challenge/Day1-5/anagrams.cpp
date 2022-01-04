class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> u;
        for(int i=0;i<strs.size();i++)
        {    
            string s= strs[i];
            sort(s.begin(),s.end());
            u[s].push_back(strs[i]);
        }
        vector<vector<string>> v;
        for(auto i:u)
        {
            v.push_back(i.second);
        }
        return v;
    }
};
