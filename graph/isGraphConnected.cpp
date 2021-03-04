#include <iostream>
#include<vector>
using namespace std;
void dfs(int **edge, int a,bool *visited,int n)
{
   
   if(a==n) return; 
    for(int i=0;i<n;i++)
    {
       
        
       if(edge[a][i]==1 && !visited[i] && a!=i)
            {
            visited[i]=1;
            (dfs(edge,i,visited,n));
            
                
            }
        
    }
     
    
   
}
int main() {
    // Write your code here
     int V, E;
    cin >> V >> E;
    if(V==0)
       { cout<<"true";return 0;}
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
   b=0;
    visited[0]=1;
   
  (dfs(edges,0,visited,V)) ;
   for(int i=0;i<V;i++)
   {
       if(visited[i]==0) {cout<<"false";b=1;break;}
   }
      if(b==0) cout<<"true";  
    
    return 0;
}
