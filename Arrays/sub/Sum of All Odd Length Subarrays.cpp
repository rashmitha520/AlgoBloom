//prefix sum   
int sumOddLengthSubarrays(vector<int>& arr) {
       int n=arr.size();
        vector<int> pre(n+1,0);
        for(int i=0;i<n;i++)
            pre[i+1]=pre[i]+arr[i];
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<=n;j+=2)
                ans+=(pre[j]-pre[i]);
        }
        return ans;
    }

/*Given array: arr = [1, 2, 3, 4, 5] (n = 5) and formula (i + 1) * (n - i)*/
  int sumOddLengthSubarrays(vector<int>& arr) {
       int n=arr.size();
       
        int ans=0;
        for(int i=0;i<n;i++)
        {
           ans=ans+ ceil((i+1)*(n-i)/2.0)*arr[i];
        }
        return ans;
    }
