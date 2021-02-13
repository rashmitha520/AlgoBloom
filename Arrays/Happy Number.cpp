//My approach
class Solution {
public:
    int sum(int k)
    {    int rem,quo=0;
        while(k!=0)
        {
           rem=k%10;
            k=k/10;
            quo =quo + rem*rem;
        }
     return quo;
    }
    bool isHappy(int n) {
    if(n==1 or n==7) return 1;
    //else if(n<10) return 0;
    while(1)
    {
        n=sum(n);
        if(n==1 or n==7) return true;
        else if(n==0 or (n>1 and n<10)) return false;
    }
        return false;
    }
};
//floyd cycle detection algorithm
class Solution {
public:
    int sum(int k)
    {    int rem,quo=0;
        while(k!=0)
        {
           rem=k%10;
            k=k/10;
            quo =quo + rem*rem;
        }
     return quo;
    }
    bool isHappy(int n) {
    if(n==1 or n==7) return 1;
    int slow=n, fast=n;
   do
    {
       slow=sum(slow);
       fast=sum(fast);
       fast=sum(fast);
    }while(slow!=fast);
        if(slow==1) return true;
        return false;
    }
};
