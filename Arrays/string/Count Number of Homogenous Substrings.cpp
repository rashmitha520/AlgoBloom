 #define m 1000000007
    int countHomogenous(string s) {
        long num=0;long count;
        for(int i=0;i<s.length();i++)
        {
            char c=s[i]; count=1;
            while(i<s.length() and c==s[i+1] )
            {
                count++;i++;
            }
            num +=((count*(count+1))/2);
            
        }
        return (num)%m;
    }
