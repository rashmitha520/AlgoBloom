class Solution {
public:
    bool isv(string s)
    {
        string k=s;
            reverse(k.begin(),k.end());
        if(k==s) return 1;
        return 0;
        
    }
     void  partitionU(string s,vector<vector<string>>& sol, vector<string>& ans,int ind)
     {
          if(s.length()==ind)
        {
           sol.push_back(ans);return;
        }
        for(int i=ind;i<s.length();i++)
        {
            string pre=s.substr(ind,i-ind+1);
            
            if(isv(pre))
            {
                ans.push_back(pre);
                partitionU(s,sol,ans,i+1);
                ans.pop_back();
            }
            
        }
     }
    vector<vector<string>> partition(string s) {
    vector<vector<string>> sol;
        vector<string> ans;
       partitionU( s,sol,ans,0);
        return sol;
       
    }
};
//2nd approach
class Solution {
public:
    bool isv(string s)
    {
        string k=s;
        reverse(k.begin(),k.end());
        if(k==s) return 1;
        return 0;
        
    }
     void  partitionU(string s,vector<vector<string>>& sol, vector<string>& ans)
     {
          if(s.length()==0)
        {
           sol.push_back(ans);return;
        }
        for(int i=0;i<s.length();i++)
        {
            string pre=s.substr(0,i+1);
            string res=s.substr(i+1);
            if(isv(pre))
            {
                ans.push_back(pre);
                partitionU(res,sol,ans);
                ans.pop_back();
            }
            
        }
     }
    vector<vector<string>> partition(string s) {
    vector<vector<string>> sol;
        vector<string> ans;
       partitionU( s,sol,ans);
        return sol;
       
    }
};
