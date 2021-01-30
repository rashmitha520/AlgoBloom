class Solution {
public:
    double findMedianSortedArrays(vector<int>& n, vector<int>& m) {
        vector<int> v(n.size()+m.size());
        int i=0,j=0;int k=0;
        bool odd=(n.size()+m.size())%2;
        int mid= (n.size()+m.size())/2;
        //when it is odd sized array, the middle is natural median
        //whereas for even sized, it is mean of mid-1 , mid th array
        while(i<n.size() && j<m.size())
        {
            if(n[i]<m[j])
            {v[k]=n[i];i++;}
            else
            {
                v[k]=m[j];j++;
            }
            if(k==mid)
            {
                if(odd)
                    return v[k];
            }
            k++;
        }
        
        while(i<n.size())
           { 
            v[k]=n[i];  
            if(odd && k==mid)
                return v[k];
            k++;i++;
           }
        
        while(j<m.size())
           {    v[k]=m[j];
            if(odd && k==mid)
                return v[k];
                k++;j++;
           }
        
        
        return double(v[mid-1]+v[mid])/2;
    }
};
