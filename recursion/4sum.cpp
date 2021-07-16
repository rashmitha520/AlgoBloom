    
    vector<vector<int>> tsum(vector<int>& nums, int target,int s)
    { int len=nums.size();
        vector<vector<int>> res;
        int i=s,j=len-1;
        while(i < j) {
                    //find a pair
            	    if(target - nums[i] == nums[j]) {
            	    	vector<int> temp;
                    	temp.push_back(nums[i]);
                    	temp.push_back(target-nums[i]);
                        res.push_back(temp);
                        //skip duplication
                        while(i<j && nums[i]==nums[i+1]) i++;
                        while(i<j && nums[j-1]==nums[j]) j--;
                        i++;
                        j--;
                    //move left bound
            	    } else if (target - nums[i] > nums[j]) {
            	        i++;
                    //move right bound
            	    } else {
            	        j--;
            	    }}
        return res;
    }
    vector<vector<int>> ksum(vector<int>& nums, int target,int k,int start)
    {
        vector<vector<int>> res;
        int len=nums.size();
        if(start==len || nums[start]*k>target||target>nums.back()*k)
            return res;
        if(k==2)
            return tsum(nums,target,start);
        for(int i=start;i<nums.size();i++)
        {
            if(i==start||nums[i-1]!=nums[i])
            {
             //vector<vector<int>> sets=ksum(nums,target-nums[i],k-1,i+1);
             for(auto &t:ksum(nums,target-nums[i],k-1,i+1))
             {
                 res.push_back({nums[i]});
                 res.back().insert(end(res.back()), begin(t), end(t));
             }
            
            }
        }
        return res;
    }
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
       // len = nums.size()-1;
        return ksum(nums,target,4,0);
      
    }
