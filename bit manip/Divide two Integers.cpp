  int divide(int divid, int divi) {
    if(divid==INT_MIN and divi==-1) return INT_MAX; 
    int neg=(divid<0 ^ divi<0)?-1:1;
    long i=0;
    long dividend=labs(divid);
    long divisor=labs(divi);
      while(dividend>=divisor)
      {long count=0;
        while(dividend-(divisor<<1<<count)>=0)
        {
            count++;
        }
       i+=1<<count;
       dividend-=divisor<<count;
      }
        return neg*i;
    }
