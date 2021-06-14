  int mySqrt(int x) {
         if(x<=1) return x;
        if(x==2 or x==3) return 1;
        
        long long int i=2;
        while(i*i<x)
        {
            i++;
        }
       
            return i*i==x?i:i-1;
    }
