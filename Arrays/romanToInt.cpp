class Solution {
public:
    unordered_map<char,int> m{
{'I',1},
{'V',5},
{'X',10},
{'L',50},
{'C',100},
{'D',500},
{'M',1000}
    };
       
    
    int romanToInt(string s) {
        int n= s.length();
        int sum=m[s[n-1]];
    for(int i=s.length()-2;i>=0;--i)
       {
           if(m[s[i+1]]>m[s[i]])
               sum-=m[s[i]];
           else
               sum+=m[s[i]];
               
       }
        return sum;
    }
};
