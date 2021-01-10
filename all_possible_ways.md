Given two integers a and b. You need to find and return the count of possible ways in which we can represent the number a as the sum of unique integers raise to the power b.
For example: if a = 10 and b = 2, only way to represent 10 as sum of unique integers raised to power 2 is-
10 = 1^2 + 3^2 
Hence, answer is 1.
Note : x^y represents x raise to the power y
```
#include<math.h>
int check(int a,int b,int num,int  sum)
{ 
   	// Write your code here
  int p=pow(num,b);
    int res=0;
    while(p+sum<a)
    {
        res+=check(a,b,num+1,p+sum);
        num+=1;
        p=pow(num,b);
        
    }
    if(p+sum==a)
        res++;
    return res;
 
}
int getAllWays(int a, int b) {

  
    return check(a,b,1,0);
}
```
