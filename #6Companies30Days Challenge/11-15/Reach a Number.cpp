  int reachNumber(int target) {
        target= abs(target);
        int sum=0,steps=1;
        if(target==0) return 0;
        while(sum<target){
            sum+=steps;
            steps++;
        }
        while((sum-target)%2){
           
            sum+=steps;
             steps++;
        }
        return steps-1;
    }
