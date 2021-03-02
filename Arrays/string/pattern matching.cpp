
//brute force: O(N*M) complexity
#include <iostream>
#include<string>
using namespace std;
int main() {
  string s,t;
  cin>>s>>t;
  int m=s.length(),n=t.length();
  int k;
  for(int i=0;i<m-n;i++)
  { if(s[i]!=t[0]) continue;
   bool isp=1;
   k=i;
    for(int j=0;j<n;j++)
    {
      if(s[j+i]!=t[j]) {
        isp=0;
        break;
        };
      
    }
    if(isp) cout<<k+1;
    else cout<<0;
  }
}
