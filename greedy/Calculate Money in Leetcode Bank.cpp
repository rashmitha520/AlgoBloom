   int totalMoney(int n) {
       if(n<=7) 
           return n*(n+1)/2;
        
        
        int fsum=28,mon=1; 
        int iter=n/7;  
        
      
        int rem=n%7; 
        
        if(rem>0) //for adding remaining numbers less than 7
        {
        int a=mon+iter;
        int N=rem;
        int remsum =( N*(2*a+(N-1)))/2; 
        fsum+=remsum; 
        }
        
        iter--;
        
        while(iter>0) // for next n 7-number sequence
        {
            mon++;
            fsum+=(7)*(2*mon+6)/2;
            iter--;
        }
        
        return fsum;
        
    }
