  static   bool cmp(pair<int,int>&a ,pair<int,int>& b)
    {
        return a.first+a.second>b.first+b.second;
    }
    int stoneGameVI(vector<int>& a, vector<int>& b) {
        int al=0,bob=0,n=a.size();
       vector<pair<int,int>> q;
       for(int i:a) al+=i;
       for(int i:b) bob+=i;
        for(int i=0;i<n;i++)
        {
            q.push_back({a[i],b[i]});
            
        }
        sort(q.begin(),q.end(),cmp);
        bool turn=0;
        for(int i=0;i<q.size();i++)
        {
            pair<int,int> fr=q[i];
         
            if(turn==0)
            {
            al+=fr.second;}
            else
            {
               
                bob+=fr.first;
            }
            turn=!turn;
        }
        if(al==bob) return 0;
        if(al<bob) return -1;
        return 1;
    }
