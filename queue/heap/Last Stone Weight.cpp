class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
       priority_queue<int> p;
        for(int i:stones)
        {
            p.push(i);
        }
        while(!p.empty())
        {   
            if(p.size()==1) return p.top();
            else if(p.size()==0) return 0;
            int x=p.top(); p.pop();
            int y=p.top();
            if(x==y) p.pop();
            else
            {
                y=x-y;
                p.pop();
                p.push(y);
            }
            
            
        }
        return 0;
    }
};
