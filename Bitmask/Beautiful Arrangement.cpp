    //bitmsking
    int solve(int n,int mask,int size)
    {
        if(size>n) return 1;
        int res=0;
        for(int i=1;i<=n;i++)
        {
        if((mask&(1<<i))==0 && (i%size==0 or size%i==0))
          res+=solve(n,mask|(1<<i),size+1);  
        }
        return res;
    }
    int countArrangement(int n) {
        int mask=0,size=1;
        return solve(n,mask,size);
        
    }
    
   //backtracking 
    vector<int> v;
    int count=0;
    void  countArrangements(int n,int p,vector<int>& s)
    {  
       if(n<p){
           count++;
           return;
       }
      
        for(int i=1;i<=n;i++)
        { if(s[i]==0 && (i%p==0 or p%i==0))
            {
           
             s[i]=1;
             countArrangements(n,p+1,s);

             s[i]=0;
            }
           
        }  
    }
    int countArrangement(int n) {
        int mask=0;vector<int> s(16,0);
       countArrangements(n,1,s);
        return count;
        
    }
