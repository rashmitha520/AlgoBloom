//iterative 
vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> v;
       if(!root) return v;
       
        q.push(root);
        while(!q.empty())
        {
            vector<int> a;
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                TreeNode* cur = q.front();
                q.pop();
                
                a.push_back(cur->val); 
            if(cur->left)
                q.push(cur->left);
            if(cur->right)
                q.push(cur->right);
                
            }
           
           v.push_back(a);
            
                
        }
        return v;
    }
