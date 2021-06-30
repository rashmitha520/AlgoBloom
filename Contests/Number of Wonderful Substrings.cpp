    long long wonderfulSubstrings(string word) {
        int mask=0,res=0;
        map<int,int> count;
        count[0]=1;
        for(auto c:word)
        {
            mask^=(1<<(c-'a'));
            res+=count[mask]; //for even num
            for(int i=0;i<10;i++)
            {
                res+=count[mask^(1<<i)];//for odd num
            }
            count[mask]++;
        }
        return res;
    }
