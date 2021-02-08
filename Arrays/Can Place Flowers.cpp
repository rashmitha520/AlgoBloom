class Solution {
public:
    bool canPlaceFlowers(vector<int>& f, int n) {
        int s=f.size();
        if(n==0) return true;
        if(s==1)
        {
            if(n>1) return false;
            else if(n==0) return true;
            else if(n==1 && f[0]==0) return true;
            else return false;
        }
        
        if(f[0]==0 && f[1]!=1) {f[0]=1;n--; if(n==0) return true;}
        if(f[s-1]==0 && f[s-2]!=1){f[s-1]=1;n--; if(n==0) return true;}
        // if(n==0) return true;
        for(int i=1;i<s-1;i++)
        {   if(n==0) return true;
            if(f[i-1]==1 || (f[i+1]==1||f[i]==1)) continue;
            else
            {
                f[i]=1;--n;
               
            }
             
        }
   return false;
    }
};
