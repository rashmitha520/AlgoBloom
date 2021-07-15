//1. DP method
ll solve(vector<ll> arr,ll n)
{
    ll count;
    vector<ll> dp(n);
    dp[0]=1;
    count=dp[0];
    for(int i=1;i<n;i++)
    {
        if(arr[i]>=arr[i-1])
        {
            dp[i]=dp[i-1]+1;
            count+=dp[i];
        }
        else
        {
            dp[i]=1;
            count+=dp[i];
        }
    }
    
    return count;
}

//2nd method
ll solve(vector<ll> arr,ll n)
{
    ll count=0,l=1;
   
    for(int i=1;i<n;i++)
    {
        if(arr[i]>=arr[i-1])
        {
            l++;
        }
        else
        {
           count +=(l*(l+1)/2);
           l=1;
        }
    }
    count +=(l*(l+1)/2);
    
    return count;
}
