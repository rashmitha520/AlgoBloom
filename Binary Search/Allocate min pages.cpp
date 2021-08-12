bool isvalid(vector<int> &arr, int b,int mid)
{
    int n=arr.size();
    int sum=0,students=1;
    for(int i=0;i<n;i++)
    {
        if(arr[i]>mid) return 0;//edge case 
        else if(arr[i]+sum>mid)
        {
           students++;
           sum=arr[i];
           if(students>b) return 0;//edge case
        }
        else sum+=arr[i];
    }
    return 1;
}
int Solution::books(vector<int> &arr, int b) {
    int sum=0,res=-1;
    if(arr.size()<b) return -1; //edge case
    for(auto i:arr) sum+=i;
    int l=0,r=sum;
    while(l<=r)
    {   int mid=l+(r-l)/2;
        if(isvalid(arr,b,mid))
           {
              res=mid;
              r=mid-1;

           }
        else l=mid+1;
            
    }
    return res;
}
