    bool canConstruct(string s, int k) {
        if(k==s.length()) return true;
        if(s.length()<k) return 0;
        map<char,int> m;
        for(auto i:s) m[i]++;
        int ones=0,mores=0;
        for(auto i=m.begin();i!=m.end();i++)
        {
            if(i->second%2)
            {
                ones++;
            }
        }
        mores=m.size()-ones;
        if(mores>=ones) return true;
        return false;
    }
