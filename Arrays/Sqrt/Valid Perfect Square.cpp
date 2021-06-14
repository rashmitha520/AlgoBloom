 bool isPerfectSquare(int num) {
        long long int s=1,e=num/2;
        if(num==1) return 1;
        while(s<=e)
        {
            long long int mid=(s+e)/2;
            if(mid*mid==num) return true;
            else if(mid*mid<num) s=mid+1; //if current sqr(mid) is less it needs to be updated
            else e=mid-1; //if more should be decreased
        }
        return false;
    }
