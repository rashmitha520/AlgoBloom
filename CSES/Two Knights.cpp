#include <iostream>
#define ll long long int
using namespace std;

int main() {
   ll n;
   cin>>n;
 for(ll i=1;i<=n;i++)
 {
     ll s=i*i;
     cout<<s*(s-1)/2 - 4*(i-1)*(i-2)<<endl;
 }
}
