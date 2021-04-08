//brute force
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      int ans=0;
      int n=s.length();
     
      for(int i=0;i<n;i++)
      {
          int c=0,j=i;
           unordered_map<char,int> m;
          while(j<n && m[s[j]]==0)
          { 
              ans=max(ans,c+1);
              m[s[j]]++;c++; j++;
          }
      }
     return ans;   
    }
};
