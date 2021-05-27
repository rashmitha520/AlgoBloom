  TreeNode* create(unordered_map<int,int>& m,int s,int e,int& index,vector<int>& pre, vector<int>& post) 
    {
       if(index>pre.size()||s>e) return NULL;
        
        TreeNode *root=new TreeNode(pre[index++]);
        
        if(s==e) return root;
        
        int rval = pre[index]; 
        int cur = m[rval];
        
        root->left = create(m,s,cur,index,pre,post);
        root->right = create(m,cur+1,e-1,index,pre,post);
        
        return root;
    }
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        int index=0;
        //was getting runtime err due to map
        unordered_map<int,int> m;
        if(pre.size()==1) return new TreeNode(pre[0]);
        for(int i=0;i<post.size();i++) m[post[i]]=i;
        return  create(m,0,post.size()-1,index,pre,post);
       
    }
