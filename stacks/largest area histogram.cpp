class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int> l(n),r(n);
        int maxA=0;
            
        //right boundary 
       stack<int> s2;
        s2.push(n-1);
     //right boundary of 0th index
        r[n-1]=n;
    for(int i=n-2;i>=0;i--)
    {
        //pop till smaller height is encountered.
        //smaller height will be the boundary.
        while(s2.size()>0 && heights[s2.top()]>=heights[i])
            s2.pop();
        
        //if size is 0, then rightmost -1 will be its boundry
        if(s2.size()==0)
            r[i]=n;
        else
            r[i]=s2.top();
        s2.push(i);
    }
      //left boundary 
       stack<int> s1;
        s1.push(0);
     //left boundary of 0th index
        l[0]=-1;
    for(int i=1;i<n;i++)
    {
        //pop till smaller height is encountered.
        //smaller height will be the boundary.
        while(s1.size()>0 && heights[s1.top()]>=heights[i])
            s1.pop();
        
        //if size is 0, then leftmost -1 will be its boundry
        if(s1.size()==0)
            l[i]=-1;
        else
            l[i]=s1.top();
        s1.push(i);
    }
    
      for(int i=0;i<n;i++)
      {
          maxA=max(maxA,(r[i]-l[i]-1)*heights[i]);
      }
        return maxA;
    }
};
