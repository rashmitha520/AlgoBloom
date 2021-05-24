class Solution {
public:
    set<string> st1;
    int getMin(string s)
    {
        stack<char> st;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]!='(' && s[i]!=')') continue;
            char c=s[i];
            if(s[i]=='(')
                st.push(c);
            else if(st.size()==0) st.push(c);
            else if(s[i]==')' and st.top()!='(')
               st.push(c);
            else st.pop();
        }
        return st.size();
    }
    void remove(vector<string>& v,string s,int mra,set<string>& st)
    {
        if(mra==0)
        {
           int pending = getMin(s);
            if(pending ==0) 
            {
                if(st.find(s)==st.end())
                {
                    st.insert(s);
                    v.push_back(s);
                }
            }
             return ;
        }
        for(int i=0;i<s.length();i++)
        { 
           if(s[i]!='(' && s[i]!=')') continue;
           string left=s.substr(0,i);
            string right=s.substr(i+1);
            if(st1.find(left+right)==st1.end())
           {    st1.insert(left+right);
                remove(v,left+right,mra-1,st);}
        }
        
       
    }
    vector<string> removeInvalidParentheses(string s) {
      int mra=getMin(s);
      set<string> st;
      vector<string> v;
          remove(v,s,mra,st);
        return v;
        
    }
};
