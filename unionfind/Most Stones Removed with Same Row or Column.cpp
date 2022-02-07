class Solution {
public:
    vector<int> parent;
    int find(int x){
        if(parent[x]==x) return x;
        return find(parent[x]);
    }
    void uni(int i,int j){
        int p1 = find(i),p2=find(j);
        if(p1==p2) return;
        parent[p1]=p2;
    }
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        parent= vector<int> (n,0);
        for(int i=0;i<n;i++) parent[i]=i;
        int c=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(stones[i][0]==stones[j][0]||stones[i][1]==stones[j][1])
                    uni(i,j);
            }
        }
        for(int i=0;i<parent.size();i++) 
        {
            if(parent[i]!=i) c++;
        }
        return c;
    }
};
