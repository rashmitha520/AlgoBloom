    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n=dist.size();
       
       for(int i=0;i<n;i++)
       {
           dist[i]=ceil((double)dist[i]/speed[i]); //time to reach the city
       }
        sort(dist.begin(),dist.end());
        int mini=0;
        for(int i=0;i<n;i++)
        {
            if(dist[i]>mini) mini++; //if time is more than current time
            else return mini;//if it already reached
        }
        return mini;
    }
