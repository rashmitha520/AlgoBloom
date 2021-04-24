
#include <iostream>
#include<map>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
class Graph
{ int vert;
  map<int,list<int>> adj;
  map<int,bool> visited;
  public:
  Graph(int v)
  { vert=v;

  }
  bool dfs();//to perform dfs
  void add_edge(int src,int des);
  bool dfs_util(int i,int parent,map<int,bool>& visited);
};

bool Graph::dfs()
{
 for(int i=0;i<vert;i++)
 {
   if(!visited[i] && dfs_util(i,-1,visited))
   {
       return 1;
   }
 }
return 0;
}
bool Graph::dfs_util(int i,int parent,map<int,bool>& visited)
{
  visited[i]=true;
  for(auto j:adj[i])
  {
    if(!visited[i])
    {
      if(dfs_util(j,i,visited)) return true;
    }
    else if(j!=parent) {return true;}
  }
  return false;
}

void Graph::add_edge(int src, int des)
{
  adj[src].push_back(des);
  adj[des].push_back(src);
}
int main() {
  Graph g(2);
 g.add_edge(0,1);
 //g.add_edge(1,0);
 
  if(g.dfs()) cout<<"has a cycle"<<endl;
  else cout<<"no";
}
