#include <iostream>
#include<climits>
using namespace std;
//Should clear the confusion of the v-1 in line no
int Mind(int distance[],bool visited[],int n)
{
    int minV=-1;
    for(int i=0;i<n;i++)
    {
        if(!visited[i] && (minV==-1 || distance[minV]>distance[i]))
            minV=i;
    }
    return minV;
}
void dijs(int** edges,int v){
    bool* visited=new bool[v];
    int* dist=new int[v];
    for(int i=0;i<v;i++)
    {visited[i]=false;dist[i]=INT_MAX;}
    dist[0]=0;
    for(int i=0;i<v-1;i++)
    {
        int minD=Mind(dist,visited,v);
        visited[minD]=true;
        for(int j=0;j<v;j++)
        {
            if(edges[minD][j] && !visited[j]){
                if((edges[minD][j]+dist[minD])<dist[j])
                    dist[j]=edges[minD][j]+dist[minD];
            }
        }
    }
    for(int i=0;i<v;i++)
        cout<<i<<" "<<dist[i]<<endl;
}
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
    dijs(edges,v);
}
