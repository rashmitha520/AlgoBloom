class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
    //method -1
    queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {   TreeNode* c=q.front();q.pop();
         
           if(c){
           q.push(c->left);
             q.push(c->right);
               swap(c->left,c->right);}
        }
        return root;
        -----------------------------------------
       //method-2 
        if(!root) return NULL;
        TreeNode* l=invertTree(root->left);
        TreeNode* r=invertTree(root->right);
        root->right=l;
        root->left=r;
        return root;
    }
};
