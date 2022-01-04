class Solution {
  public:
    int doOverlap(int l1[], int r1[], int l2[], int r2[]) {
        // code here
        if(l1[0]>r2[0]||r1[0]<l2[0]||l1[1]<r2[1]||r1[1]>l2[1]) return 0;
        return 1;
    }
};
