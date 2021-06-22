 int numberOfRounds(string s, string f) {
        int h1=stoi(s.substr(0,2));
        int h2=stoi(f.substr(0,2));
        int m1=stoi(s.substr(3));
        int m2=stoi(f.substr(3));
        
        if(h1>h2 or (h1==h2 && m1>m2)) h2=h2+24;
        int t1=h1*60+m1;
        int t2=h2*60+m2;
        if(t1%15!=0)
            t1=t1+(15-t1%15);
        int c=0;
        for(int i=t1;i<=t2;i+=15)
           {
            if(i+15<=t2)
               c++;
        }
        return c;
        
    }
