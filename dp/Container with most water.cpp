//tle    
int maxArea(vector<int>& height) {
      int area=0;
        for(int i=0;i<height.size();i++)
        {
            for(int j=i;j<height.size();j++)
            {
                area=max(area,(j-i)*min(height[i],height[j]));
            }
        }
        
    
        return area;
    }
//2-ptr approach
 int maxArea(vector<int>& height) {
     int area=0;
        int i=0,j=height.size()-1;
        while(i<j)
        {
           area=max(area,(j-i)*min(height[i],height[j]));
           
            if(height[i]<height[j])
                i++;
            else
                j--;
        }
        return area;
    }
