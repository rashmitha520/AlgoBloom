class Solution {
public:
    int find(vector<int>& heights,int n)
    {
        vector<int> l(n),r(n);
        int maxA=0;
       
       stack<int> s2;
        s2.push(n-1);
    
        r[n-1]=n;
    for(int i=n-2;i>=0;i--)
    {
        
        while(s2.size()>0 && heights[s2.top()]>=heights[i])
            s2.pop();
       
        if(s2.size()==0)
            r[i]=n;
        else
            r[i]=s2.top();
        s2.push(i);
    }
    
       stack<int> s1;
        s1.push(0);
    
        l[0]=-1;
    for(int i=1;i<n;i++)
    {
       
        while(s1.size()>0 && heights[s1.top()]>=heights[i])
            s1.pop();
        
       
        if(s1.size()==0)
           { l[i]=-1;
            maxA=max(maxA,(r[i]-l[i]-1)*heights[i]);
           }
        else
            {l[i]=s1.top();
             maxA=max(maxA,(r[i]-l[i]-1)*heights[i]);
            }
        s1.push(i);
    }
     maxA=max(maxA,(r[0]-l[0]-1)*heights[0]);  
   
        return maxA;  
    }
  // each row is regarded as the swarm of histograms and we have to find the rectangle with largest area
    int maximalRectangle(vector<vector<char>>& matrix) {
          if(matrix.size()==0) return 0;
     vector<int> height(matrix[0].size());
        int n=matrix[0].size(),m=matrix.size();
        int area=INT_MIN;
      
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]=='0') height[j]=0;
                else height[j]+=1;//if it is 1 then previous height is added to it
            }
            area=max(area,find(height,n)); //calculate max area rectangle for each row and store the largest
        }
        return area;
    }
};
