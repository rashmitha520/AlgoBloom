 vector<vector<int>> br,adj;
    vector<int> low,disc;
    int time=0;
    void dfs(int node,int par)
    {  
        low[node]=disc[node]=time++;
        
        for(auto i:adj[node])
        {
            if(i==par) continue;
            if(!disc[i])
            {   dfs(i,node);
                low[node]=min(low[node],low[i]);
                if(low[i]>disc[node])
                    br.push_back({node,i});
                
            }
            else
                low[node]=min(disc[i],low[node]);
        }
        
        
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        adj=vector<vector<int>>(n);
        low=disc=vector<int>(n,0);
      
        for(auto connection:connections)
        {
            adj[connection[0]].push_back(connection[1]);
            adj[connection[1]].push_back(connection[0]);
        }
        for(int i=0;i<adj.size();i++)
            if(disc[i]==0)
               dfs(i,i);
        return br;
    }
