class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
     vector<int> m(k);
        for(int i:arr){
            i=i%k;
            if(i<0) i=i+k;
            m[i]++;
                
        }
        if(m[0]%2==1) return 0;
        for(int i=1;i<=k/2;i++){
            if(m[i]!=m[k-i]) return 0;
        }
        return 1;
    }
};
