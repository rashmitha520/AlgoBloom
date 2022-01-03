class Solution {
public:
    string gcdOfStrings(string s1, string s2) {
        if(s1.length()<s2.length()) return gcdOfStrings(s2,s1);
        if(s2.empty()) return s1;
        if(s1.substr(0,s2.length())!=s2) return "";
        return gcdOfStrings(s1.substr(s2.length()),s2);
    }
};
