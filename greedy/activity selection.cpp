#include<bits/stdc++.h>
#include<vector>
using namespace std;
struct act
{
    int s,e;
};
bool comp(act s1,act s2){
   return s1.e<s2.e; 
}
int maxi(act a[],int n)
{ int j=0;int c=1;
    sort(a,a+n,comp);
    for(int i=1;i<n;i++)
    {
        if(a[i].s>=a[j].e)
            {j=i;c++;}
    }
 return c;
}
int main()
{
    //Write your code here
    int n;
    cin>>n;
    act a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i].s>>a[i].e;
    }
    cout<<maxi(a,n);
    
    
    return 0;
}
