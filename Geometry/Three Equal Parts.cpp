    int locate(vector<int>& arr,int t)
    {  int i=0,c=0;
        while(arr[i]==0) i++;
        while(i<arr.size())
        {  if(arr[i]==1)
            c++;
            if(c==t) return i;
           i++;
        }
     return 0;
    }
    vector<int> threeEqualParts(vector<int>& arr) {
      int n=arr.size();
      int ones=0;
      for(int i:arr) ones+=i;
      if(ones%3!=0) return {-1,-1};
      if(ones==0) return {0,2};
      int k=ones/3;
      int left=locate(arr,1),mid=locate(arr,k+1),right=locate(arr,k*2+1);
      
    while(left<mid && mid<right && right<n)
    {
        if(arr[left]==arr[mid] && arr[mid]==arr[right])
        {
            left++,right++,mid++;
        }
        else break;
    }
       if(right==n) return {left-1,mid} ;
        else if(right==0) return {0,n-1};
        return {-1,-1};
        
    }
