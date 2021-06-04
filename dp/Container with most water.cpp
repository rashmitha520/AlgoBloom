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
