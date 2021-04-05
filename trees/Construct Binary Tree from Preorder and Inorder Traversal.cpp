     TreeNode* build(vector<int>& pre, vector<int>& in,int s,int e,unordered_map<int,int>& m,int &ind)
    {
        if(s>e) return NULL;
       
        TreeNode* root=new TreeNode(pre[ind]);
        int curI = m[pre[ind++]];
        root->left=build(pre,in,s,curI-1,m,ind);
        root->right = build(pre,in,curI+1,e,m,ind);
        return root;
    }
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        int rooti=0;
        unordered_map<int,int> m;
        int index=0;
        for(int i=0;i<in.size();i++) m[in[i]]=i; 
      TreeNode* root= build(pre,in,rooti,in.size()-1,m,index);
        return root;
    }
