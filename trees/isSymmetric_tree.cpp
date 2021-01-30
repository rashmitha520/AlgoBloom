/*Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
*/
Recursive Solution:

class Solution {
public:
    bool h(TreeNode* a,TreeNode* b) {
        if(!a && !b) return true;
        if(!a or !b) return false;
        return (a->val==b->val) && h(a->left,b->right) && h(a->right,b->left);
    }
    bool isSymmetric(TreeNode* root) {
        return h(root,root);
    }
};
Iterative Solution:
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        stack<TreeNode*> s;
        if(!root) return true;
        s.push(root->left);
        s.push(root->right);
        while(!s.empty())
        {  
            TreeNode* t1;t1=s.top();
            s.pop();
           TreeNode* t2;t2=s.top();
            s.pop();
            if((!t1 && t2) || (!t2 && t1)) return false;
            if(t1) 
            { if(t1->val!=t2->val) return false;
            s.push(t1->left);
            s.push(t2->right);
            s.push(t1->right);
            s.push(t2->left);}
            
            
        }
        return true;
    }
};
