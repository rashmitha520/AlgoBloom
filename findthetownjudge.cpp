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
//With pair
class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
      vector<pair<int,int>> jud(N+1);
        for(auto i:trust)
        {
            jud[i[0]].first++;
             jud[i[1]].second++;
        }
        for(auto i=1;i<=N;i++)
        {
            if(jud[i].first==0 && jud[i].second==N-1)
                return i;
        }
        return -1;
    }
};
