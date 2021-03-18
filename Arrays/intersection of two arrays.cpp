class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> a,b;vector<int> v;
        for(int i=0;i<nums1.size();i++)
        {
            a.insert(nums1[i]);
        }
        
         for(int i=0;i<nums2.size();i++)
        {
            if(a.count(nums2[i]))
              {  v.push_back(nums2[i]);a.erase(nums2[i]);}
        }
        return v;
    }
};
