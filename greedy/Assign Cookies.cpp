    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int count=0;
       if(s.size()==0) return 0;
     
        int i=0;
        for(int j=0;i<g.size() && j<s.size();j++)
        {
           
               if(s[j]>=g[i])
                   i++;
                   
                   
           
        }
        return i;
    }
