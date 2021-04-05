  TreeNode* build(vector<int>& inorder, vector<int>& postorder,int s,int e,unordered_map<int,int>&pos,int &index)
     {
         if(s>e) return NULL;
         TreeNode* root = new TreeNode(postorder[index]);
         int i = pos[postorder[index]];
         index--;
    // as in postorder - left right root 
         root->right = build(inorder,postorder,i+1,e,pos,index);
         root->left=build(inorder,postorder,s,i-1,pos,index);
        
         return root;
         
     }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
       unordered_map<int,int> pos;
        int index=postorder.size()-1;
        for(int i=0;i<inorder.size();i++)
            pos[inorder[i]]=i;
        return build(inorder,postorder,0,inorder.size()-1,pos,index);
    }
