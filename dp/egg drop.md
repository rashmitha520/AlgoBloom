https://leetcode.com/problems/super-egg-drop/discuss/792736/CPP-Explained-Recursive-greatermemoization-greateroptimization-greaterDP-oror-Well-Explained-oror-Easy-to-unserstand
```cpp
//tle  - recursion

class Solution {
public:
    int superEggDrop(int k, int n) {
        if(n==1||n==2) return n;
        if(k==1) return n;
        int ans=INT_MAX;
        for(int i=1;i<=n;i++)
        {                 //break case          //non break
           int temp=1+max(superEggDrop(k-1,i-1),superEggDrop(k,n-i)) ;
            ans=min(ans,temp);
        }
        return ans;
    }
};
>>
//memoization
int find(int k,int n, vector<vector<int>>& dp)
    {
        if(n==1||n==2) return n;
        if(k==1) return n;
        if(dp[k][n]!=-1) return dp[k][n];
        int ans=INT_MAX;
        for(int i=1;i<=n;i++)
        {
           int temp=1+max(find(k-1,i-1,dp),find(k,n-i,dp)) ;
            ans=min(ans,temp);
        }
        return dp[k][n]=ans;
    }
    int superEggDrop(int k, int n) {
        vector<vector<int>> dp(k+1,vector<int>(n+1,-1));
       
        return  find(k,n,dp);;
    }
//memoization + binary search
 int find(int k,int n, vector<vector<int>>& dp)
    {
        if(n==1||n==2) return n;
        if(k==1) return n;
        if(dp[k][n]!=-1) return dp[k][n];
   
        int ans=100000;
        int lo=1,high=n,temp=0;
   
        while(lo<=high)
        {
            int mid=(lo+high)/2;
          
            int t1=find(k-1,mid-1,dp);
            int t2=find(k,n-mid,dp);
          
            if(t1<t2){
              lo=mid+1;
            }
            else{
              high=mid-1;
            }
           
            temp=1+max(t1,t2);
            ans=min(ans,temp);
        }
        return dp[k][n]=ans;
    }
    int superEggDrop(int k, int n) {
        vector<vector<int>> dp(k+1,vector<int>(n+1,-1));
       
        return  find(k,n,dp);;
    }

//dp 
class Solution {
public:
    
    int superEggDrop(int k, int n) {
        if(n==0||n==1) return n;
        if(k==1) return n;
        vector<vector<int>> dp(k+1,vector<int>(n+1,0));
        //n=1 or n=0
       for(int i=0;i<=k;i++)
       { dp[i][0]=0;dp[i][1]=1;}
        
        //k=1 or k=0
         for(int i=0;i<=n;i++)
       { dp[1][i]=i;dp[0][i]=0; }
        
   //     int l=1,h=n,ans=100000,temp=0;
        for(int i=2;i<=k;i++)
        {for(int j=2;j<=n;j++)
        {   int l=1,h=j,ans=100000,temp=0;
         while(l<=h){
            int mid=(l+h)/2;
            int breaks = dp[i-1][mid-1];//T1(k-1,N-1);broken
            int nobreaks = dp[i][j-mid];//T2(k,N-X);not broken
            temp = 1+max(breaks,nobreaks);
            if(breaks<nobreaks) l=mid+1;
            else h=mid-1;
           
            ans=min(ans,temp);
         }
         dp[i][j]=ans;
        }
        
        }
        
        return  dp[k][n];
    }
};


```
