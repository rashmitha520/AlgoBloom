    #define m 1000000007
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        
        
        sort(horizontalCuts.begin(),horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());
        
       
        horizontalCuts.push_back(h);
       
        verticalCuts.push_back(w);
        
      long long int maxH=horizontalCuts[0],maxW=verticalCuts[0];
        
        for(int i=1;i<horizontalCuts.size();i++)
             maxH=(maxH<(horizontalCuts[i]-horizontalCuts[i-1] ))?(horizontalCuts[i]-horizontalCuts[i-1]):maxH;

;
        
        
         for(int i=1;i<verticalCuts.size();i++)
             maxW=(maxW<(verticalCuts[i]-verticalCuts[i-1]))?verticalCuts[i]-verticalCuts[i-1]:maxW;
        
        
        return ((maxW%m)*(maxH%m))%m;
        
        
    }
