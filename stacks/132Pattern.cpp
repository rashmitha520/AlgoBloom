    bool find132pattern(vector<int>& nums) {
        int incr=INT_MIN;
        
     stack<int> s;
        for(int i=nums.size()-1;i>=0;i--)
        {
            if(nums[i]<incr) return 1;
            while(!s.empty() && nums[i]>s.top())
            {
                incr=s.top();s.pop();
            }
            s.push(nums[i]);
        }
        return 0;
    }
