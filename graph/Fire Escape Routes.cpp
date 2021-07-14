#include <iostream>
#include<vector> 
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
void dfs(vector<vector<int>>& adj,vector<bool>& visites,int& c,int idx)
{
    visites[idx]=true;
    c++;
    for(auto i:adj[idx])
    {
        if(!visites[i])
        {
            dfs(adj,visites,c,i);
        }
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector<vector<int>> adj(n+1);
        
        for(int i=0;i<m;i++)
        {
            int a,b;
            cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        int mod=1e9+7;
        ll ways=0,captains=1;
        vector<bool> visites(n+1,false);
        for(int i=1;i<=n;i++)
        {
            if(visites[i]==0)
            {   int no_of_people=0;
                ways++;
                dfs(adj,visites,no_of_people,i);
                captains=((captains%mod)*(no_of_people%mod))%mod;
            }
        }
       cout << ways<<" "<<captains <<endl;
    }
}
