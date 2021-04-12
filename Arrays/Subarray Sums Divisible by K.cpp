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
//prefix sum,hashmap
// a(j,0) - a(i,0) ==0 then thats subarray sum is divisible.
class Solution {
public:
    int subarraysDivByK(vector<int>& a, int k) {
      map<int,int> m;
      int sum=0,c=0;
      int rem=0;m[0]=1;
      for(int i=0;i<a.size();i++)
      {
          sum+=a[i];
          rem = sum%k;
          if(rem<0) rem+=k;
          if(m.count(rem))
          {
              c+=m[rem];
              m[rem]++;
          }
          else m[rem]++;
      }
        return c;
    }
};
