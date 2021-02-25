class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        stack<int> s,t;
        vector<int> ans;
       for(int i=0;i<a.size();i++)
       {  //add +ve nos to stack
          if(a[i]>0) s.push(a[i]);
           else{
             //if -ve nos are greater then pop the positive elements.
               while(!s.empty() && abs(a[i])>s.top()) s.pop();
             //if equal blast both
               if(!s.empty() && abs(a[i])==s.top())  s.pop();
             //if stack has no +ve nos
               else if(s.empty()) ans.push_back(a[i]);
           }
       }
        if(!s.empty())
        { 
            while(!s.empty())
            {
               t.push(s.top());s.pop(); 
            }
            while(!t.empty())
            {
               ans.push_back(t.top());t.pop(); 
            }
        }
        return ans;
        
    }
};
