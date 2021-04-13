/*
1. You are given a number n, representing the number of stairs in a staircase.
2. You are on the 0th step and are required to climb to the top.
3. You are given n numbers, where ith element's value represents - till how far from the step you 
     could jump to in a single move.  
     You can of course jump fewer number of steps in the move.
4. You are required to print the number of different paths via which you can climb to the top.
*/
#include <iostream>
#include<vector>
using namespace std;

int cs(int arr[], int n){
    // write your code here
vector<int> dp(n+1,0);
    dp[n]=1;
    for(int i=n-1;i>=0;i--)
    {
        for(int j=1;j<=arr[i] && (i+j)<n+1;j++)
        dp[i]+=dp[i+j];
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
