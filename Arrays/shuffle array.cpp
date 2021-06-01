class Solution {
public:
    vector<int> arr,set;
    Solution(vector<int>& nums) {
        arr=nums;
        set=nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        arr=set;
        return arr;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
       
    for(int i=0;i<arr.size();i++)
      { 
        int k=rand()%(arr.size()-i);//doubt
        swap(arr[i+k],arr[i]);
        
      }
        return arr;
    }
};
