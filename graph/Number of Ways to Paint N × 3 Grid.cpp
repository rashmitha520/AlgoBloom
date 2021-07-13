  int numOfWays(int n) {
        long  two=6,three=6;
        long mod=1e9+7;
        for(int i=2;i<=n;i++)
        {
            long temp = two;
            two = (3*two+2*three)%mod;
            three = (2*temp+2*three)%mod;
        }
        return (two+three)%mod;
    }
