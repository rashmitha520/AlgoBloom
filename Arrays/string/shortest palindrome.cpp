//2-ptr approach:
class Solution {
public:
    string shortestPalindrome(string s) {
       int i=0,j=s.length()-1;int c=0;
        for(;j>=0;j--)
        {
            if(s[i]==s[j]) i++;
        }
        int n=s.length();
        if(i==s.length()) return s;
        string rem=s.substr(i);
        reverse(rem.begin(),rem.end());
        return rem+shortestPalindrome(s.substr(0,i))+s.substr(i);
    }
};

//brute force(tle)
class Solution {
public:
    string shortestPalindrome(string s) {
       int j=s.length()-1;int c=0;
        string rev(s);
        reverse(rev.begin(),rev.end());
       for(int i=0;i<=j;i++)
       {
           if(s.substr(0,j+1-i)==rev.substr(i)) return rev.substr(0,i)+s;
       }
       return "";
    }
};
//
