class Solution {
  public:
    int findPosition(int n , int m , int k) {
        // code here
        if(m+k<=n+1) return m+k-1;
        m=m+k-1-n;
        if(m%n==0) return n;
        return m%n;
    }
};
