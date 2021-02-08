//hashmap approach
class Solution {
public:
    int findLHS(vector<int>& nums) {
       int n=nums.size();
       map<int,int> u;
        for(int i=0;i<n;i++)
        {
          u[nums[i]]++; 
        }
        int res=0;
        for(int i=0;i<n;i++)
        {
            if(u[nums[i]]!=0 && u[nums[i]+1]!=0)
                res=max(res,u[nums[i]]+u[nums[i]+1]);
        }
       return res; 
    }
};
