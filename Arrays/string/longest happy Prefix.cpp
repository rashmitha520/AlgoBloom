class Solution {
public:
    string longestPrefix(string s) {
       string ans="";
        int i=1,j=0,n=s.length();
        vector<int> v(n,0);
        v[0]=0;
        while(i<n)
        {
            if(s[i]==s[j])
            {
                //ans.push_back(s[j]);
                v[i]=j+1;
                i++,j++;
            }
            else
            {
                if(j==0)
                {v[i]=0;i++;}
                else
                {
                    j=v[j-1];
                    
                }
            }
        }
        return s.substr(0,j);
    }
};
