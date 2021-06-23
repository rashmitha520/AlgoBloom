    bool isSub(string& s,string t)
    {
        int i=0,j=0;
        while(i<t.length() && j<s.length())
        {
            if(s[j]==t[i]) i++;
            j++;
        }
        return i==t.length();
    }
    int numMatchingSubseq(string s, vector<string>& words) {
        int c=0;
        unordered_map<string,int> m;
        for(auto word:words) m[word]++;
        for(auto ms=m.begin();ms!=m.end();ms++)
        {
            if(isSub(s,ms->first))
                c+=ms->second;
        }
        return c;
    }
