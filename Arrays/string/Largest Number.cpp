 bool cmp(const int & A,const int & B)
        {
           string a=to_string(A);
           string b=to_string(B);
            return a+b>b+a;
        }
class Solution {
public:
   
     
    
    string largestNumber(vector<int>& nums) {
     string s;
     
     sort(nums.begin(),nums.end(),cmp);
     
     if(nums[0]==0) return "0";
     
     for(auto i:nums) s+=to_string(i);
        
        
        return s;
    }
};
