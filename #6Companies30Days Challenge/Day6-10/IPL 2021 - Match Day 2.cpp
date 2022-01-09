    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
       deque<int> q;
       vector<int> v;
        for(int i=0;i<nums.size();i++){
            if(!q.empty() && q.front()==i-k) q.pop_front();
            while(!q.empty() && nums[q.back()]<nums[i]) q.pop_back();
            q.push_back(i);
            if(i>=k-1) v.push_back(nums[q.front()]);
        }
        return v;
    }
