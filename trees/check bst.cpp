  //inorder approach
  bool isValidBST(TreeNode* root) {
        TreeNode* prev=nullptr;
    return isValidBST(root, prev);
}
    bool isValidBST(TreeNode* root,TreeNode* &prev)
    {
        if(!root) return true;
         if(!isValidBST(root->left,prev))
            return false;
        if(prev && root->val<=prev->val )
            return false;
       
        prev=root;
        return isValidBST(root->right,prev);
        
    }
    //2nd app
    bool isValidBST(TreeNode* root) {
    return isValidBST(root, NULL, NULL);
}
    bool isValidBST(TreeNode* root, TreeNode* minNode, TreeNode* maxNode) {
    if(!root) return true;
    if(minNode && root->val <= minNode->val || maxNode && root->val >= maxNode->val)
        return false;
    return isValidBST(root->left, minNode, root) && isValidBST(root->right, root, maxNode);
}
//3rd 
void h(TreeNode* root,vector<int> &v)
    {
       if(!root) return;
        
        h(root->left,v);
        v.push_back(root->val);
        h(root->right,v);
        
        
    }
    bool isValidBST(TreeNode* root) {
     vector<int> v;
        h(root,v);
        for(int i=0;i<v.size()-1;i++)
        {
            if(v[i]>=v[i+1])
                return false;
        }
        return true;
}
