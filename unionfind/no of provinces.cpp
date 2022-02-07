class Solution {
public:
    vector<int> parent;
    int find(int x){
        if(parent[x]==-1) return x;
        return find(parent[x]);
    }
    void unions(int i,int j){
        int p1=find(i),p2=find(j);
        if(p1==p2) return;
        parent[p1]=p2;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        parent = vector<int>(n,-1);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]) unions(i,j);
            }
        }
        int c=0;
        for(int i=0;i<parent.size();i++) {
            if(parent[i]==-1) c++;
        }
        return c;
    }
};
//https://leetcode.com/problems/number-of-provinces/discuss/873741/Simple-C%2B%2B-Solution-oror-Fully-Explained-at-begineers-level-oror-Easy-Understanding-of-UNION-concept
