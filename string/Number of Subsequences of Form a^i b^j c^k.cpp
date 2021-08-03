  int countSubsequences(string &s) {
        // write your code here
        int a=0,b=0,c=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='a')
               a=1+2*a;
            else if(s[i]=='b')
               b=2*b+a;
            else if(s[i]=='c')
               c=2*c+b;
        }
        return c;
    }
