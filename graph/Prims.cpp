#include <iostream>
#include<climits>
using namespace std;
int Minn(int v,int *weights,bool *visited)
{
    int mini=-1;
    for(int i=0;i<v;i++)
    {if(!visited[i] &&((weights[mini]>weights[i])||mini==-1))
        mini=i;
     }
   return mini; 
}
void prims(int **edges,int v)
{
    int *parent=new int[v];
    int *weights=new int[v];
    bool *visited=new bool[v];
    for(int i=0;i<v;i++)
    {
        visited[i]=false;
        //As part of prim's algorithm
        weights[i]=INT_MAX;
    }
    //as 0th element is the starting point
    parent[0]=-1;
    weights[0]=0;
    for(int i=0;i<v;i++)
    {
        //pick unvisited vertex with minimum weight
        int minv=Minn(v,weights,visited);
            //mark minv as visited
            visited[minv]=true;
        //if unvisited update with minimum weight and change parent
        for(int j=0;j<v;j++)
        {  //if edge exists 
            if(edges[minv][j]!=0)
            {   //minimising the weight and accordingly assigning the parent
                //parent: from whom the connection comes from
                
                if(weights[j]>edges[minv][j] && visited[j]==false)
                {
                    weights[j]=edges[minv][j];
                    parent[j]=minv;
                }
            }
        }
        
    }
     for(int i=1;i<v;i++)
    {
        if(parent[i]<i)
        {
            cout<<parent[i]<<" "<<i<<" "<<weights[i]<<endl;
        }
        else
        {
            cout<<i<<" "<<parent[i]<<" "<<weights[i]<<endl;
        }
}}

int main() {
    // Write your code here
    int v,e;
    cin>>v>>e;
    int** edges=new int*[v];
    for(int i=0;i<v;i++)
    {
        edges[i]=new int[v];
        for(int j=0;j<v;j++)
            edges[i][j]=0;
    }
    for(int i=0;i<e;i++)
    {
        int f,s,w;
        cin>>f>>s>>w;
        edges[f][s]=edges[s][f]=w;
    }
    prims(edges,v);
    
}
