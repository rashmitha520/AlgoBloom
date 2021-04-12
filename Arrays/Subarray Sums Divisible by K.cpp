//TLE
class Solution {
public:
    int subarraysDivByK(vector<int>& a, int k) {
        unordered_map<int,int> m;int c=0;
        for(int i=0;i<a.size();i++)
        {
            int s=0;
            for(int j=i;j<a.size();j++)
            {
                s+=a[j];
                m[s]++;
                if(s%k==0) c++;
                
            }
        }
            return c;
    }
};
