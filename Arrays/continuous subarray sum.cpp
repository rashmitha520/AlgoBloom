/*Given an integer array nums and an integer k, return true if nums has a continuous subarray of size at least two whose elements sum up to a multiple of k, or false otherwise.

An integer x is a multiple of k if there exists an integer n such that x = n * k. 0 is always a multiple of k.

 

Example 1:

Input: nums = [23,2,4,6,7], k = 6
Output: true
Explanation: [2, 4] is a continuous subarray of size 2 whose elements sum up to 6.*/

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
      map<int,int> m;
       int sum=0;
      //case :[0,0] k=0
      //or when sum=0 i.e divisible and if it is not present in map before hand then it will not consider this case and move to next element .
      m[0]=-1;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            if(k!=0) sum=sum%k;
            if(m.count(sum) && (i-m[sum])>1)
            {
               return 1;
            }
            else if(!m.count(sum)) m[sum]=i;
        }
        return 0;
    }
};

//tle
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> prefix(n+1,0);
       
        for(int i=1;i<=n;i++)
        {
          prefix[i]=prefix[i-1]+nums[i-1];  
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=i+2;j<=n;j++)
            {
                if(prefix[j]-prefix[i]==0 || (prefix[j]-prefix[i])%k==0)
                    return 1;
            }
        }
        return 0;
    }
};
