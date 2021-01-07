#include<math.h>
#include<bits/stdc++.h>
void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
}
int pivotf(int arr[], int low, int high) 
{ 
    int pivot = arr[high];   
    int i = (low-1); 
  
    for (int j = low; j <= high- 1; j++) 
    { 
       
        if (arr[j] <= pivot) 
        { 
            i++,
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 
void sort(int input[],int s,int e)
{
    if(s>=e) return;
    int p=pivotf(input,s,e);
    sort(input,s,p-1);
    sort(input,p+1,e);
}
void quickSort(int input[], int size) {
 
        sort(input,0,size-1);
    
}

