//Uses graphs approach
//efficient approach
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
     vector<int> balance(n+1); 
     //doubt
        for(auto i:trust) --balance[i[0]],++balance[i[1]];
        for(auto i=1;i<=n;i++)
            if(balance[i]==n-1)
                return i;
        return -1;
    }
};

//space complex approach
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
     vector<int> trusts(n+1),trusted(n+1);  
     //doubt
        for(auto i:trust) ++trusts[i[0]],++trusted[i[1]];
        for(auto i=1;i<=n;i++)
            if(trusts[i]==0 && trusted[i]==n-1)
                return i;
        return -1;
    }
};
