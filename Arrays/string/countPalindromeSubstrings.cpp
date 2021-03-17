
int countPalindromeSubstrings(char s[])
{
    int count=0;
    int n ;int k=0;
    for(int i=0;s[i]!='\0';i++)
        k++;
    n=k;
   for(int i=0;i<n;i++)
   {  int left=i,right=i;
       while(left>=0 && right<n && s[left]==s[right])
       {
           count++;
           left--;right++;
       }
         left=i,right=i+1;
     while(right<n && left>=0  && s[left]==s[right])
       {
           count++;
           left--;right++;
       }
   }
    return count;
}
