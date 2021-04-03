int gcd(int a,int b)
{
	//Write your code here
    int k; 
    k=(a<b)?a:b;
    int ans=1;
    for(int i=2;i<=k;i++)
    {
        if(a%i==0 && b%i==0)
            ans=i;
        
    }
    return ans;
}
//euclid's algorithm
int gcd(int a,int b)
{
	//Write your code here
    if(b==0) return a;
    return gcd(b,a%b);
}
