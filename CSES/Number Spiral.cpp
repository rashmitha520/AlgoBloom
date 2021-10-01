#include <iostream>
#define ll long long int
using namespace std;

int main() {
    ll t;
    cin>>t;
while(t--)
  { 
   ll r,c;
   cin>>r>>c;
   if(r>=c)//takes max in the case
   {
       if(r%2==0) cout<<r*r-c+1<<endl;
       else cout<<(r-1)*(r-1)+c<<endl;
   }
   else
   {
       ll t=r;
       r=c;
       c=t;
       if(r%2==1) cout<<r*r-c+1<<endl;
       else cout<<(r-1)*(r-1)+c<<endl;
   }
   
   }
	return 0;
}
