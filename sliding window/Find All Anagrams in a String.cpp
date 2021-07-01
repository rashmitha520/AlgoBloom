 vector<int> findAnagrams(string s, string p) {
        vector<int> ans,cur(26),prev(26);
        for(auto i:p) prev[i-'a']++;
        
      for(int i=0;i<s.length();i++)
      {
          cur[s[i]-'a']++;//increasing window
          if(i>=p.length()) cur[s[i-p.size()]-'a']--;//when invalid removing prev ones to make valid
          if(cur==prev) ans.push_back(i-p.size()+1);
      }
        return ans;
    }
