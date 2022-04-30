//kruskal algorithm 
class Solution {
public:
    vector<int> par;
    
    int find(int x){
     if(par[x]==x) return x;
        return find(par[x]);
    }
    bool unions(int x,int y){
        int xp=find(x),yp=find(y);
        if(xp==yp) return 0;
        par[xp]=yp;
        return 1;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<pair<int,pair<int,int>>> edge;
        par=vector<int>(points.size());
        for(int i=0;i<points.size();i++) par[i]=i;
        for(int i=0;i<points.size();i++){
            for(int j=i+1;j<points.size();j++){
                int dis = abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                edge.push_back({dis,{i,j}});
                
            }
        }
        sort(edge.begin(),edge.end());
        int e=0,ms=0;
        for(int i=0;i<edge.size() && e<points.size();i++){
            if(unions(edge[i].second.second,edge[i].second.first))
            {
                e++;
                ms+=edge[i].first;
            }
        }
        return ms;
    }
};

//prims 
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        vector<int> mst(n,0);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> p;
        p.push({0,0});
        int ms=0,e=0;
        while(e<n){
            auto top = p.top();
            int wt = top.first;
            int cur = top.second;
            p.pop();
            if(mst[cur]) continue;
            ms+=wt;
            e++;
            mst[cur]=1;
            for(int i=0;i<n;i++){
                if(mst[i]==0){
                    int d = abs(points[i][0]-points[cur][0])+abs(points[i][1]-points[cur][1]);
                    p.push({d,i});
                  //  e++;
                    
                }
            }
            }
        return ms;
    }
};
