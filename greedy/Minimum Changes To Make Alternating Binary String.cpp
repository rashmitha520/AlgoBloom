  int minOperations(string s) {
        int c=0;
       for(int i=0;i<s.length();i++)
       {
           if(s[i]-'0'!=i%2) c++;
       }
        int n=s.length();
        return min(c,n-c);
    }
    public int minOperations(String s) {
    int n = s.length();
    int c1 = 0, c2 = 0;
    for (int i = 0; i < n; i++) {
        // for 0101 sequence, count violating
        if (s.charAt(i) - '0' != i % 2) {
            c1++;
        }
        // for 1010 sequence, count violating
        if (s.charAt(i) - '0' == i % 2) {
            c2++;
        }
    }
    return Math.min(c1, c2);
}


public int minOperations(String s) {
    int n = s.length();
    int c1 = 0, c2 = 0;
    for (int i = 0; i < n; i++) {
        // for 0101 sequence, count violating
        if (s.charAt(i) - '0' != i % 2) {
            c1++;
        } else { // for 1010 sequence, count violating
            c2++;
        }
    }
    return Math.min(c1, c2);
}
and we know c1+c2 equals n, so we can further simplify the code to

public int minOperations(String s) {
    int n = s.length();
    int c1 = 0;
    for (int i = 0; i < n; i++) {
        // for 0101 sequence, count violating
        if (s.charAt(i) - '0' != i % 2) {
            c1++;
        }
    }
    return Math.min(c1, n - c1);
}
