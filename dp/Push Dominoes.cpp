    string pushDominoes(string s) {
        int n=s.length();
        vector<int> l(n,0),r(n,0);
        int count=1;char prev='.';
        //right
        for(int i=0;i<n;i++)
        {
            if(s[i]=='R') {count=1;prev='R';continue;}
            else if(s[i]=='L'){prev='L';}
            else
            {
                if(prev=='R' && s[i]=='.')
                   { r[i]=count++;}
            }
            
        }
        //left
        prev='.';count=1;
         for(int i=n-1;i>=0;i--)
        {
            if(s[i]=='L') {count=1;prev='L';continue;}
            else if(s[i]=='R'){prev='R';}
            else
            {
                if(prev=='L' && s[i]=='.')
                   { l[i]=count++;}
            }
            
        }
        string ans="";
        for(int i=0;i<n;i++)
        {
            if(!l[i] && !r[i]) ans+=s[i];
            else if(!l[i]) ans+='R';
            else if(!r[i]) ans+='L';
            else if(l[i]==r[i]) ans+='.';
            else if(l[i]>r[i]) ans+='R';
            else ans+='L';
        }
        return ans;
    }
