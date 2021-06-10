   int lenLongestFibSubseq(vector<int>& arr) {
        set<int> s;int ans,maxi=2;
        for(auto i:arr) s.insert(i);
        
        for(int i=0;i<arr.size();i++)
        {  
            for(int j=i+1;j<arr.size();j++)
            {
               int f0=arr[i];int f1=arr[j];ans=2;
                while(s.find(f0+f1)!=s.end())
                {
                    ans++;
                    int f2=f0+f1;
                    f0=f1;
                    f1=f2;
                   
                    
                }
              maxi=max(ans,maxi);  
            }
        }
        return maxi>2?maxi:0;
    }
