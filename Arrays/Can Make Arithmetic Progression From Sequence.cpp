class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
      sort(arr.begin(),arr.end());
        int d= arr[0]-arr[1];  
        for(int i=1;i<arr.size()-1;i++)
        {
            if(arr[i]-arr[i+1]!=d) return 0;
        }
        return 1;
    }
};

//2nd way-without sorting-duplicates ignored
class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        //array into set
        unordered_set<int> uset(arr.begin(),arr.end());
        int max= *max_element(arr.begin(),arr.end());
        int min= *min_element(arr.begin(),arr.end());
        int diff=(max-min)/(arr.size()-1);
        for(int i=1;i<arr.size();i++)
        {
            if(!uset.count(min+diff*i))
                return 0;
        }
       return 1; 
    }
};
