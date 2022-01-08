
class Solution{
    public:
    string colName (long long int n)
    {
        // your code here
        string s;
        while(n>0)
        {char rem='A'+(n-1)%26;
        s=rem+s;
        n=(n-1)/26;
        }
        return s;
    }
};
