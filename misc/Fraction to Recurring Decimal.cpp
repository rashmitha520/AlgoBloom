string fractionToDecimal(int numerator, int denominator) {
      if(numerator==INT_MIN and denominator==-1) return "2147483648";
        long long q=numerator/denominator;
       long long r=numerator%denominator;
        string s;
        if(numerator==0) return "0";
        
        map<long long,long long> m;
       if((numerator<0 ^ denominator<0) and q==0) s+='-';
        s+=to_string(q);
        if(r==0) return s;
        else
        {
            s+='.';
            while(r!=0)
            { if(m[r]!=0)
            {   long long l=s.length();
                s.insert(m[r],"(");
                s+=")";
                break;
            }
            else
               { 
                m[r]=s.length();
                r=r*10;
                q=r/denominator;
                r=r%denominator;
                if(q<0 ) q=q*-1;
                s+=to_string(q);
            }
            }
        }
        return s;
    }
