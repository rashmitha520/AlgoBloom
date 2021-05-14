// O(m*n) approach
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row=matrix.size();
        set<int> r,l;
        int col=matrix[0].size();
        
       for(int i=0;i<row;i++)
       {
          
           for(int j=0;j<col;j++)
           {
               if(matrix[i][j]==0) 
                   {
                   
                  r.insert(i);l.insert(j);
               }
           }
       }
        
        for(int i=0;i<row;i++)
       {
           
           for(int j=0;j<col;j++)
           {
               if(r.find(i)!=r.end()|| l.find(j)!=l.end())
                   matrix[i][j]=0;
      
           }
            
        }
        
    }
       
    
};


//O(m+n)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row=matrix.size();
       // set<int> r,l;
        int col=matrix[0].size();
        bool c=0,r=0;
       for(int i=0;i<row;i++)
       {
          
           for(int j=0;j<col;j++)
           {
              
               if(matrix[i][j]==0) 
                   {
                    if(i==0){ r=1;}
                    if(j==0){ c=1;}
                  matrix[i][0]=0,matrix[0][j]=0;
               }
           }
       }
        
        for(int i=1;i<row;i++)
       {
           
           for(int j=1;j<col;j++)
           {
               if(matrix[i][0]==0|| matrix[0][j]==0)
                   matrix[i][j]=0;
      
           }
            
        }
        if(r){
          for(int j=0;j<col;j++)
           {
               
                   matrix[0][j]=0;
      
           }  
        }
        if(c){
          for(int j=0;j<row;j++)
           {
               
                   matrix[j][0]=0;
      
           }  
        }
        
    }
       
    
};
