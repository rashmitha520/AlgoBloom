class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l,r,n;
        l=0,r=nums.size()-1,n=nums.size();
        while(l<=r)
        {
           int mid=(l+r)/2;
            if(nums[mid]==target) return mid;
            
            //left rotation
            if(nums[mid]>nums[r])
            {
               if(target<nums[mid] && target>=nums[l]) 
                   r=mid-1;
                else
                    l=mid+1;
                
            }
            //right rotation
           else  if(nums[mid]<nums[l])
            {
               if(target>nums[mid] && target<=nums[r]) 
                   l=mid+1;
                else
                    r=mid-1; 
                
            }
            //no rotation
            else{
              if(target>nums[mid])
                  l=mid+1;
              else
                  r=mid-1;
                  
                
            }
            
        }
        return -1;
    }
};

//2nd way:

class Solution {
public:
    int bs(vector<int>& nums,int s,int e,int t)
    {
        if(e<s || s<0 ||e>nums.size()) return -1;
        if(nums.size()==1) 
        {
            if(nums[0]!=t) return -1;
            else return 0;
        }
        
         while(s<=e)
        {
            int m=(s+e)/2;
            if(nums[m]==t) return m;
            else if(nums[m]<t) s=m+1;
            else e=m-1;
        }
      return -1;
      
    }
  //pivot
    int mini(vector<int>& nums,int n)
    {
       if(n==-1) return -1;
        if(n==0||nums[0]<=nums[n]) return 0;
        int s=0,e=n;
        
        while(s<=e)
        {
            int m=(s+e)/2;
            if(nums[m]>nums[m+1]) return m+1;
            else if(nums[m]>=nums[s]) s=m+1;
            else e=m-1;
        }
       return 0; 
    }
    int search(vector<int>& nums, int target) {
        //index of minimum element.
        int k=mini(nums,nums.size()-1);
        int i=-1;
        
        
        if(nums[k]==target) return k;
        
        if(nums[k]<target && nums[nums.size()-1]>=target)
            i=bs(nums,k+1,nums.size()-1,target);
        
        else if(nums[k]<target && nums[0]<=target)
            i=bs(nums,0,k-1,target);
        
        return i;
    }
};
