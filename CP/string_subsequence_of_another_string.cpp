#include <iostream>
#include<vector> 
#include<set>
#include<map>
#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;


int main() {
string s,t="QAQ";
cin>>s;

int m=s.length(),n=t.length();
vector<vector<int>> dp(m+1,vector<int>(n+1,0));
for(int j=0;j<=n;j++) dp[0][j]=0;
for(int i=0;i<=m;i++) dp[i][0]=1;

for(int i=1;i<=m;i++){
    for(int j=1;j<=n;j++){
        if(s[i-1]==t[j-1]){
         dp[i][j]=dp[i-1][j-1]+dp[i-1][j];  
        }
        else{
            dp[i][j]=dp[i-1][j];
        }
    }
}
cout<<dp[m][n];
}
