class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
    vector<vector<int>> graph(n);
        vector<int> indeg(n,0);
        queue<int> q;
        for(int i=0;i<pre.size();i++)
        {
           graph[pre[i][1]].push_back(pre[i][0]); 
            indeg[pre[i][0]]++;
        }
        for(int i=0;i<indeg.size();i++)
        {
            if(indeg[i]==0)
            {
                q.push(i);
                n--;
            }
        }
        while(!q.empty())
        {
            int c=q.front();q.pop();
            for(int i:graph[c])
            { --indeg[i];
                if(indeg[i]==0)
                {
                    q.push(i);
                        n--;
                }
            }
        }
        return n==0;
    }
};
