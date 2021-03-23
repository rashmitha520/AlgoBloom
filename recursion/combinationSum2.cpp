/*
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.

Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]
Example 2:

Input: candidates = [2,5,2,1,2], target = 5
Output: 
[
[1,2,2],
[5]
]
*/

class Solution {
public:
    vector<vector<int>> res;
    vector<int> ans; 
    map<vector<int>,int> mp;
    int sum;
    void back(vector<int>& c, int k,int index)
    {   if(sum>k) return;
        if(sum==k) 
        {
            if(mp[ans]==0)
            {res.push_back(ans);
             mp[ans]++;
            }
            return;
        }
     for(int i=index;i<c.size();i++)
     {
         sum+=c[i];
         
         ans.push_back(c[i]);
         
         back(c,k,i+1);
         sum-=c[i];
         ans.pop_back();
     }
    }
    vector<vector<int>> combinationSum2(vector<int>& c, int k) {
        sum=0;
        sort(c.begin(),c.end());
        back(c,k,0);
        return res;
    }
};
