class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n=arr.size(); int maxi=0;
        for(int i=1;i<n-1;i++)
        {
            int j=i-1;
            int cur=arr[i];
            int l=0;
            while(j>=0  && arr[j]<cur)
            {
               l++;
               cur=arr[j];
               j--;
                
            }
            j=i+1; cur=arr[i];int r=0;
            while((l>0 && j<=n-1)  && arr[j]<cur)
            {
               r++;
               cur=arr[j];
               j++;
               maxi=max((l+r+1),maxi);
            }
            
        }
        return maxi;
    }
};


//efficient

class Solution {
public:
    int longestMountain(vector<int>& A) {
          if(A.size() == 0)
            return 0;
        
        int maxLen = 0; 
        for(int i=1; i<A.size()-1; i++)
        {
            if(A[i] > A[i+1] && A[i] > A[i-1])
            {
                int left = i-1;
                int right = i+1;
                
                while(left > 0 && A[left-1] < A[left])
                    left--;
                while(right < A.size()-1 && A[right+1] < A[right])
                    right++;
                maxLen = max(maxLen, right-left+1);
            }
        }
        return maxLen;
    }
};
