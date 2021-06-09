class Solution {
public:
    vector<int> diffWaysToCompute(string exp) {
        int n=exp.length();
        vector<int> res;
        for(int i=0;i<n;i++)
        {   int cur=exp[i];
            if(exp[i]!='+' && exp[i]!='-' && exp[i]!='*') continue;
            vector<int> l=diffWaysToCompute(exp.substr(0,i));
            vector<int> r=diffWaysToCompute(exp.substr(i+1));
         for(auto left:l)
         {  for(auto right:r)
           { if(cur=='+')
                res.push_back(left+right);
            else if(cur=='-')
                res.push_back(left-right);
            else if(cur=='*')
                res.push_back(left*right);}
            
        } }
        if(res.size()==0) res.push_back(stoi(exp));
        return res;
    }
};
