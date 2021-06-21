/*Chef is stuck in the wavey world of polynomials. You are given all N
 roots of a polynomial P(x)=∏Ni=1(x−ai). The roots are pairwise distinct integers, but they are not given in any particular order.
To help Chef escape, you should answer Q queries (numbered 1 through Q). For each valid i, in the i-th query, you are given an integer xi
 and you have to determine whether P(xi)
 is positive, negative or 0
.*/

#include <iostream>
#include<bits/stdc++.h>
#include<vector>
#include<algorithm>
#define ll long long int
using namespace std;

int main() {
    ll n,q;
    cin>>n>>q;
    vector<ll> v(n);
    for(ll i=0;i<n;i++)
    {
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    while(q--)
    {
        ll xi;
        cin>>xi;
        
        auto ind=lower_bound(v.begin(), v.end(), xi)-v.begin();
        if(v[ind]==xi) cout<<0<<endl;
        else if(ind%2==0) cout<<"POSITIVE"<<endl;
        else cout<<"NEGATIVE"<<endl;
        
    }
    
	return 0;
}
