//brute force - tle
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& a, int k) {
        int n=a.size();
        int c=0;
        for(int i=0;i<n;i++)
        {
            set<int> s;
            for(int j=i;j<n;j++)
            {
                s.insert(a[j]);
                if(s.size()==k)
                    c++;
            }
        }
        return c;
    }
};

//sliding window
