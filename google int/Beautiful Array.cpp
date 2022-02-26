class Solution {
public:
    vector<int> beautifulArray(int n) {
        if(n==1) return {1};
        vector<int> even = beautifulArray(n/2);
        vector<int> odd = beautifulArray(n-n/2);
        
        vector<int> ans;
        for(auto i:even) ans.push_back(2*i);
        for(auto i:odd) ans.push_back(2*i-1);
        return ans;
        
    }
};
