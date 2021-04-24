class Solution {
public:
    bool cycle(vector<vector<int>>& graph,int parent,vector<bool>& visited,int cur)
    {
        visited[cur]=true;
        for(auto i:graph[cur])
        {
            if(!visited[i])
            {
                if(cycle(graph,cur,visited,i))
                    return true;
            }
            else if(i!=parent)
            {
                return true;
            }
        }
        visited[cur]=false;
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<vector<int>> graph(edges.size()+1);
        vector<bool> visited(edges.size()+1,0);
        for(auto edge:edges)
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
            if(cycle(graph,-1,visited,edge[0]))
                return edge;
        }
        return {1453};
    }
};
