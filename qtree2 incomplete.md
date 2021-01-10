###### Q2.Given a tree  with N nodes, and edges numbered 1, 2, 3...N-1. Each edge has an integer value assigned to it, representing its length.

Perform the following operations:

**DIST (a, b)** : ask for the distance between node a and node b
or
**KTH (a ,b, k)** : ask for the k-th node on the path from node a to node b
>(**source**:<a href="https://www.spoj.com/problems/QTREE2/">SPOJ-Qtree2 problem</a>)

```CPP
#include <iostream>
#include <math.h>
#include<vector>
using namespace std;
int orig[N],st[N*6],depth[N],pa[LN][N];
//build the segment tree
void build_seg(int i,int s,int e)
{ if(s==e-1)
   {
    st[i]=orig[e-1];
    return;
   }
   int mid=(s+e)/2;
   //for the left part
   build_seg(2*i,s,m);
   //for the right part
   build_seg(2*i+1,m+1,e);
   //the node stores the sum of its children
   st[i]=st[2*i]+st[2*i+1];
    
}
void update_seg(int v,int l,int r,int pos,int val)
{. //if only one element in st:
    if(l==r)
      {st[v]=val;return;}
      
      int mid=(l+r)/2;
     //if the updation is before or at mid index:
      if(pos<=mid)
      update_seg(v*2,l,mid,pos,val);
     //if its after the mid:
      else
      update_seg(2*v+1,mid+1,r,pos,val);
      //the node will store the sum of children
      st[v]=st[2*v]+st[2*v+1];
}
int query_tree(int node,int l,int r,int i,int j)
{
 if(i>r||j<l||l>r) return 0;
 if(l<=i || r>=j)  return st[node];
 int mid=(l+r)/2;
 return (query_tree(2 * node, l, mid, i, j) + query_tree(2 * node + 1, mid + 1, r, i, j));
   
    
}
int query_up(int u,int v)
{
  if(u==v) return 0;
    int uc,vc=chIndex[v],res=-1;
    while(true)
    {
    uc=chIndex[u];
    while(true)
    {
    if(u==v) break;
    query_tree(1,0,ptr,posInBase[v]+1,posInBase[u]+1);
    if(qt[1]>res) res=qt[1];
    break;
    }
    query_tree(1, 0, ptr, posInBase[chHead[uchain]], posInBase[u]+1);
    if(qt[1]>res) res=qt[1];
    u=chHead[uc];
    u=pa[0][u];
    }
    return res;  
}
int lca(int u,int v)
{
    if(depth[u]<depth[v]) swap(u,v);
    int diff=depth[u]-depth[v];
    for(int i=0;i<LN;i++)
    if((diff>>i&1)) u=pa[i][u];
    if(u==v) return u;
    for(int LN-1;i>=0;i--)
    {
        if(pa[i][u]!=pa[i][v])
          u=pa[i][u],v=pa[i][v];
    }
    return pa[0][u];
    
}
void hld()
{
    
}
void dfs(int cur,int prev,int depths)
{
 pa[0][cur]=prev;
 depth[cur]=depths;
 subtree_size[cur]=1;
 for(int i:adj[cur].size())
 {
     if(adj[cur][i]!=prev)
       {
           //otherEnd[indexes[cur][i]]=adj[cur][i];
           dfs(adj[cur][i],cur,depths+1);
           subtree_size[cur]+=subtree_size[adj[cur][i]];
           
       }
 }
}
//function to find the distance between u and v
int dist(int u,int v)
{
 int LCA=lca(u,v);
 int chain1=query_up(u,LCA);
 int chain2=query_up(v,LCA);
 return chain+chain2;
}
//to return kth node in btw a nd b nodes
int kth(int a,int b,int k)
{
   
}

int main() {

	return 0;
}
```
