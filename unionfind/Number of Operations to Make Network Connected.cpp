class Solution {
public:
    vector<int> par;
    int find(int x){
        if(par[x]==x) return x;
        return find(par[x]);
    }
    void add(int i,int j){
        int p1=find(i),p2=find(j);
        if(p1==p2) return;
        par[p1]=p2;
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        par=vector<int>(n);
        if(n-1>connections.size()) return -1;
        for(int i=0;i<n;i++) par[i]=i;
        for(int i=0;i<connections.size();i++){
            int a=connections[i][0],b=connections[i][1];
            add(a,b);
        }
        int c=0;
        for(int i=0;i<n;i++){
            if(par[i]==i) c++;
        }
        return c-1;
    }
};
