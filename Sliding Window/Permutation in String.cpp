    bool checkInclusion(string s1, string s2) {
        vector<int> perm(26),cur(26);
        for(auto i:s1) perm[i-'a']++;
        
        for(int i=0;i<s2.length();i++)
        {
            cur[s2[i]-'a']++; //increment
            if(i>=s1.size()) //if window invalid
            {
                cur[s2[i-s1.size()]-'a']--;//decrement
            }
            if(cur==perm) return true;
        }
        return false;
    }
