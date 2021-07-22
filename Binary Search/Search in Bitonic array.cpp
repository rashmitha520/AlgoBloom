int i=0,j=arr.size()-1,n=arr.size();
while(i<=j)
{ int mid=(i+j)/2;
    if(arr[mid]==t) return mid;
   else if(arr[mid]<=arr[j]) //sorted
    {
        if(arr[mid]<t) i=mid+1;
        else j=mid-1;
    }
  else{
      if(arr[mid]<t) j=mid-1;//then the greater element is to left
      else i=mid+1;//lesser elements to the right for abnormal element
  }
