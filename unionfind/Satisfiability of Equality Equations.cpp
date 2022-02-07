class Solution {
public:
    vector<int> par;
    int find(int x){
        if(par[x]==x) return x;
        return find(par[x]);
    }
    
    bool equationsPossible(vector<string>& equations) {
        par=vector<int>(26,0);
        for(int i=0;i<26;i++){
            par[i]=i;
        }
        int n=equations.size();
        for(int i=0;i<n;i++){
           int a=equations[i][0]-'a';
            int b=equations[i][3]-'a';
            if(equations[i][1]=='=')
            {
                int x=find(a),y=find(b);
                if(x!=y) par[y]=x;
            }
        }
          for(int i=0;i<n;i++){
           int a=equations[i][0]-'a';
            int b=equations[i][3]-'a';
            if(equations[i][1]=='!')
            {
                int x=find(a),y=find(b);
                if(x==y) return 0;
            }
        }
        return 1;
        
    }
};
