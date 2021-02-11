class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
       priority_queue<vector<int>, vector<vector<int>>,compare> p;
        for(vector<int>& i:points)
        {
            p.push(i);
            if(p.size()>K)
                p.pop();
            
        }
        vector<vector<int>> ans;
        while(!p.empty())
        {
            ans.push_back(p.top());
            p.pop();
        }
        return ans;
    }
    private:
    struct compare
    {
        bool operator()(vector<int>& p,vector<int>& q)
        {
            return p[0]*p[0]+p[1]*p[1]<q[0]*q[0]+q[1]*q[1];
        }
    };
};
