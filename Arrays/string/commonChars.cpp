class Solution {
public:
    vector<string> commonChars(vector<string>& s) {
       vector<int> t(26,0),p(26,0);vector<string> ans;
        for(int i=0;i<s[0].length();i++)
            t[s[0][i]-'a']++;
        for(int i=0;i<s.size();i++)
        {
            for(int j=0;j<s[i].size();j++)
                p[s[i][j]-'a']++;
            for(int i=0;i<26;i++)
               { t[i]=min(t[i],p[i]);p[i]=0;}
        }
        for(int i=0;i<26;i++)
        {
            for(int j=0;j<t[i];j++)
               { string te="";
                te+=i+'a';
                ans.push_back(te);}
        }
        return ans;
    }
};
