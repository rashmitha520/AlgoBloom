//O(n)-Sliding Window   
int minSubArrayLen(int target, vector<int>& nums) {
        vector<int> prefix(nums.size()+1);
        int start=0,fir=0,ans=INT_MAX;
       for(int i=0;i<nums.size();i++)
       {
           fir+=nums[i];
           while(fir>=target)
           {  ans=min(ans,i-start+1);
               fir-=nums[start];
               start++;
               
           }
           
       }
     return ans==INT_MAX?0:ans;
    }

//prefix sum
    int minSubArrayLen(int target, vector<int>& nums) {
        vector<int> prefix(nums.size()+1);
        int start=0,fir=1,ans=INT_MAX;
        for(int i=0;i<nums.size();i++)
        {
            prefix[i+1]=nums[i]+prefix[i];
            if(prefix[i+1]>=target && fir) {start=i+1;fir=0;}
        }
        int n=nums.size();
       for(int i=prefix.size()-1;i>=start;i--)
       {
           for(int j=0;j<i;j++)
           {
               if(prefix[i]-prefix[j]>=target)
                   ans=min(ans,i-j);
           }
       }
     return ans==INT_MAX?0:ans;
    }
