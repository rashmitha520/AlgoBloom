//not yet completed
/*
Given an array , we must find an interval where (minElement of interval *[total sum of the interval] )is maximum .
Eg : [3,1,6,5,4,2]
Ans is 60
4*[6+5+4]
*/
#include <iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
int gr(vector<int> v)
{
    int sum=0;
    vector<int> s(v.size(),0);
    //current element as minimum
    for(int i=0;i<v.size();i++)
    {
         //first element and next element is smaller than the first
         if((i==0 && i+1<v.size()) && v[i]>v[i+1])
             s[i]=v[i]*v[i];
            //if adjacent elements are smaller than current min
         if((i-1>=0 && i+1<v.size()) && (v[i-1]<v[i] && v[i]>v[i+1]))
            s[i]=v[i]*v[i];
            //if left or right elements are bigger than the current minimum
        else if((i-1>=0 && i+1<v.size()) && (v[i-1]>v[i] || v[i]<v[i+1]))
        {   int left=i-1;
            while(left>=0 && v[left]>v[i])
                {   s[i]=s[i]+v[left]; left--; }
            int right=i+1;
            while(right<v.size() && v[right]>v[i])    
                 {   s[i]=s[i]+v[right]; right++; }
                 s[i]=s[i]+v[i];
                 s[i]=s[i]*v[i];

                 }

    }
    sort(s.begin(),s.end());
    return s[s.size()-1];
}
int main() {
    int n;
    cin>>n;
   vector<int> v(n);
   for(int i=0;i<n;i++)
      cin>>v[i];
    cout<<gr(v);
}
