  vector<vector<int>> nodes; vector<int> v;
    void dfs(vector<vector<int>>& graph,int src,int des)
    {   
       v.push_back(src);
        if(src==des) {nodes.push_back(v); return;}
        
        for(auto rel:graph[src])
        {
           dfs(graph,rel,des); 
           v.pop_back();
        }
        
     
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
      int n=graph.size();
        dfs(graph,0,n-1);
            return nodes;
    }
