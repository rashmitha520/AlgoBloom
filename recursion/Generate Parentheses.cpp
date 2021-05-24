//Recursive
class Solution {
public:
    void back(vector<string>& ans,string cur,int open,int close,int n)
    {
      if(open==n and close==n) 
      {
          ans.push_back(cur);
          return;
      }
        //if not complete i.e. n=2 only n=1 complttd
      if(open<n)
      {
          back(ans,cur+'(',open+1,close,n);
      }
        //if not balanced
    if(close < open)
      {
          back(ans,cur+')',open,close+1,n);
      }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s;
        back(ans,s,0,0,n);
        return ans;
    }
};
