    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<pair<int,TreeNode*>> q;
        q.push({0,root});
        map<int,vector<int>> hd;
        
        int hor=0;
        while(!q.empty())
        {
            int sz=q.size();
            
            multiset<pair<int,int>> values;
            for(int i=0;i<sz;i++)
           { 
             
            auto pairs = q.front();
            q.pop();
            values.insert({pairs.first,pairs.second->val});
            if(pairs.second->left)
            {   q.push({pairs.first-1,pairs.second->left});
                
            }
            if(pairs.second->right)
            {   q.push({pairs.first+1,pairs.second->right});
                
            }
                
           }
         
         for(auto i=values.begin();i!=values.end();i++)
         {
             hd[i->first].push_back(i->second);
         }
            
        }
        vector<vector<int>> ans;
        for(auto i=hd.begin();i!=hd.end();i++)
        {
            ans.push_back(i->second);
        }
        return ans;
    }
