 int numOfSubarrays(vector<int>& arr) {
        vector<int> prefix(arr.size()+1,0);
        long long even=0,odd=0;
        for(long long i=0;i<arr.size();i++)
        {
            prefix[i+1]=prefix[i]+arr[i];
        }
        long long count=0; //odd-even =odd and even-odd=odd
        for(long long i=0;i<=arr.size();i++)
        {
            if(prefix[i]%2==1){ //prefix is odd then count no of even and increment the odd 
               count+=(even);
            odd++;
            }
            else//even then count no of odd and increment even
            {
              count+=odd;
                even++;
            }
            
        }
        return count%1000000007;
    }
