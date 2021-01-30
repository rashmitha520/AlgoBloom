class Solution {
public:
    multiset<double> s;
    void insert(double x)
    {
        s.insert(x);
    }
    void del(double x)
    {
        s.erase(s.find(x));
    }
    double med()
    {
        int n=s.size();
        double a =*next(s.begin(),n/2-1);
        double b =*next(s.begin(),n/2);
        if(n%2==1) return b;
        return (a+b)*0.5;
        
    }
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
      vector<double> v;int n=nums.size();
      //let k=3;nums=[1,3,-1,-3,5,3,6,7]
      //inside set s=> [1,3,-1]
      //med returns median which is appended to v array
      //v[0]=3 ; then first element of set is deleted and the next of the k-1th element is inserted.
      //1,3,-1 => 3,-1 => 3,-1,-3
      //continues so on for others

        for(int i=0;i<k;i++)
        {
            insert(nums[i]);
        }
        for(int i=k,j=0;i<n;i++,j++)
        {
            v.push_back(med());
            del(nums[j]);
            insert(nums[i]);
            
        }
        v.push_back(med());
        return v;
    }
};
