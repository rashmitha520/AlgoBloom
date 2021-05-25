//tle o{n^2}
#include<bits/stdc++.h>
class Solution {
public:
    int maxProduct(vector<int>& nums) {
       
        int n=nums.size();
        int maxi=INT_MIN;
        for(int i=0;i<n;i++)
        { 
            int prod=nums[i];
              for(int j=i+1;j<n;j++)
              {   maxi=max(prod,maxi);
                  prod*=nums[j];
              }
            maxi=max(prod,maxi);
              
          }
        
        
        return maxi;
    }
};
//O(n)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int curr=1,maxi=INT_MIN;
        int n=nums.size();bool z=0;
        //right traversal
        for(int i=0;i<n;i++)
        {
            curr=curr*nums[i];
            if(curr==0)
            {   
              z=1;
              curr=1;
              continue;  
            }
            maxi=max(curr,maxi);
        }
        curr=1;
        //left traversal
        for(int i=n-1;i>=0;i--)
        {
            curr=curr*nums[i];
            if(curr==0)
            {   
                z=1;
                curr=1;
              continue;  
            }
            maxi=max(curr,maxi);
            
        }
      //when there is 0 in array , then max prod can never be -ve; its either 0 or positive.
        return z==1?max(maxi,0):maxi;
    }
};
//O(n)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxv=nums[0],minv=nums[0],prod=nums[0];
        for(int i=1;i<nums.size();i++)
        {   //maxvalue becomes min and viceversa
            if(nums[i]<0)
                swap(maxv,minv);
            //current max is either the current value(in case of -ve)
            //or is the max_prod_of_previous * current_no;
            maxv=max(nums[i],nums[i]*maxv);
            minv=min(nums[i],nums[i]*minv);
            
            prod=max(prod,maxv);
        }
        return prod;
    }
};
