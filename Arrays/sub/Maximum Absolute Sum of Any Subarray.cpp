//kadane algorithm

int maxAbsoluteSum(vector<int>& nums) {
        int maxsum=0,minsum=0,negk=0,posk=0;
        for(int i:nums)
        {
            negk+=i;
            posk+=i;
            if(negk>0) negk=0;
            if(posk<0) posk=0;
            
            maxsum=max(maxsum,posk);
            minsum=min(minsum,negk);
        }
        return max(maxsum,abs(minsum));
    }
