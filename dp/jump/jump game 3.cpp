
class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        if(start<0 || start>=arr.size()||arr[start]<0) return 0; //visited node if visited again is false
        arr[start]*=-1;
        return arr[start]==0||canReach(arr,start+arr[start])||canReach(arr,start-arr[start]);
    }
};
