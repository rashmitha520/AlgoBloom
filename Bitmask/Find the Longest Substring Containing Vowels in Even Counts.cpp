    int findTheLongestSubstring(string s) {
      map<int,int>  m;int mask=0,res=0; m[0]=-1; string v="aeiou";
        for(int i=0;i<s.length();i++)
        {
            for(int j=0;j<5;j++)
            {
                if(s[i]==v[j])
                   { mask^=(1<<j);break;}//even
                
            }
            if(m.find(mask)==m.end())
            {
                m[mask]=i;
            }
            res=max(res,i-m[mask]);
        }
        return res;
    }
