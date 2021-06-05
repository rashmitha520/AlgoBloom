//TLE    
int numberOfSubstrings(string s) {
       int n=s.length(),k=0;set<char> a;
        for(int i=0;i<n;i++)
        {  a.erase(a.begin(),a.end());
          
            for(int j=i;j<n;j++)
            {
                 a.insert(s[j]);
                if(a.size()==3) k++;
            }
        }
        return k; 
    }

 int numberOfSubstrings(string s) {
       int n=s.length(),k=0;map<char,int> a;int first=0;
        for(int i=0;i<n;i++)
        { 
             a[s[i]]++;
                while(a.size()==3){ 
                    
                    k+=(n-i); //counts all substrings from end; 'a'bcabc : abc,abca,abcab,abcabc               
                    a[s[first]]--;
                     if(a[s[first]]==0) a.erase(s[first]);
                    first++;
                }
            
        }
        return k; 
    }
