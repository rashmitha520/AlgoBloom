class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v;
        unordered_map<int,int> a;
        for(int i=0;i<nums1.size();i++)
        {
            a[nums1[i]]++;
        }
        
         for(int i=0;i<nums2.size();i++)
        {
            if(a.find(nums2[i]) !=a.end() )
              { a[nums2[i]]--;
               if(a[nums2[i]]>=0)
                v.push_back(nums2[i]);
            }
        }
        return v;
    }
};
