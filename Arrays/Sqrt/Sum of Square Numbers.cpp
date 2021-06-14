  bool judgeSquareSum(int c) {
       map<long long int,long long int> m;
        for(long long int i=0;i*i<=c;i++)
        {
           
            m[i*i]++;
            if(m.find(c-i*i)!=m.end()) return true;
        }
        return false;
    }
