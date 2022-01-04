
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        int setbit,xor1=arr[0],x=0,y=0;
        for(int i=1;i<n;i++){
            xor1=xor1^arr[i];
            
        }
        for(int i=1;i<=n;i++){
            xor1=xor1^i; //here we get xor1=x^y
        }
        //to find x and y , we find rightmost set bit
        setbit = xor1 & ~(xor1-1);
      
        for(int i=0;i<n;i++){
            if(setbit & arr[i]) x=x^arr[i];
            else y=y^arr[i];
            
        }
      
        for(int i=1;i<=n;i++){
           if(setbit & i) x=x^i;
            else y=y^i; 
        }
        int *ans;ans[0]=x,ans[1]=y;
        return ans;
    }
};

//method - 2(tle)
    int *findTwoElement(int *arr, int n) {
       int s=n*(n+1)/2,s2=n*(n+1)*(2*n+1)/6,x=0,y=0,*ans,sum=0,sq_sum=0;
       for(int i=0;i<n;i++){
           sum+=arr[i];
           sq_sum+=arr[i]*arr[i];
       } 
       int x_y=s-sum,x2y2=s2-sq_sum;
       int divs= x2y2/x_y;
       x=divs+x_y;
       x=x/2;
       y=divs-x;
       ans[0]=y,ans[1]=x;
       return ans;
       
    }
