#include <iostream>
using namespace std;
bool dfs(int **edge, int a,int b,bool *visited,int n)
{
    if(edge[a][b]==1) return true;
    if(n<=0) return 0;
    for(int i=0;i<n;i++)
    {
        if(i==a) continue;
        
        else if(edge[a][i]==1 && !visited[i])
            {
            visited[i]=1;
            if(dfs(edge,i,b,visited,n-1))
                 return 1;
            }
    }
    return false;
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
   if(dfs(edges,a,b,visited,V)) cout<<"true";
 else cout<<"false";
    return 0;
}
