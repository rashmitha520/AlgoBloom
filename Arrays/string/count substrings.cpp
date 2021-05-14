
/*
count no of substrings without the occurrence of a specific element k
eg: s="baa" k="b"
output: 3 -> "a","a","aa"
s="ababaa" k="b"
output: 5 -> "a","a","a","a","aa"
by formula : no of substrings of n-size string : n*(n+1)/2
*/
#include <iostream>
#include<string>
#include<vector>
using namespace std;
int main() {
    string s; vector<int> v;
    cin>>s; 
    char k;cin>>k;
    int sum=0;int c=0;
    for(int i=0;i<s.length();i++)
      {
          while(s[i]!=k && i<s.length()) {c++;i++;}
          if(s[i]==k) {v.push_back(c);c=0;}
      }
      v.push_back(c);
      int n=s.length();
      for(int i=0;i<v.size();i++)
    {  int n=v[i]; sum=sum+(n*(n+1)/2) ; }
    cout<<sum;
}
