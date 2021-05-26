class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
      int n=nums.size();vector<int> v;
        int maj1=-1,maj2=-1,c1=0,c2=0;
        if(n<2) return nums;
        for(auto i:nums)
        {
            if(maj1==i) c1++;
            else if(maj2==i) c2++;
            else if(c1==0) {maj1=i;c1=1;}
            else if(c2==0){maj2=i;c2=1;}
            else {c1--,c2--;}
        }
        c1=c2=0;
        for(auto i:nums)
        {
            if(i==maj1) c1++;
            else if(i==maj2) c2++;
        }
        if(c1>(n/3)) v.push_back(maj1);
        if(c2>(n/3)) v.push_back(maj2);
        return v;
    }
};
