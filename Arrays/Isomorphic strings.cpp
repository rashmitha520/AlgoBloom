/*Given two strings s and t, determine if they are isomorphic.

Two strings s and t are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.

 

Example 1:

Input: s = "egg", t = "add"
Output: true
Example 2:

Input: s = "foo", t = "bar"
Output: false
Example 3:

Input: s = "paper", t = "title"
Output: true
*/
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char,char> c;  map<char,char> d;
        if(s.length()!=t.length()) return 0;
        for(int i=0;i<s.length();i++)
           {c[s[i]]=t[i];d[t[i]]=s[i];}
        for(int i=0;i<s.length();i++)
          {
            if(c[s[i]]!=t[i] || s[i]!=d[t[i]]) 
                return 0;
        }
        
        return true;
    }
};
