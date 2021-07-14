#include <iostream>
#include<vector> 
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
void dfs(vector<vector<int>>& adj,int i,int j,vector<vector<bool>>& visited,int& banks,int str)
{   if(i<0||j<0||i>=adj.size()||j>=adj[0].size()||visited[i][j]==1||adj[i][j]!=str) return ;
    visited[i][j]=1;
    banks++;
    dfs(adj,i+1,j,visited,banks,str);
     dfs(adj,i-1,j,visited,banks,str);
      dfs(adj,i,j+1,visited,banks,str);
     dfs(adj,i,j-1,visited,banks,str);
    
}
int main() {
int n,m;
cin>>n>>m;
vector<vector<int>> adj(n,vector<int>(m));
for(int i=0;i<n;i++)
{
    for(int j=0;j<m;j++)
      cin>>adj[i][j];
}

vector<vector<bool>> visited(n,vector<bool>(m,false));
int strength=0,state=0;
for(int i=0;i<n;i++)
{
    for(int j=0;j<m;j++)
    {
        if(!visited[i][j])
        {   int c=0;
            dfs(adj,i,j,visited,c,adj[i][j]);
            if((c==state && strength>adj[i][j]) || c>state)
            {
                strength=adj[i][j];
                state=c;
            }
        }
    }
}
cout <<strength<<" "<<state<<endl;
	return 0;
}
