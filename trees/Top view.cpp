  void topView(Node * root) {
         queue<pair<int,Node*>> q;
         q.push({0,root});
         map<int,int> m;
         while(!q.empty())
         {
             int n=q.size();
             for(int i=0;i<n;i++)
             {
                 auto p = q.front();q.pop();
                 if(!m[p.first]) m[p.first]=p.second->data;
                 if(p.second->left) q.push({p.first-1,p.second->left});
                 if(p.second->right) q.push({p.first+1,p.second->right});
             }
             
         }
          for(auto i:m)
             {
                 cout<<i.second<<" ";
             }

    }
