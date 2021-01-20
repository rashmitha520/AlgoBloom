
//Adobe question-2marks
class Solution {
public:
    int longestPalindrome(string s) {
       unordered_map<char,int> u;int r=0,c=0;
        for(int i=0;i<s.length();i++)
            u[s[i]]++;
       for(auto i:u)
       {
           if(i.second%2==0)
               r+=i.second;
           else
               r+=i.second-1,c=1;}
        return r+c;
    }
};
