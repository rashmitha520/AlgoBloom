class Solution {
public:
    int trap(vector<int>& height) {
        int l=0,r=0;
        int ans=0;int n=height.size();
      
        for(int i=1;i<n-1;i++)
        {  
          l=height[i],r=height[i];
          
            for(int j=0;j<i;j++)
                l=max(height[j],l);
          
            for(int j=i+1;j<n;j++)
                r=max(height[j],r);
          //water filled acc to the minimum pole.
            ans=ans+(min(l,r)-height[i]);
            
        }
        return ans;
    }
};

//O(n) space O(n)
class Solution {
public:
    int trap(vector<int>& height) {
       
        int ans=0;int n=height.size();
        if(n==0) return 0;
         vector<int> l(n),r(n);
          l[0]=height[0];r[n-1]=height[n-1];
            for(int j=1;j<n;j++)
                l[j]=max(height[j],l[j-1]);
            for(int j=n-2;j>=0;j--)
                r[j]=max(height[j],r[j+1]);
        for(int i=0;i<n;i++)
        { 
            ans=ans+(min(l[i],r[i])-height[i]);
            
        }
        return ans;
    }
};

