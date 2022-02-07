class Solution {
public:
    vector<int> parent;
    int find(int x){
        if(parent[x]==x) return x;
        return find(parent[x]);
    }
    bool unions(int i,int j){
        int p1=find(i),p2=find(j);
        if(p1==p2) return 0;
        parent[p1]=p2;
        return 1;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        parent=vector<int>(n+1,0);
        for(int i=1;i<=n;i++) parent[i]=i;
        vector<int> ans(2,0);
        for(auto edge:edges){
            if(!unions(edge[0],edge[1])) return {edge[0],edge[1]};
        }
        return {};
    }
};
