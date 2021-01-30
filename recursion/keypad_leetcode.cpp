class Solution {
public:
   vector<string> v = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> letterCombinations(string digits) {
        //Assume thee is 367
        //c=3
        vector<string> mres;
        if(digits.length()==0)
        {
            return mres;
        }
       char c=digits[0];
        string subs=digits.substr(1);//subs=67
        vector<string> rest=letterCombinations(subs);//returns all substrings of 6x7
         if(rest.empty()) rest.emplace_back("");
        string st=v[c-'0'];// for 3:def => it stores "def"
        //for d,e,f we combine to each string in the rest string vector
        for(int i=0;i<st.length();i++)
        {
            for(int i1=0;i1<rest.size();i1++)
            {  //adding d+{all the substrings got from recursion}
                
                mres.emplace_back(st[i]+rest[i1]);
            }
        }
        return mres;
    }
};

=======================================
   #include <string>
#include<vector>
using namespace std;
string v[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
int keypad(int num, string output[]){
     if(num==0||num==1) {output[0]="";return 1;}
     int last=num%10;
     int rest=num/10;
    string om[1000];
    int scount=keypad(rest,om);
    string laststring=v[last];
    int ll=laststring.length();
    int b=0;
    for(int i=0;i<ll;i++)
    {
        for(int j=0;j<scount;j++)
        {
            output[b]=om[j]+laststring[i];
            b++;
        }
    }
    return b;
}


