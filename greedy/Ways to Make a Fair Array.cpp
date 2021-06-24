class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int n=nums.size();
        vector<int> even(n+1,0),odd(n+1,0);
        
          for(int i=0;i<n;i++)
             {
              if(i%2==0)
              {   odd[i+1]=odd[i];
                  even[i+1]=even[i]+nums[i];
              }
              else
              {odd[i+1]=odd[i]+nums[i];
                even[i+1]=even[i];
              }
             
             }
        
        int count=0;
        for(int i=1;i<=n;i++)
        {
           int intactOSum= odd[i-1];
           int intactESum= even[i-1];
           int osum = intactOSum + even[n]-even[i];
           int esum = intactESum + odd[n]-odd[i];
           if(osum==esum) count++;   
           
        }
        
       return count; 
    }
  
  
  //TLE
  
   int waysToMakeFair(vector<int>& nums) {
        vector<vector<int>> subsets;
       for(int i=0;i<nums.size();i++)
       {  vector<int> v;
            for(int j=0;j<nums.size();j++)
            {
                if(i==j) continue;
                v.push_back(nums[j]);
            }
        subsets.push_back(v);
       }
        int count=0;
      for(auto subset:subsets)
      {
          int esum=0,osum=0;
          for(int i=0;i<subset.size();i++)
          {
              if(i%2) osum+=subset[i];
              else esum+=subset[i];
          }
          if(esum==osum) count++;
      }
        return count;
    }
