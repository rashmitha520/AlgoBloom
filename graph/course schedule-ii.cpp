class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<int> indeg(n,0),res,emp;
        vector<vector<int>> g(n);
        queue<int> q;
        for(int i=0;i<pre.size();i++)
        {
            g[pre[i][1]].push_back(pre[i][0]);
            indeg[pre[i][0]]++;
        }
        for(int i=0;i<indeg.size();i++)
        {
            if(indeg[i]==0){n--;q.push(i);}
            
        }
        while(!q.empty())
        { int c=q.front();q.pop();
         res.push_back(c);
            for(int i:g[c])
        {
                --indeg[i];
                if(indeg[i]==0){n--;q.push(i);}       
        }
        }
        return n==0?res:emp;
    }
};
