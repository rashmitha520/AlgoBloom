/*There are ‘n’ number of balls in a container. Mr. Sharma and Singh want to take balls out from the container. At each step, Mr. Sharma took ‘k’ balls out of the box and Mr. Singh took one-tenth of the remaining balls. Suppose there are 29 balls at the moment and k=4. Then, Mr. Sharma will take 4 balls and Mr. Singh will take 2 balls (29-4 = 25; 25/10 = 2). If there are less than ‘k’ balls remaining at some moment, then Mr. Sharma will take all the balls which will get the container empty. The process will last until the container becomes empty. Your task is to choose minimal ‘k’ for Mr. Sharma such that Mr. Sharma will take at least half of the balls from the container.*/
#include<bits/stdc++.h>
using namespace std;
//Sharma should have more or equal balls than n/2
long long h(long long s,long long e,long long n,long long &a)
{
   if(s>e)
       return a;
    long long n1=n;
    long long mid=(s+e)/2;
    long long k=mid;
    long long sh=0,si=0;
    while(n1>=k && n1>0)
    {
        sh+=k;
        n1=n1-k;
        si=si+(n1)/10;
        n1=n1-(n1)/10;
    }
    sh+=n1;
//if sh<n/2 then we need to move furthur.
    if(2*sh<n)
    {
       return h(mid+1,n,n,a);
    }
//if sh>=n/2 we note down and check minimum k required for sh to be >= n/2
    else
    {a=k; return h(s,mid-1,n,a);
    }
    
}
int main()
{ ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ; 

    long long n;
    cin>>n;
 //start ,end,total_ele,answer
    cout<<h(1,n,n,n)<<endl;;
     
	return 0;
}

