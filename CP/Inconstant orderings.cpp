#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;
int main(){
int t,t1=0;
cin>>t;
while(t1<t){
int n;
cin>>n;
vector<int> v(n);
for(int i=0;i<n;i++) cin>>v[i];
string ans = "A"; char c='B';
if(n==1) {
    for(int i=0;i<v[0];i++) {ans+=c; c++;}
}
else{
    for(int i=0;i<n;i++){
        if(i%2==0) {
            if(i+1<n && v[i+1]>v[i])
            {int diff = v[i+1]-v[i];
            for(int j=0;j<v[i]-1;j++){
               ans+=c; c++;
              }
              c+=diff;
              ans+=c;
              } 
              else{
                 for(int j=0;j<v[i];j++) {ans+=c; c++;}  
              }
        }
        else{
            string s="A";char c1='B';
            for(int j=0;j<v[i]-1;j++) {s=c1+s; c1++;}
            ans+=s;
            c=ans[ans.length()-1]+1;
            
        }
    }
}

cout<<"Case #"<<t1+1<<": "<<ans<<endl;

t1++;

}
return 0;
}
