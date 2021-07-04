  #define mod 1000000007
//even indices : 5 ; odd indices: 4
//if n=3 : 4^2*5^1 : 80
//if n=4 : 4^2*5^2 - 400
    long long power(long long x,long long n,long long m)
    {
        if(n==0) return 1;
        if(n%2==0)
        {
            return power((x%mod*x%mod)%m,n/2,m);
        }
        return (x*power((x%mod*x%mod)%m,(n-1)/2,m))%m;
    }
    int countGoodNumbers(long long n) {
        long long four=n/2,five=n-four;
        return( power(4,four,mod)%mod*power(5,five,mod)%mod)%mod;
        
    }
