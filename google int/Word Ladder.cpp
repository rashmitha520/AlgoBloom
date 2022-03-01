class Solution {
public:
    int ladderLength(string begin, string end, vector<string>& words) {
       unordered_set<string> list;
       for(auto word:words) list.insert(word);
       set<string> visited;
        int ans=1;
       queue<string> q;
        q.push(begin);
        if(list.find(end)==list.end()) return 0;
        visited.insert(begin);
        while(!q.empty()){
            int n=q.size();
            while(n--){
                string s=q.front();q.pop();
                if(s==end) return ans;
                for(int i=0;i<s.length();i++){
                    char ch=s[i];
                    for(auto c='a';c<='z';c++){
                        s[i]=c;
                        if(visited.find(s)==visited.end() && list.find(s)!=list.end())
                        {
                            q.push(s);visited.insert(s);
                        }
                    }
                    s[i]=ch;
                }
            }
            ans++;
        }
        return 0;
    }
};
