//july long challenge - bit problem
#include <iostream>
#include<vector> 
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {
	ll t;
	cin>>t;
	while(t--)
	{
	    ll n,k,ans=0;
	    cin>>n>>k;
	    vector<ll> arr(n);
	    for(ll i=0;i<n;i++)
	      cin>>arr[i];
	      ll count=0;
	   for(int i=0;i<32;i++)
	   {
	       for(int j=0;j<n;j++)
	       {if(arr[j]!=0)
	          { if(arr[j]&1)
	            count++;
	            arr[j]=arr[j]>>1;}
	       }
	       if(count%k) ans+=((count/k)+1);
	       else ans+=(count/k);
	       count=0;
	   }
	   cout << ans <<endl;
	    
	}
	return 0;
}
