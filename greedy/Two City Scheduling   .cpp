   static bool cmp(vector<int>& a,vector<int>& b)
    {
        return (a[0]-a[1])<(b[0]-b[1]); //with most negative difference
    }
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(),costs.end(),cmp);
        int n=costs.size()/2;
        int a=0,b=0,sum=0;
        for(auto cost:costs)
        {
            if(a<n)
               { a++;sum+=cost[0];}
            else
               { sum+=cost[1];}
            
        }
      
        return sum;

    }
