class Solution {
public:
    void tsutil(int i,stack<int>& s,vector<vector<int>>& graph,vector<int>& v)
    {
        v[i]=1;
        for(auto j:graph[i])
        {
            if(v[j]==0)
              tsutil(j,s,graph,v);
        }
        s.push(i);
    }
    string ts(vector<vector<int>>& graph)
    {  vector<int> v(graph.size(),0);
       stack<int> s;
       string ans="";
       for(int i=0;i<26;i++)
       {
           if(graph[i].size()!=0 && v[i]==0)
             tsutil(i,s,graph,v);
       }
       while(!s.empty())
       {
           ans+=s.top();s.pop();
       }
       return ans;
    }
    string alienOrder(vector<string> &words) {
      vector<vector<int>> graph;
      for(int i=0;i<words.size();i++)
      {
          for(int j=0;j<words[i].length();j++)
          {
              graph[words[i][j]-'a']=vector<int>(0);
          }
      }
      int n=words.size();
      for(int i=0;i<n-1;i++)
      {
          string w1=words[i],w2=words[i+1];
          for(int j=0;j<min(w1.length(),w2.length());j++)
          {
               if(w1[j]!=w2[j])
               {
                   graph[w1[j]-'a'].push_back(w2[j]-'a');
                   break;
               }
          }
      }
      return ts(graph);

    }
};
