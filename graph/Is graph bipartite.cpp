class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
     vector<int> colour(n,0);
        queue<int> q;
        for(int i=0;i<n;i++)
        {
            if(colour[i]) continue;
            //colour uncolored vertice
            colour[i]=1;
            q.push(i);
             while(!q.empty())
             {
                int temp=q.front();
                 //extract all the current vertice's neighbours
                 for(auto neighbour:graph[temp])
                 {  //if not colored put opposite one
                     if(!colour[neighbour])
                         {colour[neighbour]=-colour[temp];q.push(neighbour);}
                     //if same color then not bipartite
                     else if(colour[neighbour]==colour[temp])
                         return 0;
                 }
                 q.pop();
             }
        }
        return 1;
    }
};
