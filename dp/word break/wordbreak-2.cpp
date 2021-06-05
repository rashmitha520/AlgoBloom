//memo
class Solution {
public:
    map<string,vector<string>> mp;
    vector<string> fn(string s,unordered_set<string>& sets)
    {   vector<string> v;
         if(mp.find(s)!=mp.end()) return mp[s];
         for(int i=1;i<=s.length();i++)
         {
             if(sets.find(s.substr(0,i))!=sets.end())
             {
                 if(s.substr(i).length()==0) v.push_back(s.substr(0,i));
                 else
                 { vector<string> suf= fn(s.substr(i),sets);
                       for (auto sub : suf) 
                           v.push_back(s.substr(0, i) + " " + sub);
                 }
             }
         }
     return mp[s]=v;
        
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> sets(wordDict.begin(),wordDict.end());
        return fn(s,sets);
    }
};
