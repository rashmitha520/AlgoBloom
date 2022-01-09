   //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        // your code here
        deque<int> q;
        vector<int> v;
        for(int i=0;i<n;i++){
            if(!q.empty() && q.front()==i-k) q.pop_front();
            while(!q.empty() && arr[q.back()]<arr[i]) q.pop_back();
            q.push_back(i);
            if(i>=k-1) v.push_back(arr[q.front()]);
        }
        return v;
    }
