class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n);
        //blank space
        dp[0]=1;
        //lis initially
        int omax=1;
        
        for(int i=1;i<n;i++)
        { int maxi=0;
          for(int j=0;j<i;j++)
          {  //faith
              if(nums[j]<nums[i])
              {    //if lis of dp[j]>maxi
                  if(dp[j]>maxi)
                    maxi=dp[j];
                
              }
              
          }
         
           dp[i]=maxi+1;
         omax=max(dp[i],omax);
        }
        return omax;
    }
};

//O(nlogn) 
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp;
        dp.push_back(nums[0]);
        for(int i=0;i<nums.size();i++)
        {
            if(dp.back()<nums[i])
                dp.push_back(nums[i]);
            else
            {
                int j=lower_bound(dp.begin(),dp.end(),nums[i])-dp.begin();
                dp[j]=nums[i];
            }
            
        }
        return dp.size();
    }
