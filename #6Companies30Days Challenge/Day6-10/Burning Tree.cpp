class Solution {
  public:
    unordered_map<Node*,Node*> parent;
    Node* tnode=NULL;
    void dfs(Node* root, int target,Node* par){
        if(!root) return;
        if(root->data==target) 
        {
               tnode=root;
        }
        if(par) parent[root]=par;
        dfs(root->left,target,root);
        dfs(root->right,target,root);
    }
    int minTime(Node* root, int target) 
    {
      dfs(root,target,NULL);
      unordered_map<Node*,bool>vis; queue<pair<Node*,int>> q;
      q.push({tnode,0});
      vis[tnode]=1;
      int ans=0;
      while(!q.empty()){
          Node* node = q.front().first;int t=q.front().second;q.pop();
          ans=max(ans,t);
          if(node->right && vis[node->right]==0)
          {
             q.push({node->right,t+1});
             vis[node->right]=1;
          }
          if(node->left && vis[node->left]==0)
          {
             q.push({node->left,t+1});
             vis[node->left]=1;
          }
           if(parent[node] && vis[parent[node]]==0)
          {
             q.push({parent[node],t+1});
             vis[parent[node]]=1;
          }
          
      }
      return ans;
    }
