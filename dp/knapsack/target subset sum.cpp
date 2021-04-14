#include<bits/stdc++.h>
#include<vector>
#include<climits>
using namespace std;
bool func(vector<int>& v,int tar,int n)
{
bool dp[n+1][tar+1];
for (int i = 0; i <n+1; i++) {
            for (int j = 0; j < tar+1; j++) {
                if (i == 0 && j == 0) {
                    dp[i][j] = true;
                } else if (i == 0) {
                    dp[i][j] = false;
                } else if (j == 0) {
                    dp[i][j] = true;
                } else {
                    if(dp[i - 1][j] == true){
                        dp[i][j] = true;
                    } else {
                        int val = v[i - 1];
                        if (j >= val && dp[i - 1][j - val] == true) {
                            dp[i][j] = true;
                        }
                    }
                }
            }
        }

return dp[n][tar];
}
int main()
{
    int n;vector<int> arr(n);
    for(int i=0;i<n;i++)
     cin>>arr[i];
     int tar;
     cin>>tar;
     if(func(arr,tar,n)) cout<<"true";
     else cout<<"false";
}
