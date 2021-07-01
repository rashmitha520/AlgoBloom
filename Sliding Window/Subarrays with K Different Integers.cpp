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
class Solution {
public:
      int atmostk(vector<int>& arr, int k) {
        int i = -1, j = -1, ans = 0;
        unordered_map<int, int> m;
        const int n = arr.size();
         while(true)
         { //until valid
             while(i<(n-1))
             {
               i++;
               m[arr[i]]++;
               if(m.size()<=k)
               {
                   ans+=(i-j);
               }
               else break;
             }
             
             if(i==n-1 && m.size()<=k)
                 break;
             
             //to make window valid
             //i.e. map size <=k 
             //then count no of such subarrays
             while(j<i)
             {
              j++;
              if(m[arr[j]]==1)
                  m.erase(arr[j]);
              else
                  m[arr[j]]--;
              if(m.size()>k) continue;
              else
              {
                  ans+=(i-j);
                  break;
              }
             }
             
         }
       return ans;
    }
    int subarraysWithKDistinct(vector<int>& A, int K) {
       return atmostk(A,K)-atmostk(A,K-1); 
    }
};
