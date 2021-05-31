 int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start=0,sum=0,gass=0;
        for(int i=0;i<gas.size();i++)
        {
            sum+=(gas[i]-cost[i]);
            gass+=(gas[i]-cost[i]);
            if(gass<0)
            {
                start=i+1;
                gass=0;
            }
        }
        return sum>=0? start:-1;
    }
