#include <iostream>
#include<vector>
#include<climits>
#include<bits/stdc++.h>
using namespace std;

int cs(int arr[], int n){
    // write your code here
    int *dp = new int[n+1]; 
     dp[n]=0;    
     for(int i=n-1;i>=0;i--)     
     {  int mini=INT_MAX;
         if(arr[i]>0)
             {
                 int mini=INT_MAX;
                for(int j=1;j<=arr[i] && (i+j)<n+1;j++)
                  {
                    if(dp[i+j]!=NULL)
                       mini=min(dp[i+j],mini);
                 }
            
               if(mini!=INT_MAX)
                dp[i]=mini+1;
               else dp[i]=NULL;
         
            }
          
     }
    return dp[0];
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0 ; i < n ;i++){
        cin>>arr[i];
    }
    cout<<cs(arr,n)<<endl;
}
