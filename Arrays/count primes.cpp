//TLE
class Solution {
public:
    bool prime(int k)
    { if(k<=1) return 0;
      if(k==2) return 1;
        for(int i=2;i<=sqrt(k);i++)
        {
            if(k%i==0) return false;
        }
        return true;
    }
    int countPrimes(int n) {
        if(n<=2) return 0;
        int c=1;
        for(int i=3;i<n;i++)
        {   if(i%2==0) continue;
            else if(prime(i)) c++;
        }
        return c;
    }
};

//SIEVE OF ERATOSTHENES
class Solution {
public:
    int countPrimes(int n) {
      vector<bool> prime(n,1);
       for(int i=2;i*i<n;i++)
       {
           if(!prime[i]) continue;
           //mark all the multiples of i as non-prime
           //why from i*i ? eg :- 3*3=9 then what about 3*2?
           //Ans: already marked false by 2's iteration.
           // 2*2=4; 4+2=6;so already marked false.
           for(int j=i*i;j<n;j+=i)
               prime[j]=0;
       }
        int c=0;
        for(int i=2;i<n;i++)
            if(prime[i]) c++;
        return c;
        
    }
};
