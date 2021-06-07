   int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size(),maxi=1,ans=0;
        vector<int> len(n,1),count(n,1);
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
               if(nums[i]>nums[j])
                {
                  if(len[j]+1>len[i])
                {
                    count[i]=count[j];
                     len[i]=len[j]+1;
                }
              else if(len[j]+1==len[i])
                {
                    count[i]+=count[j];
                }
               }
                
            }
            maxi=max(maxi,len[i]);
        }
        for(int i=0;i<n;i++)
        {
            if(len[i]==maxi)
                ans+=count[i];
        }
        return ans;
    }
