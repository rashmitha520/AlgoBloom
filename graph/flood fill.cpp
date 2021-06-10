 void dfs(vector<vector<int>>& image, int sr, int sc, int newColor,int c)
    {
        if(sr<0||sc<0||sr>=image.size()||sc>=image[0].size()||image[sr][sc]!=c) return;
        
        image[sr][sc]=newColor;
        
        dfs(image,sr-1,sc,newColor,c);
        dfs(image,sr,sc-1,newColor,c);
        dfs(image,sr+1,sc,newColor,c);
        dfs(image,sr,sc+1,newColor,c);
        
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int r=image.size(),c=image[0].size();
                 if(image[sr][sc]!=newColor)
                    dfs(image,sr,sc,newColor,image[sr][sc]);
                
            
        
        return image;
    }
