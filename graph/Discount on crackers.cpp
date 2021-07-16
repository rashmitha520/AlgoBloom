#include <iostream>
#include<vector> 
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

bool dfs(vector<int> adj[],int s,int e,vector<bool>& vis)
{
  vis[s]=1;
  
  for(auto i:adj[s])
  {   if(e==i) return true;
     if(!vis[i])
       {
           if(dfs(adj,i,e,vis)) return true;
       }
  }
  return false;
}
void solve()
{
 string s,t;
	    int m;
	    cin>>s>>t;
	    cin>>m;
	    vector<int> adj[26];
	    for(int i=0;i<m;i++)
	    {
	        string inp;
	        cin>>inp;
	        adj[inp[0]-'a'].push_back(inp[3]-'a');
	        
	        
	    }
	    
	    
	    if(s.length()!=t.length())
	    cout<<"NO"<<endl;
	    else
	    {
	   bool flag=1;
	   for(int i=0;i<s.length();i++)
	    {
	       if(s[i]!=t[i])
	       {   vector<bool> vis(26,false);
	           flag= dfs(adj,s[i]-'a',t[i]-'a',vis);
	           if(!flag) break;
	       }
	    }
	    if(flag) cout<<"YES"<<endl;
	    else cout<<"NO"<<endl; 
	        
	    }  
}
int main() {
	int test;
	cin>>test;
	while(test--)
	{   
	  
	    
	    solve();
	    
	}
	return 0;
}
