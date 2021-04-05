//binary tree
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
      if(p==root || q==root || root==NULL)
          return root;
        TreeNode* p1=lowestCommonAncestor(root->left,p,q);
        TreeNode* p2=lowestCommonAncestor(root->right,p,q);
        if(p1 && p2)
            return root;
        return p1?p1:p2;
    }
//binary tree-iterative
//bst
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
      if(p==root || q==root || root==NULL)
          return root;
        TreeNode* p1=NULL;
        if(p->val<root->val && q->val< root->val)
           return lowestCommonAncestor(root->left,p,q);
        TreeNode* p2=NULL;
        if(p->val>root->val && q->val>root->val)
           return lowestCommonAncestor(root->right,p,q);
       
        return root;
    }
};
//iterative - bst
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
   
        TreeNode* node = root;
        while(node)
        {
            if(p->val<node->val && q->val< node->val)
                node = node->left;
          else if(p->val>node->val && q->val>node->val)
                node = node->right;
            else return node;
        }
        return NULL;
    }
};
