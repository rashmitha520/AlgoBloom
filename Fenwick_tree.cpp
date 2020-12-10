#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define MAX 100005 
int b[MAX];

void update_even(int idx,int count)
{ // i&(-i)=> least significant digit
// we add i=i+lsd when we need to go to parent
    for(int i=idx;i<MAX;i+=i&(-i))
    {
        b[i]+=count;
    }
}
int query(int idx)
{ int sum_even=0;
    while(idx)
    { 
        sum_even+=b[idx];
        // we do i=i-lsd when we need to go to child
         idx-=(idx & (-idx));
    }
    return sum_even;
}

int a[MAX];
int main() {
	int n;
    cin>>n;
    //doubt
    for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            if(a[i]%2==0)
            update_even(i,1);
        }

       
    int queries;
    cin>>queries;
    int q,l,r;
    while(queries--)
    {
        
        cin>>q>>l>>r;
        if(q==0)
        {
         if(a[l]%2==0 && r%2==1)
           update_even(l,-1);
         else if(a[l]%2==1 && r%2==0)
           update_even(l,1);
          a[l]=r;
        }
        else if(q==1)
        {
         int cnt=query(r)-query(l-1);
         cout<<cnt<<endl;
        }
        else
        {
          int cnt=query(r)-query(l-1);
         cout<<(r-l+1)-cnt<<endl;
        }

    }
    return 0;
}
