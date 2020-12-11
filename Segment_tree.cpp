
#include <iostream>
#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
ll tree[300000];
ll arr[200000];
//construct segment tree
//checked
void build(ll i,ll si,ll en)
{
    if(si==en)
    {
        tree[i]=arr[si];
       // return;
    }
    else
    {
    ll mid=(si+en)/2;
    build(2*i,si,mid);
    build(2*i+1,mid+1,en);
    tree[i]=tree[2*i]+tree[2*i+1];
    }
    
}
void update(ll v,ll l,ll r,ll pos,ll val)
{
    if(l==r)
    {
       tree[v]= tree[v]-arr[pos]+val;
       arr[pos]=val;
      // return;
    }
    else
    {
      ll mid=(l+r)/2;
      if(l<=pos && pos<=mid)
      update(2*v,l,mid,pos,val);
      else
      update(2*v+1,mid+1,r,pos,val);
      tree[v]=tree[2*v]+tree[2*v+1];
    }
}
ll query(ll i, ll st, ll en, ll l, ll r)
{
    if(r<st or en<l) return 0;
    //doubt
    if(l<=st and en<=r) return tree[i];
    ll mid=(st+en)/2;
    ll p1=query(2*i,st,mid,l,r);
    ll p2=query(2*i+1,mid+1,en,l,r);
    return p1+p2;
}
int main()
{
    int n;
    cin>>n;
    for(ll i=1;i<=n;i++)
    {
        ll g;
       cin>>g;
       arr[i]=g%2==0?1:0;
    }
    build(1,1,n);
    ll queries;
    cin>>queries;
    while(queries--)
    {
        int q,l,r;
        cin>>q>>l>>r;
        if(q==0)
        { 
          update(1,1,n,l,r%2==0?1:0);
        }
        else if(q==1)
        {
        //query(ll v,ll l,ll r,ll tl,ll tr)
         cout<<query(1,1,n,l,r)<<endl;
        }
        else
        {
         cout<<(r-l+(l!=r?1:0))-query(1,1,n,l,r)<<endl;
        }
    }
    return 0;
}
