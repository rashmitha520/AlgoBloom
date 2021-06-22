  int numRescueBoats(vector<int>& people, int limit) {
       int mini=0;
        int l=0,r=people.size()-1;
        sort(people.begin(),people.end());
        while(l<=r)
        {
            if(people[l]+people[r]<=limit)
            {
               
                l++;
            }
            r--;
            
            mini++;
        }
        return mini;
    }
