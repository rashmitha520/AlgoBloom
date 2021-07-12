    int countPalindromicSubsequence(string s) {
        int n=s.size(),count=0;
        for(int k=0;k<26;k++)
        {   int i=0,j=n-1;
            while(i<n && s[i]!=('a'+k))
                i++;
            while(j>=0 && s[j]!=('a'+k))
                j--;
           unordered_set<char> st;
            for(int l=i+1;l<j;l++)
            {
                st.insert(s[l]);
            }
         count+=st.size();
        }
        return count;
    }
