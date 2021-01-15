class Solution {
public:
    void flatten(TreeNode* root) {
     if(!root) return;
        //first put left nodes on right;
        // then add right nodes later;
      TreeNode* r=root->right,*n=root;
     root->right=root->left;
        root->left=nullptr;
        while(n->right)
            n=n->right;
        n->right=r;
        flatten(root->right);
    }
};
