    vector<int> partitionLabels(string s) {
        vector<int>  v(26),ans;
        for(int i=0;i<s.length();i++) v[s[i]-'a']=i;
        int len=0;
        int last=-1;
        for(int i=0;i<s.length();i++)
        {
            len++;
            last=max(last,v[s[i]-'a']); //last repeating position
            if(i==last)// if the last repeating position is same, it is one partition
            {
                ans.push_back(len);
                len=0;last=-1;
            }
        }
        return ans;
    }
