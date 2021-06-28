    string removeOccurrences(string s, string part) {
       string ans;
        for(auto i:s)
        {
            ans+=i;
            if(ans.size()>=part.size() && ans.substr(ans.size()-part.size())==part)
            {  int n=part.size();
                while(n--)
                {
                    ans.pop_back();
                }
            }
        }
        return ans;
    }
