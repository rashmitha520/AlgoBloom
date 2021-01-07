void merge(int input[],int s,int e,int m)
{
    int si=m-s+1,ei=e-m;
    int l[si],r[ei];
	
    for(int i=0;i<si;i++)
        l[i]=input[s+i];
     for(int i=0;i<ei;i++)
        r[i]=input[m+i+1];
	
    int k=s,j=0,i1=0;
 //compare and enter the lowest
    while(j<si && i1<ei)
    {
        if(l[j]<=r[i1])
            input[k]=l[j],k++,j++;
        else
            input[k]=r[i1],k++,i1++;
    }
    //left over parts of l and r
    while(j<si)
        input[k]=l[j],k++,j++;
    while(i1<ei)
        input[k]=r[i1],k++,i1++;
    
}
void merges(int input[],int s,int e)
{  int mid =(s+e)/2;
    if(s>=e) return ;
 //splitting
     merges(input,s,mid);
      merges(input,mid+1,e);
 //merging
     merge(input,s,e,mid);
    
}
void mergeSort(int input[], int size){
	
     merges(input,0,size-1);
     
}

