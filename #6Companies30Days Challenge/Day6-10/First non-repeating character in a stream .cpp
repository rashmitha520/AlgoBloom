// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string a){
		    // Code here
		    vector<int> v(26,0); 
		
		    queue<int> q;
		    for(int i=0;i<a.length();i++){
		        v[a[i]-'a']++;
		        if(v[a[i]-'a']==1) q.push(a[i]);
		       
		            while(!q.empty() && v[q.front()-'a']!=1) q.pop();
		            if(q.empty()) a[i]='#';
		            else a[i]=q.front();
		   
		    }
		    return a;
		    
		}

};
