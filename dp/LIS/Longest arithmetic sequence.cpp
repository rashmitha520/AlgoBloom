//tle
class Solution {
public:
    int longestArithSeqLength(vector<int>& a) {
        int n=a.size();int maxi=2;
        vector<unordered_map<int,int>> m(n);
        for(int i=0;i<n;i++)
        {
           
            for(int j=0;j<i;j++)
            {
               int diff= a[i]-a[j];
                if(m[j][diff]>0)
                    m[i][diff]=m[j][diff]+1;
                else
                     m[i][diff]=2;
                maxi=max(m[i][diff],maxi);
            }
        }
        
        
       return maxi; 
        
    }
};
//accepted soln

class Solution {
public:
    int longestArithSeqLength(vector<int>& a) {
        int n=a.size();int maxi=0;
vector<vector<int>>m(n,vector<int>(1001,0));
      
        for(int i=0;i<n;i++)
        {
           
            for(int j=0;j<i;j++)
            {//to tackle negative values
               int diff= a[i]-a[j]+500;
                
                    m[i][diff]=m[j][diff]+1;
                
                    
                maxi=max(m[i][diff],maxi);
            }
        }
        
        
       return maxi+1; 
        
    }
};
