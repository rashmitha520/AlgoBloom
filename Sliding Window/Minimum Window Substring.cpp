   //method -1
   bool valid(map<char,int>& smap,map<char,int>& tmap){
        for(auto it = tmap.begin(); it != tmap.end(); ++it){
            char c= it->first; int freq = it->second;
            if(smap[c] <freq)
                return false;
        }
        return true;
    }
    string minWindow(string s, string t) {
       map<char,int> smap,tmap;
       for(auto i:t) tmap[i]++;
        
       int start=0,len=INT_MAX;string ans="";
        int st=0,e=0;
       for(int end=0;end<s.length();end++)
       {
           smap[s[end]]++;
           while(valid(smap,tmap))
           {
               if(end-start<len)
               {
                   st=start;
                   len=end-start;
                   
               }
               smap[s[start]]--;
             //  if(smap[start]==0) smap.erase(start);
               start++;
           }
       }
       return len==INT_MAX?"":s.substr(st,len+1); 
    }
