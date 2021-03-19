//brute force
long long kDistinctCharacters(string &s, int k) {
        // Write your code here
        vector<string> st;
        long long count=0;
         int n=s.length();
        for(int i=0;i<n;i++)
          for(int j=1;j<=n-i;j++)
             st.push_back(s.substr(i,j));
        
        for(int i=0;i<st.size();i++)
        {
            string a=st[i];
            if(a.length()<k) continue;
            set<char> u;
            for(int j=0;j<a.length();j++)
            {
             u.insert(a[j]);
            }
            if(u.size()>=k) count+=1;
            u.clear();
        }
        return count;
}



//O(n*n)
class Solution {
public:
  
    long long kDistinctCharacters(string &s, int k) {
        // Write your code here
        vector<int> v;
        long long count=0;
         int n=s.length();
        for(int i=0;i<n;i++)
         {  vector<int> v(26,0);
         int dis=0;
             for(int j=i;j<n;j++)
           {
              if(v[s[j]-'a']==0) 
              dis++;
              v[s[j]-'a']++;
            if(dis>=k) count+=1;
           }
        }
        return count;
    }
};
