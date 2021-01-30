#include<unordered_map>
class Solution {
public:
   string s[4][10]={
       {"","I","II","III","IV","V","VI","VII","VIII","IX"},
       {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"},
       {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"},
       {"","M","MM","MMM"}
   };
    string intToRoman(int num) {
     string ans; int count=0;
        
        while(num)
        {
           int k=num%10;
            //eg 2467
            // 1 iter :ans = vii
            // 2 iter : ans = lxvii
            // 3 iter : ans = cdlxvii
            // 4 iter : ans= mmcdlxvii
            ans=s[count][k]+ans;
            num/=10;
            count++;
        }
        return ans;
    }
};
//another method:
#include<unordered_map>
class Solution {
public:
   string s[4][10]={
       {"","I","II","III","IV","V","VI","VII","VIII","IX"},
       {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"},
       {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"},
       {"","M","MM","MMM"}
   };
    string intToRoman(int ans) {
    
        
        
      
       return s[3][(ans/1000)%10]+s[2][(ans/100)%10]+ s[1][(ans/10)%10]+s[0][ans%10];
        
    }
};
