class Solution {
public:
    int nthUglyNumber(int n) {
       if(n<=0) return 0;
        if(n==1) return 1;
        vector<int> v(n);
        v[0]=1;int t2=0,t3=0,t5=0;
        for(int i=1;i<n;i++){
            v[i]=min(v[t2]*2,min(v[t3]*3,v[t5]*5));
            if(v[i]==v[t2]*2) t2++;
            if(v[i]==v[t3]*3) t3++;
            if(v[i]==v[t5]*5) t5++;
        }
        return v[n-1];
    }
};
