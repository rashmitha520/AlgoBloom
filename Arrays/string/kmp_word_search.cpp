#include<string>
#include<stdio.h>
using namespace std;
int kmp(string s,string t)
{
    int m=s.length(),n=t.length();
    int i=0,j=0,dp[m];
    int ind=-1;
    while(i<m && j<n)
    {
      if(s[i]==t[j]){dp[i]=j+1;i++,j++;}  
    else
    {
        if(j!=0){j=dp[j-1];i++;}
        if(j==0){dp[i]=0;i++;} 
    }
    }
    if(j==n) return i-j;
    return -1;
}
int findString(char s[], char t[]) {
    // Write your code here
    string p="",te="";
for(int i=0;s[i]!='\0';i++)
    p+=s[i];
for(int i=0;t[i]!='\0';i++)
    te+=t[i];
return kmp(p,te);
}

