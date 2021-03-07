#include <iostream>
#include<bits/stdc++.h>
using namespace std;
class Edge{
    public:
    int source,des,weight;
    
};

bool compare(Edge e1,Edge e2)
{
    return e1.weight<e2.weight;
}
int find(int v,int* parent)
{
    if(parent[v]==v) return v;
    find(parent[v],parent);
}

void kruskal(Edge* input,int n,int e)
{
    //sort
    sort(input,input+e,compare);
    //for outputting mst
    Edge*output=new Edge[n-1];
    int *parent=new int[n];
    for(int i=0;i<n;i++)
        parent[i]=i;
    int count=0;
    int j=0;
    while(count!=n-1)
    {   Edge a=input[j];
        int sorpar=find(a.source,parent);
        int despar=find(a.des,parent);
        if(sorpar!=despar)
        {
          output[count++]=a;
          parent[sorpar]=despar;
              
        }
        j++;
    }
    for(int i=0;i<n-1;i++)
    {
        if(output[i].source<=output[i].des)
            cout<<output[i].source<<" "<<output[i].des<<" "<<output[i].weight<<endl;
        else
            cout<<output[i].des<<" "<<output[i].source<<" "<<output[i].weight<<endl;
    }
    
}
int main() {
    // Write your code here
    int n,e;
    cin>>n>>e;
    Edge *input=new Edge[e];
    for(int i=0;i<e;i++)
    {
    int s,d,w;
    cin>>s>>d>>w;
    input[i].source=s;
    input[i].des=d;
    input[i].weight=w;
    }
  kruskal(input,n,e); 
   return 0;
}
