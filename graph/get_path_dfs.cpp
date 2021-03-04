#include <iostream>
#include<vector>
using namespace std;
vector<int> dfs(int **edge, int a,int b,bool *visited,int n)
{
    if(a==b) {
        vector<int> ans;
       // ans.push_back(b);
        ans.push_back(a);
        
        return ans;
    }
    
    for(int i=0;i<n;i++)
    {
       
        
       if(edge[a][i]==1 && !visited[i] && a!=i)
            {
            visited[i]=1;
            vector<int> ans;
            ans=(dfs(edge,i,b,visited,n));
            if(ans.size()!=0)
                {ans.push_back(a);
                return ans;
                }
                
            }
    }
     vector<int> ans;
    return ans;
   
}
int main() {
    // Write your code here
     int V, E;
    cin >> V >> E;
    if(V==0)
        return 0;
    int **edges=new int*[V];
    for(int i=0;i<V;i++)
    {
        edges[i]=new int[V];
    }
    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {
            edges[i][j]=0;
        }
    }
    for(int i=0;i<E;i++)
    {
        int start,end;
        cin>>start>>end;
        edges[start][end]=1;
        edges[end][start]=1;
    }
    bool*visited=new bool[V];
    for(int i=0;i<V;i++)
    {
        visited[i]=false;
    }
    int a,b;
    cin>>a>>b;
    visited[a]=1;
   vector<int> c=(dfs(edges,a,b,visited,V)) ;
    if(c.size()!=0)
for(int i=0;i<c.size();i++) cout<<c[i]<<" ";
        
    return 0;
}
