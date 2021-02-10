class Solution {
public:
    int thirdMax(vector<int>& nums) {
      long fir=LONG_MIN,sec=LONG_MIN,thi=LONG_MIN;
        for(int i=0;i<nums.size();i++)
        {   if(fir==nums[i]||sec==nums[i]||thi==nums[i])
             continue;
            if(nums[i]>fir)
            {   thi=sec;
                sec=fir;
                fir=nums[i];
                
            }
            else if(nums[i]>sec)
            {
                thi = sec;
                sec=nums[i];
            }
            else if(nums[i]>thi)
            {
                thi=nums[i];
            }
        }
        return thi==LONG_MIN?fir:thi;
        
    }
};
