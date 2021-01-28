#include <iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
int pre(vector<int> v,int l,int r)
{vector<int> k(v.size());
int sum=0;
    for(int i=l;i<=r;i++)
    {
        sum=sum+v[i];
        k[i]=sum;
    }
    return k[r];
}
int main() {
    int n;
    cin>>n;
    vector<int> a(n),b(n+1);
    for(int i=0;i<n;i++)
     cin>>a[i];
     b[0]=0;
      for(int i=1;i<=n;i++)
            b[i]=pow(2,a[i-1]);
    int count=0;
     for(int i=1;i<=n;i++)
     {
         for(int j=i+1;j<=n;j++)
            if(b[i]*b[j]==pre(b,i,j))
                  count++;
     }


cout<<count<<endl;
}
