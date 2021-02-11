class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> m;
        for(auto i:s) m[i]++;
        priority_queue<pair<int,char>> p;
        for(auto i=m.begin();i!=m.end();i++)
        {
           // pair<char,int> t=i;
            p.push({i->second,i->first});
        }
        s="";
        while(!p.empty())
        {
           pair<int,char> l = p.top();
           
            while( l.first--)
            {
                s+=l.second;
            }
             p.pop();
        }
        return s;
    }
};
