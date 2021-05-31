    void dfs(vector<vector<int>>& rooms, vector<bool>& vis,int v)
    {
        vis[v]=1;
        for(auto i:rooms[v])
        { if(vis[i]!=1)
            dfs(rooms,vis,i);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> vis(rooms.size(),0);
        dfs(rooms,vis,0);
        for(auto i:vis) 
        {
            if(i==0) return false;
        }
        return true;
    }
