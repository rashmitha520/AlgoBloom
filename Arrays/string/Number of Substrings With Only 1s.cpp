   #define mod 1000000007
               
    int numSub(string s) {
       long c=0;long num=0;
       for(long i=0;i<s.length();i++)
       {
          if(s[i]=='1') c++;
          else 
          {
              num = num + (c * (c+1))/2;
              c=0;
           }
         
       }
        return (num+(c * (c+1))/2)%mod;//imp
    }
