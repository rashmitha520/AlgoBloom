//time limit exceeded

if(sum==0) return 1;
if(sum<0) return 0;
if(n==0 && sum>=1) return 0;
return countWaysToMakeChange(a,n,sum-a[0])+countWaysToMakeChange(a+1,n-1,sum);

//dp approach
int countWaysToMakeChange(int a[], int no_of_coins, int value){

    int dp[value+1][no_of_coins];int x,y;
   //filling for value=0 for every case
    for(int i=0;i<no_of_coins;i++)
    {
        dp[0][i]=1;
    }
    for(int i=1;i<=value;i++)
    {
        for(int j=0;j<no_of_coins;j++)
        { //when current value included
            x=(i-a[j]>=0)?dp[i-a[j]][j]:0;
            //when omitted
            y=(j>=1)?dp[i][j-1]:0;
            dp[i][j]=x+y;
        }
    }
    
    
return dp[value][no_of_coins-1];
}
